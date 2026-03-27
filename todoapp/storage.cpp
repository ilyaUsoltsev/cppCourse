#include "storage.hpp"
#include <fstream>
#include <sstream>

Storage::Storage(std::string filename)
    : filename_(std::move(filename)) {}

std::vector<Task> Storage::load() const {
    std::vector<Task> tasks;
    std::ifstream file(filename_);

    if (!file.is_open()) {
        return tasks;
    }

    std::string line;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string donePart;
        std::string titlePart;

        if (std::getline(iss, donePart, '|') && std::getline(iss, titlePart)) {
            bool done = (donePart == "1");
            tasks.emplace_back(titlePart, done);
        }
    }

    return tasks;
}

bool Storage::save(const std::vector<Task>& tasks) const {
    std::ofstream file(filename_);

    if (!file.is_open()) {
        return false;
    }

    for (const auto& task : tasks) {
        file << (task.isDone() ? "1" : "0")
             << "|"
             << task.getTitle()
             << "\n";
    }

    return true;
}
