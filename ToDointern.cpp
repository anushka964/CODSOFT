#include<iostream>
#include <vector>
#include <string>
using namespace std;

struct TaskList {
    std::string description;
    bool completed;
    // To extend this structure to include additional task details like due date, priority, etc.
};

void displayMenu() {
    cout << "\n===== To-Do List Manager =====" << endl;
    cout << "1. Add Task\n";
    cout << "2. View Tasks\n";
    cout << "3. Mark Task as Completed\n";
    cout << "4. Remove Task\n";
    cout << "5. Exit\n";
}

void addTask(vector<TaskList> &tasks){
    TaskList newTask;
    cout << "Enter task to add to your To-Do List: ";
    cin.ignore();
    getline(cin, newTask.description);
    newTask.completed = false;
    tasks.push_back(newTask);
    cout << "Congrats! Your task has been added successfully." << endl;
}

void viewTasks(const vector<TaskList>& tasks){
    cout << "\n===== Tasks =====\n";
    for (size_t i = 0; i < tasks.size(); ++i) {
        cout << i + 1 << ". ";
        if (tasks[i].completed) {
            cout << ":) Completed ";
        }
        cout << tasks[i].description << endl;
    }
}

void markCompleted(vector<TaskList>& tasks){
    int num;
    cout << "Enter task number that you have completed: ";
    cin >> num;
    if (num >= 1 && num <= static_cast<int>(tasks.size())) {
        tasks[num - 1].completed = true;
        cout << "Bravo!Task completed. Keep going.\n";
    } else {
        cout << "Invalid task number.\n";
    }
}

void removeTask(vector<TaskList>& tasks){
    if (tasks.empty()) {
        cout << "No tasks to delete.\n";
        return;
    }

    viewTasks(tasks);
    cout << "Enter the task number to remove from the list: ";
    int taskNumber;
    cin >> taskNumber;

    if (taskNumber >= 1 && taskNumber <= static_cast<int>(tasks.size())) {
        tasks.erase(tasks.begin() + taskNumber - 1);
        cout << "Task has been removed successfully!\n";
    } else {
        cout << "Invalid task number.\n";
    }
}

int main(){
    vector<TaskList> tasks;
    string name;
    cout << "Enter your user name: ";
    cin >> name;
    cout << "Welcome " << name << " to your To-Do List Manager!\n";
    cout << "Let's get started...\n";

    int choice;
    do {
        displayMenu();
        cout << "Enter your choice (1-5): ";
        cin >> choice;

        switch (choice) {
            case 1:
                addTask(tasks);
                break;
            case 2:
                viewTasks(tasks);
                break;
            case 3:
                markCompleted(tasks);
                break;
            case 4:
                removeTask(tasks);
                break;
            case 5:
                cout << "Exiting the To-Do List Manager. Goodbye!"<<name<<endl;
                break;
            default:
                cout << "Invalid choice. Please enter a number between 1 and 5.\n";
        }
    } while (choice != 5);

    return 0;
}



