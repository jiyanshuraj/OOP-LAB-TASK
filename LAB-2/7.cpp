#include <iostream>
#include <string>
using namespace std;

struct Product {
    int productID;
    string name;
    int quantity;
    double price;
};

void addProduct(Product*& inventory, int& size, Product newProduct) {
    Product* temp = new Product[size + 1];
    for (int i = 0; i < size; i++) {
        temp[i] = inventory[i];
    }
    temp[size] = newProduct;
    delete[] inventory;
    inventory = temp;
    size++;
}

void removeProduct(Product*& inventory, int& size, int productID) {
    bool found = false;
    Product* temp = new Product[size - 1];
    int j = 0;
    for (int i = 0; i < size; i++) {
        if (inventory[i].productID == productID) {
            found = true;
            continue;
        }
        if (j < size - 1) temp[j++] = inventory[i];
    }
    if (found) {
        delete[] inventory;
        inventory = temp;
        size--;
        cout << "Product removed successfully.\n";
    } else {
        delete[] temp;
        cout << "Product not found.\n";
    }
}

void updateProduct(Product* inventory, int size, int productID) {
    for (int i = 0; i < size; i++) {
        if (inventory[i].productID == productID) {
            cout << "Enter new name: ";
            cin >> inventory[i].name;
            cout << "Enter new quantity: ";
            cin >> inventory[i].quantity;
            cout << "Enter new price: ";
            cin >> inventory[i].price;
            cout << "Product updated successfully.\n";
            return;
        }
    }
    cout << "Product not found.\n";
}

void displayInventory(Product* inventory, int size) {
    double totalValue = 0;
    cout << "Inventory:\n";
    cout << "ID\tName\tQuantity\tPrice\tValue\n";
    for (int i = 0; i < size; i++) {
        double value = inventory[i].quantity * inventory[i].price;
        totalValue += value;
        cout << inventory[i].productID << "\t" << inventory[i].name << "\t"
             << inventory[i].quantity << "\t\t" << inventory[i].price << "\t" << value << "\n";
    }
    cout << "Total Inventory Value: " << totalValue << "\n";
}

int main() {
    Product* inventory = nullptr;
    int size = 0;

    int choice;
    do {
        cout << "\nInventory Management System\n";
        cout << "1. Add Product\n";
        cout << "2. Remove Product\n";
        cout << "3. Update Product\n";
        cout << "4. Display Inventory\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                Product newProduct;
                cout << "Enter Product ID: ";
                cin >> newProduct.productID;
                cout << "Enter Product Name: ";
                cin >> newProduct.name;
                cout << "Enter Quantity: ";
                cin >> newProduct.quantity;
                cout << "Enter Price: ";
                cin >> newProduct.price;
                addProduct(inventory, size, newProduct);
                break;
            }
            case 2: {
                int productID;
                cout << "Enter Product ID to remove: ";
                cin >> productID;
                removeProduct(inventory, size, productID);
                break;
            }
            case 3: {
                int productID;
                cout << "Enter Product ID to update: ";
                cin >> productID;
                updateProduct(inventory, size, productID);
                break;
            }
            case 4:
                displayInventory(inventory, size);
                break;
            case 5:
                cout << "Exiting program...\n";
                break;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 5);

    delete[] inventory;
    return 0;
}
