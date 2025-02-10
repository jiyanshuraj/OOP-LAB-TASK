#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Laptop {
private:
    string brand;
    string model;
    string processor;
    int ram;
    int storage;

public:
    Laptop(string b, string m, string p, int r, int s) : brand(b), model(m), processor(p), ram(r), storage(s) {}

    void turnOn() {
        cout << "Turning On..." << endl;
    }

    void turnOff() {
        cout << "Turning Off..." << endl;
    }

    void runProgram() {
        cout << "Running the program..." << endl;
    }

    void displaySpecs() const {
        cout << "Brand: " << brand << endl;
        cout << "Model: " << model << endl;
        cout << "Processor: " << processor << endl;
        cout << "RAM: " << ram << " GB" << endl;
        cout << "Storage: " << storage << " GB" << endl;
    }

    static void compare(const Laptop& l1, const Laptop& l2) {
        cout << "\nComparing Laptops:\n";

        if (l1.brand == l2.brand) {
            cout << "Brands are the same." << endl;
        } else {
            cout << "Brands are different." << endl;
        }

        if (l1.model == l2.model) {
            cout << "Models are the same." << endl;
        } else {
            cout << "Models are different." << endl;
        }

        if (l1.processor == l2.processor) {
            cout << "Processors are the same." << endl;
        } else {
            cout << "Processors are different." << endl;
        }

        if (l1.ram > l2.ram) {
            cout << l1.brand << "'s RAM is greater than " << l2.brand << "'s." << endl;
        } else if (l1.ram < l2.ram) {
            cout << l2.brand << "'s RAM is greater than " << l1.brand << "'s." << endl;
        } else {
            cout << "RAM is the same." << endl;
        }

        if (l1.storage > l2.storage) {
            cout << l1.brand << "'s Storage is greater than " << l2.brand << "'s." << endl;
        } else if (l1.storage < l2.storage) {
            cout << l2.brand << "'s Storage is greater than " << l1.brand << "'s." << endl;
        } else {
            cout << "Storage is the same." << endl;
        }
    }
};

int main() {
    Laptop Bilal("Dell", "Inspiron 15", "Intel i5", 8, 256);
    Bilal.turnOn();
    Bilal.runProgram();
    Bilal.displaySpecs();
    Bilal.turnOff();

    Laptop Ayesha("Lenovo", "ThinkPad X1", "Intel i7", 16, 512);
    Ayesha.turnOn();
    Ayesha.runProgram();
    Ayesha.displaySpecs();
    Ayesha.turnOff();

    Laptop::compare(Bilal, Ayesha);

    return 0;
}
