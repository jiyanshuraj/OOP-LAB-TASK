#include <string>
#include <iostream>
using namespace std;

class Product {
public:
    int uniqueID;
    string name;
    float price;

    Product() : uniqueID(0), name(" "), price(0.0) {}

    Product(int id, string n, float p) : uniqueID(id), name(n), price(p) {}

    void Display() const {
        cout << "Unique ID: " << uniqueID << endl;
        cout << "Name: " << name << endl;
        cout << "Price: " << price << endl;
    }
};

class Department {
public:
    void sort(Product* p[], int size) {
        Product* temp;
        for (int i = 0; i < size - 1; i++) {
            for (int j = i + 1; j < size; j++) {
                if (p[i]->price > p[j]->price) {
                    temp = p[i];
                    p[i] = p[j];
                    p[j] = temp;
                }
            }
        }
    }

    void Display(Product* p[], int size) {
        for (int i = 0; i < size; i++) {
            p[i]->Display();
            cout << endl;
        }
    }

    void Search(Product* p[], int size, int id) {
        for (int i = 0; i < size; i++) {
            if (p[i]->uniqueID == id) {
                cout << "Product found: " << endl;
                p[i]->Display();
                return;
            }
        }
        cout << "Product with ID " << id << " not found." << endl;
    }
};

int main() {
    Product p1(1234, "GROCERIES", 2500025);
    Product p2(2345, "ELECTRONICS", 24880025);
    Product p3(34567, "CLOTHING", 9887654);

    Product* products[] = { &p1, &p2, &p3 };
    int size = sizeof(products) / sizeof(products[0]);

    Department dp;

    dp.sort(products, size);

    dp.Display(products, size);

    dp.Search(products, size, 2345);

    return 0;
}
