#ifndef TASK_HPP
#define TASK_HPP

#include <string>

class Task {
public:
    Task();
    Task(std::string title, bool done = false);

    const std::string& getTitle() const;
    bool isDone() const;

    void setTitle(const std::string& title);
    void toggleDone();

private:
    std::string title_;
    bool done_;
};

#endif
