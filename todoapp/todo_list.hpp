#ifndef TODO_LIST_HPP
#define TODO_LIST_HPP

#include "task.hpp"
#include <vector>
#include <string>

class TodoList {
public:
    void addTask(const std::string& title);
    bool removeTask(std::size_t index);
    bool toggleTask(std::size_t index);
    void listTasks() const;

    const std::vector<Task>& getTasks() const;
    void setTasks(const std::vector<Task>& tasks);

private:
    std::vector<Task> tasks_;
};

#endif
