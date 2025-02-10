#include <iostream>

using namespace std;

class GroceryStore {
private:
    struct Item {
        char name[100];
        double price;
    };

    Item inventory[100];
    int itemCount = 0;

public:
    void addItem() {
        if (itemCount < 100) {
            cout << "Enter item name: ";
            cin.ignore();
            cin.getline(inventory[itemCount].name, 100);

            cout << "Enter price: ";
            cin >> inventory[itemCount].price;

            itemCount++;
            cout << "Item added successfully!" << endl;
        } else {
            cout << "Inventory is full. Cannot add more items." << endl;
        }
    }

    void updatePrice() {
        char name[100];
        double newPrice;

        cout << "Enter item name to update price: ";
        cin.ignore();
        cin.getline(name, 100);

        for (int i = 0; i < itemCount; i++) {
            if (strcmp(inventory[i].name, name) == 0) {
                cout << "Enter new price: ";
                cin >> newPrice;
                inventory[i].price = newPrice;
                cout << "Price updated successfully!" << endl;
                return;
            }
        }

        cout << "Item not found in inventory." << endl;
    }

    void viewInventory() const {
        if (itemCount == 0) {
            cout << "Inventory is empty." << endl;
            return;
        }

        cout << "\nCurrent Inventory:\n";
        cout << "Item Name             Price\n";
        cout << "--------------------------\n";

        for (int i = 0; i < itemCount; i++) {
            cout << inventory[i].name << "             " << inventory[i].price << endl;
        }
    }

    void generateReceipt() const {
        if (itemCount == 0) {
            cout << "Cannot generate receipt for an empty inventory." << endl;
            return;
        }

        double total = 0;

        cout << "\nReceipt:\n";
        cout << "Item Name             Price\n";
        cout << "--------------------------\n";

        for (int i = 0; i < itemCount; i++) {
            cout << inventory[i].name << "             " << inventory[i].price << endl;
            total += inventory[i].price;
        }

        cout << "--------------------------\n";
        cout << "Total:                 " << total << endl;
    }
};

int main() {
    GroceryStore store;
    int choice;

    do {
        cout << "\nGrocery Store Management System\n";
        cout << "1. Add Item\n";
        cout << "2. Update Price\n";
        cout << "3. View Inventory\n";
        cout << "4. Generate Receipt\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                store.addItem();
                break;
            case 2:
                store.updatePrice();
                break;
            case 3:
                store.viewInventory();
                break;
            case 4:
                store.generateReceipt();
                break;
            case 0:
                cout << "Exiting program. Thank you!\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 0);

    return 0;
}
