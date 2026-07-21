#include <iostream>
#include <memory>
#include <string>

#include "DroneControl.h"
#include "TelemetryParser.h"
#include "mission/MissionProcessor.h"
#include "solvers/AnalyticalSolver.h"

namespace
{
struct Arguments
{
    std::string uart = "/dev/ttyAMA1";
    std::string gpioChip = "gpiochip0";
    unsigned int startLine = 24;
    unsigned int dropLine = 23;
};

bool parseUnsigned(const char* value, unsigned int& result)
{
    try
    {
        result = static_cast<unsigned int>(std::stoul(value));
        return true;
    }
    catch (...)
    {
        return false;
    }
}

bool parseArguments(int argc, char* argv[], Arguments& args)
{
    for (int i = 1; i < argc; ++i)
    {
        const std::string arg = argv[i];

        if (arg == "--uart" && i + 1 < argc)
        {
            args.uart = argv[++i];
        }
        else if (arg == "--gpiochip" && i + 1 < argc)
        {
            args.gpioChip = argv[++i];
        }
        else if (arg == "--start-line" && i + 1 < argc)
        {
            if (!parseUnsigned(argv[++i], args.startLine)) return false;
        }
        else if (arg == "--drop-line" && i + 1 < argc)
        {
            if (!parseUnsigned(argv[++i], args.dropLine)) return false;
        }
        else
        {
            std::cerr << "Unknown or incomplete argument: " << arg << '\n';
            return false;
        }
    }

    return true;
}
} // namespace

int main(int argc, char* argv[])
{
    Arguments args;
    if (!parseArguments(argc, argv, args))
    {
        std::cerr << "Usage: " << argv[0]
                  << " [--uart /dev/ttyAMA1]"
                  << " [--gpiochip gpiochip0]"
                  << " [--start-line 24]"
                  << " [--drop-line 23]\n";
        return 1;
    }

    TelemetryParser parser(args.uart);
    DroneControl control(args.gpioChip, args.startLine, args.dropLine);
    auto solver = std::make_unique<AnalyticalSolver>();

    MissionProcessor mission(parser, control, std::move(solver));
    if (!mission.init())
    {
        std::cerr << "Failed to initialize mission\n";
        return 1;
    }

    mission.run();
    return 0;
}
