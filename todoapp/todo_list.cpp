#include "todo_list.hpp"
#include <iostream>

void TodoList::addTask(const std::string& title) {
    tasks_.emplace_back(title, false);
}

bool TodoList::removeTask(std::size_t index) {
    if (index >= tasks_.size()) {
        return false;
    }

    tasks_.erase(tasks_.begin() + static_cast<long>(index));
    return true;
}

bool TodoList::toggleTask(std::size_t index) {
    if (index >= tasks_.size()) {
        return false;
    }

    tasks_[index].toggleDone();
    return true;
}

void TodoList::listTasks() const {
    if (tasks_.empty()) {
        std::cout << "No tasks yet.\n";
        return;
    }

    for (std::size_t i = 0; i < tasks_.size(); ++i) {
        std::cout << i + 1 << ". "
                  << "[" << (tasks_[i].isDone() ? 'x' : ' ') << "] "
                  << tasks_[i].getTitle() << "\n";
    }
}

const std::vector<Task>& TodoList::getTasks() const {
    return tasks_;
}

void TodoList::setTasks(const std::vector<Task>& tasks) {
    tasks_ = tasks;
}
