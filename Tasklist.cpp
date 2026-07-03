#include <iostream>
#include <vector>
#include <string>

int main() {
    std::vector<std::string> tasks;

    std::cout << "Welcome to Task List Tool!" << std::endl << std::endl;
    std::cout << "Menu Options:" << std::endl;
    std::cout << "1. Add Task" << std::endl;
    std::cout << "2. View Tasks" << std::endl;
    std::cout << "3. Remove Task" << std::endl;
    std::cout << "4. Quit" << std::endl << std::endl;
    std::cout << "Task list system initialized and ready!" << std::endl;

    int choice;
    while (true) {
        std::cout << "Choose an option: ";
        std::cin >> choice;
        std::cin.ignore();

        if (choice == 1) {
            std::string task;
            std::getline(std::cin, task);
            tasks.push_back(task);
            std::cout << "Task \"" << task << "\" added successfully!" << std::endl;
            std::cout << "Total tasks: " << tasks.size() << std::endl;
        }
        else if (choice == 2) {
            if (tasks.empty()) {
                std::cout << "No tasks available." << std::endl;
            } else {
                std::cout << "Your Tasks:" << std::endl;
                for (int i = 0; i < tasks.size(); i++) {
                    std::cout << (i + 1) << ". " << tasks[i] << std::endl;
                }
                std::cout << "Total tasks: " << tasks.size() << std::endl;
            }
        }
        else if (choice == 3) {
            int taskNum;
            std::cin >> taskNum;
            if (taskNum >= 1 && taskNum <= tasks.size()) {
                std::string removedTask = tasks[taskNum - 1];
                tasks.erase(tasks.begin() + taskNum - 1);
                std::cout << "Task \"" << removedTask << "\" removed successfully!" << std::endl;

                if (tasks.empty()) {
                    std::cout << "No tasks remaining." << std::endl;
                } else {
                    std::cout << "Remaining Tasks:" << std::endl;
                    for (int i = 0; i < tasks.size(); i++) {
                        std::cout << (i + 1) << ". " << tasks[i] << std::endl;
                    }
                }
                std::cout << "Total tasks: " << tasks.size() << std::endl;
            } else {
                std::cout << "Error: Invalid task number. Please enter a number between 1 and " << tasks.size() << "." << std::endl;
            }
        }
        else if (choice == 4) {
            std::cout << "Thank you for using Task List Tool!" << std::endl;
            break;
        }
        else {
            std::cout << "Invalid choice. Please try again." << std::endl;
        }
    }

    return 0;
}
