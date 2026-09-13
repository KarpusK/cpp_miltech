#include <iostream>
#include <fstream>
#include <string>
#include "httplib.h"

std::string readFile(const std::string& filename) {
    std::ifstream file(filename);
    std::string content((std::istreambuf_iterator<char>(file)),
                        std::istreambuf_iterator<char>());
    return content;
}

int main() {
    httplib::Client cli("http://cppmiltech.com.ua");
    cli.set_connection_timeout(2);
    cli.set_read_timeout(2);
    // Створюємо заголовки
    httplib::Headers headers = {
    { "X-API-Key", "dz12-vX7mK4qT9r2w" }
    };

    // Треба просто передати файл як є
    std::string json = readFile("simulation.json");

    // Формуємо повний JSON
    std::string body =
        R"({
            "studentId": "1072",
            "testId": "T03",
            "simulation": )"
        + json +
        R"(
        })";

    // POST
    auto res = cli.Post(
        "/api/dz12/results",
        headers,
        body,
        "application/json"
    );

    if (res) {
        std::cout << "HTTP status: " << res->status << "\n";
        std::cout << "Server response:\n" << res->body << "\n";
    } else {
        std::cout << "POST failed\n";
        std::cout << "Error: " << httplib::to_string(res.error()) << "\n";
    }
    
    // Передаємо заголовки другим аргументом у Get
    if (auto res = cli.Get("/api/dz12/results/T03/1072", headers)) {
        std::cout << res->body << std::endl;
    }

    return 0;

}