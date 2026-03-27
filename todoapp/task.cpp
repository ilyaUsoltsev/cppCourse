#include "task.hpp"

Task::Task() : title_(""), done_(false) {}

Task::Task(std::string title, bool done)
    : title_(std::move(title)), done_(done) {}

const std::string& Task::getTitle() const {
    return title_;
}

bool Task::isDone() const {
    return done_;
}

void Task::setTitle(const std::string& title) {
    title_ = title;
}

void Task::toggleDone() {
    done_ = !done_;
}
