#include <fcntl.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <linux/i2c-dev.h>
#include <cstdint>
#include <iostream>

//LD_PRELOAD=./sim/libi2csim.so ./build/i2c_dev 

//LD_PRELOAD=./sim/libi2csim-arm64.so ./build/i2c_dev 

int main()
{
    int fd = open("/dev/i2c-1", O_RDWR);

    if (fd < 0) {
        std::cerr << "Cannot open I2C\n";
        return 1;
    }

    constexpr uint8_t address = 0x48;

    if (ioctl(fd, I2C_SLAVE, address) < 0) {
        std::cerr << "Cannot select slave\n";
        close(fd);
        return 1;
    }

    // Pointer register -> conversion register 0x00
    uint8_t pointer = 0x00;

    if (write(fd, &pointer, 1) != 1) {
        std::cerr << "Write failed\n";
        close(fd);
        return 1;
    }



    while(1) {
        uint8_t buf[2];

        if (read(fd, buf, 2) != 2) {
            std::cerr << "Read failed\n";
            close(fd);
            return 1;
        }
        int16_t value =
            static_cast<int16_t>(
                (static_cast<uint16_t>(buf[0]) << 8) |
                buf[1]
            );  
        std::cout << "ADC raw: " << value << '\n';
        std::cout << "ADC voltage: " << (value * 3.3 / 4096) << " V\n";
        sleep(1);
    }

    close(fd);
}