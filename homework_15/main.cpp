#include <httplib.h>
#include <iostream>

int main() {
    httplib::Client cli("http://cppmiltech.com.ua");
    cli.set_connection_timeout(2);
    cli.set_read_timeout(2);
    // Створюємо заголовки
    httplib::Headers headers = {
    { "X-API-Key", "dz12-vX7mK4qT9r2w" }
    };

    auto res = cli.Post(
        "/api/dz12/results",
        headers,
        R"({
            "studentId": "6666",
            "testId": "T03",
            "simulation": {
                // Вміст файлу simulation.json
            }
        })",
        "application/json"
    );

    // Передаємо заголовки другим аргументом у Get
    if (auto res = cli.Get("/api/dz12/results/T03/1042", headers)) {
        std::cout << res->body << std::endl;
    }

    return 0;

}