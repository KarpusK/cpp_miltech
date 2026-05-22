#define _USE_MATH_DEFINES
#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>

float x = 0;
float y = 0;
float theta = 0;

float pi = M_PI;

int ticks_per_revolution = 1024;
float wheel_radius_m = 0.3;
float wheelbase_m = 1.0;

int steps = 0;

struct Row {
    long timestamp_ms;
    long fl_ticks;
    long fr_ticks;
    long bl_ticks;
    long br_ticks;
};

std::vector<Row> data;

Row row;

float d_fl;
float d_fr;
float d_bl;
float d_br;

float dL;
float dR;

float d;
float dtheta;
float distance_per_tick;

float d_left = 0;
float d_right = 0;

void DeltaFinding(int i, std::vector<Row>& data, float& d_left, float& d_right) {

        d_fl = data[i].fl_ticks - data[i-1].fl_ticks;
        d_fr = data[i].fr_ticks - data[i-1].fr_ticks;
        d_bl = data[i].bl_ticks - data[i-1].bl_ticks;
        d_br = data[i].br_ticks - data[i-1].br_ticks;

        d_left  += (d_fl + d_bl) / 2;
        d_right += (d_fr + d_br) / 2;
}

void ConvertionTicksToMetres(float& d_left, float& d_right, float& wheel_radius_m, int& ticks_per_revolution, float& pi, float& distance_per_tick) {
    distance_per_tick = 2 * pi * wheel_radius_m / ticks_per_revolution;

    dL = d_left  * distance_per_tick;
    dR = d_right * distance_per_tick;
}

void DistAndAngleCalculation(float& dL, float& dR, float& wheelbase_m, float& d, float& dtheta) {
    d = (dL + dR) / 2;              // пройдена вiдстань центру
    dtheta = (dR - dL) / wheelbase_m;    // змiна орiєнтацiї
}

void PositionUpdate(float& d, float& dtheta, float& x, float& y) {
    x += d * cos(theta + dtheta / 2);
    y += d * sin(theta + dtheta / 2);
    theta += dtheta;
}


int main(int argc, char** argv) {
    
    if (argc != 2) {
        std::cerr << "usage: ugv_odometry <input_path>\n";
        return 1;
    }

    std::ifstream file(argv[1]);

    if (!file.is_open()) {
        std::cerr << "Failed to open file\n";
        return 1;
    }

    std::cout << "Starting reading file...\n";


    while (file >> row.timestamp_ms
                >> row.fl_ticks
                >> row.fr_ticks
                >> row.bl_ticks
                >> row.br_ticks) 
    {
        data.push_back(row);
        steps++;
    }

    for(int i = 1; i < steps; i++) {

        DeltaFinding(i, data, d_left, d_right);
        ConvertionTicksToMetres(d_left, d_right, wheel_radius_m, ticks_per_revolution, pi, distance_per_tick);
        DistAndAngleCalculation(dL, dR, wheelbase_m, d, dtheta);
        PositionUpdate(d, dtheta, x, y);

        std::cout << "Time: " << data[i].timestamp_ms << "  " << "X = " << x << "  " << "Y = " << y << "  " << "Theta = " << theta << std::endl;
    }

    file.close();

    return 0;

}





























    // TODO: implement wheel odometry for a 4-wheel differential-drive UGV.
    //
    // Model parameters:
    //   ticks_per_revolution = 1024
    //   wheel_radius_m       = 0.3
    //   wheelbase_m          = 1.0
    //
    // Input: a text file with 5 whitespace-separated values per line:
    //         timestamp_ms fl_ticks fr_ticks bl_ticks br_ticks
    // Output: a table on stdout, starting from the second sample:
    //         timestamp_ms x y theta
