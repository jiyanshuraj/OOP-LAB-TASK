#include<iostream>
#include<string>
using namespace std;

class planner {
private:
    string task[12][30]; // 12 months, 30 days each
public:
    void addTask() {
        int day, month;
        cout << "Enter month (1-12): ";
        cin >> month;
        cout << "Enter day (1-30): ";
        cin >> day;
        if (day >= 1 && day <= 30 && month >= 1 && month <= 12) {
            cout << "Enter task: ";
            cin >> task[month - 1][day - 1];
            cout << "Task added" << endl;
        } else {
            cout << "Invalid day/month" << endl;
        }
    }

    void removeTask() {
        string searchTask;
        cout << "Enter task to remove: ";
        cin >> searchTask;
        for (int i = 0; i < 12; i++) {
            for (int j = 0; j < 30; j++) {
                if (task[i][j] == searchTask) {
                    task[i][j] = "-";
                    cout << "Task Removed" << endl;
                    return; // Exit after removing the task
                }
            }
        }
        cout << "Task not found" << endl;
    }

    void display() {
        for (int i = 0; i < 12; i++) {
            for (int j = 0; j < 30; j++) {
                if (task[i][j] != "-") {
                    cout << "Month " << i + 1 << ", Day " << j + 1 << ": " << task[i][j] << endl;
                }
            }
        }
    }

    void updateTask() {
        int day, month;
        cout << "Enter month (1-12): ";
        cin >> month;
        cout << "Enter day (1-30): ";
        cin >> day;
        if (day >= 1 && day <= 30 && month >= 1 && month <= 12) {
            string utask;
            cout << "Enter new task: ";
            cin >> utask;
            task[month - 1][day - 1] = utask;
            cout << "Task updated" << endl;
        } else {
            cout << "Invalid day/month" << endl;
        }
    }
};

int main() {
    planner p;
    int choice;
    do {
        cout << "1. Add Task" << endl;
        cout << "2. Remove Task" << endl;
        cout << "3. Update Task" << endl;
        cout << "4. Display Tasks" << endl;
        cout << "5. Exit the program" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                p.addTask();
                break;
            case 2:
                p.removeTask();
                break;
            case 3:
                p.updateTask();
                break;
            case 4:
                p.display();
                break;
            case 5:
                cout << "Exiting...." << endl;
                break;
            default:
                cout << "Invalid input" << endl;
        }
    } while (choice != 5);

    return 0;
}
