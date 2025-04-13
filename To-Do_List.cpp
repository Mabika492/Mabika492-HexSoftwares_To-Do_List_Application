#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Task {
    string description;
    bool completed;
};

void displayMenu() {
    cout << "\n--- To-Do List Menu ---\n";
    cout << "1. Mark Task as Completed\n";
    cout << "2. View Tasks\n";
    cout << "3. Exit\n";
    cout << "Choose an option: ";
}

void markCompleted(vector<Task>& tasks) {
    if (tasks.empty()) {
        cout << "No tasks available to mark as completed.\n";
        return;
    }
    int taskNum;
    cout << "Enter task number to mark as completed: ";
    cin >> taskNum;
    if (taskNum > 0 && taskNum <= tasks.size()) {
        tasks[taskNum - 1].completed = true;
        cout << "Task marked as completed.\n";
    } else {
        cout << "Invalid task number.\n";
    }
}

void viewTasks(const vector<Task>& tasks) {
    cout << "\nYour Tasks:\n";
    if (tasks.empty()) {
        cout << "No tasks available.\n";
    }
    for (size_t i = 0; i < tasks.size(); ++i) {
        cout << i + 1 << ". [" << (tasks[i].completed ? "X" : " ") << "] " << tasks[i].description << "\n";
    }
}

int main() {
    vector<Task> tasks;
    string taskInput;
    int taskCount;

    cout << "How many tasks would you like to add? ";
    cin >> taskCount;
    cin.ignore(); // flush newline

    for (int i = 0; i < taskCount; ++i) {
        Task task;
        cout << "Add task " << i + 1 << ": ";
        getline(cin, task.description);
        task.completed = false;
        tasks.push_back(task);
    }

    int choice;

    do {
        displayMenu();
        cin >> choice;

        switch (choice) {
            case 1: markCompleted(tasks); break;
            case 2: viewTasks(tasks); break;
            case 3: cout << "Goodbye!\n"; break;
            default: cout << "Invalid option. Try again.\n";
        }

    } while (choice != 3);

    return 0;
}