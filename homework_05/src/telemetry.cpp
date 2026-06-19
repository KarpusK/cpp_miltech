#include "telemetry.hpp"

#include <cstdlib>
#include <fstream>
#include <iostream>

// Debugging exercise notes:
// this file intentionally contains four runtime defects.
// The defects are related to malformed input shape, invalid numeric values,
// unsafe time deltas, and empty logs. Exact locations are not marked on purpose.

const int EXPECTED_FIELD_COUNT = 7;
const int MAX_LINE_LENGTH = 256;

int main(int argc, char** argv) {
    // The executable expects exactly one telemetry log path.
    if (argc != 2) {
        std::cerr << "usage: telemetry_check <input_path>\n";
        return 1;
    }

    Frame frames[MAX_TELEMETRY_FRAMES];
    const int frame_count = read_frames(argv[1], frames, MAX_TELEMETRY_FRAMES);

    if (frame_count <= 0) {
        std::cerr << "Error: Frames count is invalid." << std::endl;
        return 1;
    };

    const Summary summary = summarize(frames, frame_count);

    print_summary(summary);

    return 0;
}


// int split_line(char line[], char* fields[], int max_fields) {
//     int count = 0;
//     char* cursor = line;

//     while (*cursor != '\0' && count < max_fields) {
//         while (*cursor == ' ' || *cursor == '\t' || *cursor == '\n' || *cursor == '\r') {
//             *cursor = '\0';
//             ++cursor;
//         }

//         if (*cursor == '\0') {
//             break;
//         }

//         fields[count] = cursor;

//         // перевірка: чи це число
//         char* endptr;
//         strtod(cursor, &endptr);

//         if (*endptr == '\0' ||
//             *endptr == ' ' ||
//             *endptr == '\t' ||
//             *endptr == '\n' ||
//             *endptr == '\r')
//         {
//             ++count; 
//         };


//         while (*cursor != '\0' && *cursor != ' ' && *cursor != '\t' && *cursor != '\n' &&
//                *cursor != '\r') {
//             ++cursor;
//         }
//     }

//     return count;
// }

int split_line(char line[], char* fields[], int max_fields) {
    int count = 0;
    char* cursor = line;

    while (*cursor != '\0' && count < max_fields) {
        while (*cursor == ' ' || *cursor == '\t' || *cursor == '\n' || *cursor == '\r') {
            *cursor = '\0';
            ++cursor;
        }

        if (*cursor == '\0') {
            break;
        }

        fields[count] = cursor;
        ++count;

        while (*cursor != '\0' &&
               *cursor != ' ' &&
               *cursor != '\t' &&
               *cursor != '\n' &&
               *cursor != '\r') {
            ++cursor;
        }
    }

    return count;
}

// long parse_long(const char* text, int field) {

//     if (text == nullptr) {
//         std::cerr << "Error: Field " << field << " is not a number." << std::endl;
//         return 0;
//     };

//     char* end = nullptr;
//     long value = 0;
//     while (*text != '\0') {
//         value = std::strtol(text, &end, 10);

//         if (end != text) {
//             // знайшли число
//             text = end;
//         } else {
//         // не число — пропускаємо символ
//             ++text;
//         };
//     };
//     return value;
// }

long parse_long(const char* text, int field_number, int frame_count) {
    if (text == nullptr) {
        std::cerr << "Error: field " << field_number << " at line " << frame_count + 1 << " is empty.\n";
        std::exit(1);
    }

    char* end = nullptr;
    long value = std::strtol(text, &end, 10);

    if (end == text || *end != '\0') {
        std::cerr << "Error: field " << field_number << " at line " << frame_count + 1 << " is not a number: " << text << '\n';
        std::exit(1);
    }

    return value;
}

int parse_int(const char* text, int field, int frame_count) {
    return static_cast<int>(parse_long(text, field, frame_count));
}

// double parse_double(const char* text, int field) {

//     if (text == nullptr) {
//         std::cerr << "Error: Field " << field << " is not a number." << std::endl;
//         return 0;
//     };

//     char* end = nullptr;
//     double value = 0;

//     while (*text != '\0') {
//         value = std::strtod(text, &end);

//         if (end != text) {
//             // знайшли число
//             text = end;
//         } else {
//         // не число — пропускаємо символ
//             ++text;
//         };
//     };

//     return value;
// }

double parse_double(const char* text, int field_number, int frame_count) {
    if (text == nullptr) {
        std::cerr << "Error: field " << field_number << " at line " << frame_count + 1 << " is empty.\n";
        std::exit(1);
    }

    char* end = nullptr;
    double value = std::strtod(text, &end);

    if (end == text || *end != '\0') {
        std::cerr << "Error: field " << field_number << " at line " << frame_count + 1 << " is not a number: " << text << '\n';
        std::exit(1);
    }

    return value;
}

Frame parse_frame(char line[], int frame_count) {
    char* fields[EXPECTED_FIELD_COUNT] = {};
    const int field_count = split_line(line, fields, EXPECTED_FIELD_COUNT);
    (void)field_count;

    if (field_count < EXPECTED_FIELD_COUNT) {
        std::cerr << "Error: invalid frame at line " << frame_count + 1 << ": expected 7 fields." << std::endl;
    };

    Frame frame{};

    frame.timestamp_ms = parse_long(fields[0], 1, frame_count);

    frame.seq = parse_int(fields[1], 2, frame_count);

    frame.voltage_v = parse_double(fields[2], 3, frame_count);

    frame.current_a = parse_double(fields[3], 4, frame_count);

    frame.temperature_c = parse_double(fields[4], 5, frame_count);

    frame.gps_fix = parse_int(fields[5], 6, frame_count);

    frame.satellites = parse_int(fields[6], 7, frame_count);

    if (field_count > 7) {
        std::cout << "Too much fields." << std::endl;
    };
    return frame;
}

double compute_frame_rate_hz(const Frame frames[], int frame_count) {
    const long elapsed_ms = frames[frame_count - 1].timestamp_ms - frames[0].timestamp_ms;

    if (elapsed_ms <= 0) 
    {
        std::cerr << "Error. Frame rate is 0." << std::endl;
        exit(1);
    } else {
        return static_cast<double>((frame_count - 1) * 1000 / elapsed_ms);
    };
}

int read_frames(const char* path, Frame frames[], int max_frames) {
    std::ifstream input{path};
    if (!input) {
        std::cerr << "error: failed to open input file: " << path << '\n';
        return 0;
    }

    int frame_count = 0;
    char line[MAX_LINE_LENGTH];

    while (input.getline(line, MAX_LINE_LENGTH)) {
        if (line[0] == '\0') {
            continue;
        }

        if (frame_count < max_frames) {
            frames[frame_count] = parse_frame(line, frame_count);
            ++frame_count;
        }
    }

    return frame_count;
}

Summary summarize(const Frame frames[], int frame_count) {
    Summary summary{};
    summary.frames_total = frame_count;
    summary.frames_valid = frame_count;
    summary.voltage_min = frames[0].voltage_v;
    summary.voltage_max = frames[0].voltage_v;
    summary.low_voltage_frames = 0;

    double temperature_sum = 0.0;

    for (int i = 0; i < frame_count; ++i) {
        if (frames[i].voltage_v < summary.voltage_min) {
            summary.voltage_min = frames[i].voltage_v;
        }

        if (frames[i].voltage_v > summary.voltage_max) {
            summary.voltage_max = frames[i].voltage_v;
        }

        temperature_sum += frames[i].temperature_c;

        if (frames[i].voltage_v < 22.0) {
            ++summary.low_voltage_frames;
        }
    }

    const int temperature_tenths = static_cast<int>(temperature_sum * 10.0) / frame_count;
    summary.temperature_avg = static_cast<double>(temperature_tenths) / 10.0;
    summary.frame_rate_hz = compute_frame_rate_hz(frames, frame_count);
    return summary;

}

void print_summary(const Summary& summary) {
    std::cout << "frames_total " << summary.frames_total << '\n';
    std::cout << "frames_valid " << summary.frames_valid << '\n';
    std::cout << "voltage_min " << summary.voltage_min << '\n';
    std::cout << "voltage_max " << summary.voltage_max << '\n';
    std::cout << "temperature_avg " << summary.temperature_avg << '\n';
    std::cout << "low_voltage_frames " << summary.low_voltage_frames << '\n';
    std::cout << "frame_rate_hz " << summary.frame_rate_hz << '\n';
}
