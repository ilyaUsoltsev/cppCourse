#ifndef STORAGE_HPP
#define STORAGE_HPP

#include "task.hpp"
#include <string>
#include <vector>

class Storage {
public:
    explicit Storage(std::string filename);

    std::vector<Task> load() const;
    bool save(const std::vector<Task>& tasks) const;

private:
    std::string filename_;
};

#endif
