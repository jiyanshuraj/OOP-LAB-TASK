#include <iostream>
#include <string>

using namespace std;

class TeaMug {
private:
    const string brand;
    const string color;
    const double capacity;
    double currentFillLevel;

public:
    TeaMug(string b, string col, double cap) : brand(b), color(col), capacity(cap), currentFillLevel(0) {}

    void sipTea(double sip) {
        if (sip <= 0) {
            throw invalid_argument("Sip amount must be positive.");
        }
        if (sip > capacity) {
            throw invalid_argument("Cannot sip more than the mug's capacity.");
        }
        if (sip > currentFillLevel) {
            throw runtime_error("Not enough tea to sip.");
        }
        currentFillLevel -= sip;
        cout << "Sipped " << sip << " ml. Current fill level: " << currentFillLevel << " ml" << endl;
        checkIfEmpty();
    }

    void refill() {
        currentFillLevel = capacity;
        cout << "Mug refilled." << endl;
    }

    void checkStatus() const {
        cout << "Brand: " << brand << endl;
        cout << "Color: " << color << endl;
        cout << "Capacity: " << capacity << " ml" << endl;
        cout << "Current fill level: " << currentFillLevel << " ml" << endl;
    }

private:
    void checkIfEmpty() const {
        if (currentFillLevel == 0) {
            cout << "Time for a fresh cup!" << endl;
        }
    }
};

int main() {
    try {
        TeaMug myMug("Tapal Danedar", "Brown", 250.0);

        myMug.refill();
        myMug.sipTea(50);
        myMug.sipTea(100);
        myMug.sipTea(100);
        myMug.sipTea(10); 

        myMug.checkStatus();
    } catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
    }

    return 0;
}
