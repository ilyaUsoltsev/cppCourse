#include "todo_list.hpp"
#include "storage.hpp"

#include <iostream>
#include <limits>
#include <string>

void printMenu() {
    std::cout << "\n=== Todo CLI App ===\n";
    std::cout << "1. Show tasks\n";
    std::cout << "2. Add task\n";
    std::cout << "3. Toggle task\n";
    std::cout << "4. Remove task\n";
    std::cout << "5. Save and exit\n";
    std::cout << "Choose: ";
}

void clearInput() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int main() {
    TodoList todoList;
    Storage storage("tasks.txt");

    todoList.setTasks(storage.load());

    int choice = 0;

    while (true) {
        printMenu();

        if (!(std::cin >> choice)) {
            clearInput();
            std::cout << "Invalid input.\n";
            continue;
        }

        clearInput();

        if (choice == 1) {
            todoList.listTasks();
        } else if (choice == 2) {
            std::string title;
            std::cout << "Enter task title: ";
            std::getline(std::cin, title);

            if (title.empty()) {
                std::cout << "Task title cannot be empty.\n";
                continue;
            }

            todoList.addTask(title);
            std::cout << "Task added.\n";
        } else if (choice == 3) {
            std::size_t index;
            std::cout << "Enter task number to toggle: ";

            if (!(std::cin >> index)) {
                clearInput();
                std::cout << "Invalid number.\n";
                continue;
            }

            clearInput();

            if (index == 0 || !todoList.toggleTask(index - 1)) {
                std::cout << "Task not found.\n";
            } else {
                std::cout << "Task updated.\n";
            }
        } else if (choice == 4) {
            std::size_t index;
            std::cout << "Enter task number to remove: ";

            if (!(std::cin >> index)) {
                clearInput();
                std::cout << "Invalid number.\n";
                continue;
            }

            clearInput();

            if (index == 0 || !todoList.removeTask(index - 1)) {
                std::cout << "Task not found.\n";
            } else {
                std::cout << "Task removed.\n";
            }
        } else if (choice == 5) {
            if (storage.save(todoList.getTasks())) {
                std::cout << "Tasks saved. Bye!\n";
            } else {
                std::cout << "Failed to save tasks.\n";
            }
            break;
        } else {
            std::cout << "Unknown option.\n";
        }
    }

    return 0;
}
