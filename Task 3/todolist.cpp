#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Task {
    string description;
    bool completed;

    Task(string desc) {
        description = desc;
        completed = false;
    }
};

void addTask(vector<Task> &tasks) {
    string desc;
    cin.ignore(); // Clear input buffer
    cout << "Enter task description: ";
    getline(cin, desc);
    tasks.push_back(Task(desc));
    cout << "Task added successfully!\n";
}

void viewTasks(const vector<Task> &tasks) {
    if (tasks.empty()) {
        cout << "No tasks available.\n";
        return;
    }
    cout << "\nTo-Do List:\n";
    for (size_t i = 0; i < tasks.size(); i++) {
        cout << i + 1 << ". " << tasks[i].description
             << " [" << (tasks[i].completed ? "Completed" : "Pending") << "]\n";
    }
}

void markCompleted(vector<Task> &tasks) {
    int index;
    cout << "Enter task number to mark as completed: ";
    cin >> index;
    if (index < 1 || index > (int)tasks.size()) {
        cout << "Invalid task number!\n";
        return;
    }
    tasks[index - 1].completed = true;
    cout << "Task marked as completed!\n";
}

void removeTask(vector<Task> &tasks) {
    int index;
    cout << "Enter task number to remove: ";
    cin >> index;
    if (index < 1 || index > (int)tasks.size()) {
        cout << "Invalid task number!\n";
        return;
    }
    tasks.erase(tasks.begin() + index - 1);
    cout << "Task removed successfully!\n";
}

int main() {
    vector<Task> tasks;
    int choice;

    do {
        cout << "\n--- To-Do List Menu ---\n";
        cout << "1. Add Task\n";
        cout << "2. View Tasks\n";
        cout << "3. Mark Task as Completed\n";
        cout << "4. Remove Task\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: addTask(tasks); break;
            case 2: viewTasks(tasks); break;
            case 3: markCompleted(tasks); break;
            case 4: removeTask(tasks); break;
            case 5: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 5);

    return 0;
}
