
// Online C++ Compiler - Build, Compile and Run your C++ programs online in your favorite browser

#include<iostream>

#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Task {
    string description;
    bool isCompleted;
};

void addTask(vector<Task>& tasks) {
    string desc;
    cout << "Enter task description: ";
    cin.ignore();
    getline(cin, desc);
    tasks.push_back({desc, false});
    cout << "Task added successfully.\n";
}

void markCompleted(vector<Task>& tasks) {
    int index;
    cout << "Enter task number to mark as completed: ";
    cin >> index;
    if (index > 0 && index <= tasks.size()) {
        tasks[index - 1].isCompleted = true;
        cout << "Task marked as completed.\n";
    } else {
        cout << "Invalid task number.\n";
    }
}

void viewTasks(const vector<Task>& tasks) {
    cout << "\nYour Tasks:\n";
    for (size_t i = 0; i < tasks.size(); ++i) {
        cout << i + 1 << ". [" << (tasks[i].isCompleted ? "X" : " ") << "] " << tasks[i].description << "\n";
    }
    cout << endl;
}

int main() {
    vector<Task> tasks;
    int choice;

    do {
        cout << "\n--- To-Do List Menu ---\n";
        cout << "1. Add Task\n2. Mark Task as Completed\n3. View Tasks\n4. Exit\n";
        cout << "Choose an option: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addTask(tasks);
                break;
            case 2:
                markCompleted(tasks);
                break;
            case 3:
                viewTasks(tasks);
                break;
            case 4:
                cout << "Exiting To-Do List App. Goodbye!\n";
                break;
            default:
                cout << "Invalid option. Try again.\n";
        }
    } while (choice != 4);

    return 0;
}