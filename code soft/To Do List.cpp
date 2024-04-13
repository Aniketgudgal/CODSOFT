#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Structure to represent a to-do item
struct ToDoItem {
  string description;
  bool isCompleted;
};

vector<ToDoItem> todoList;

// Function to display the to-do list
void displayTodoList() {
  if (todoList.empty()) {
    cout << "There are no tasks in the list." << endl;
    return;
  }

  cout << "To-Do List:" << endl;
  for (int i = 0; i < todoList.size(); i++) {
    cout << i + 1 << ". " << todoList[i].description << (todoList[i].isCompleted ? " (Completed)" : "") << endl;
  }
}

// Function to add a new to-do item
void addTask() {
  string description;
  cout << "Enter a new task: ";
  getline(cin, description); // Get entire line including spaces
  todoList.push_back({description, false});
  cout << "Task added successfully!" << endl;
}

// Function to mark a task as completed
void markCompleted() {
  int itemNumber;
  if (todoList.empty()) {
    cout << "There are no tasks to mark as completed." << endl;
    return;
  }

  cout << "Enter the number of the task to mark as completed: ";
  cin >> itemNumber;

  if (itemNumber < 1 || itemNumber > todoList.size()) {
    cout << "Invalid task number." << endl;
    return;
  }

  todoList[itemNumber - 1].isCompleted = true;
  cout << "Task marked as completed." << endl;
}

// Function to delete a task
void deleteTask() {
  int itemNumber;
  if (todoList.empty()) {
    cout << "There are no tasks to delete." << endl;
    return;
  }

  cout << "Enter the number of the task to delete: ";
  cin >> itemNumber;

  if (itemNumber < 1 || itemNumber > todoList.size()) {
    cout << "Invalid task number." << endl;
    return;
  }

  todoList.erase(todoList.begin() + itemNumber - 1);
  cout << "Task deleted successfully." << endl;
}

int main() {
  int choice;

  while (true) {
    cout << endl;
    cout << "To-Do List Menu:" << endl;
    cout << "1. Display List" << endl;
    cout << "2. Add Task" << endl;
    cout << "3. Mark Task Completed" << endl;
    cout << "4. Delete Task" << endl;
    cout << "5. Exit" << endl;
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice) {
      case 1:
        displayTodoList();
        break;
      case 2:
        addTask();
        break;
      case 3:
        markCompleted();
        break;
      case 4:
        deleteTask();
        break;
      case 5:
        cout << "Exiting the To-Do List application." << endl;
        break;
        return 0;
      default:
        cout << "Invalid choice. Please try again." << endl;
    }

    cin.ignore(); // Clear input buffer before next loop iteration
  }

  return 0;
}
