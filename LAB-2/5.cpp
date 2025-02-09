#include <iostream>
#include <string>
using namespace std;

struct Book {
    int BookID;
    string title;
    string Author;
    bool isAvailable;
};

Book* AllocateMemory(int size) {
    return new Book[size];
}

Book* ResizeArray(Book* books, int& size) {
    Book* newBooks = new Book[size + 1];
    for (int i = 0; i < size; i++) {
        newBooks[i] = books[i];
    }
    delete[] books;
    size++;
    return newBooks;
}

void addBook(Book*& books, int& size) {
    books = ResizeArray(books, size);

    cout << "Book ID: ";
    cin >> books[size - 1].BookID;
    cin.ignore();

    cout << "Book Title: ";
    getline(cin, books[size - 1].title);

    cout << "Author: ";
    getline(cin, books[size - 1].Author);

    books[size - 1].isAvailable = true;
    cout << "Book added successfully!\n";
}

void RemoveBook(Book*& books, int& size) {
    if (size == 0) {
        cout << "No books available to remove.\n";
        return;
    }

    int bid;
    cout << "Enter Book ID to Remove: ";
    cin >> bid;

    int index = -1;
    for (int i = 0; i < size; i++) {
        if (books[i].BookID == bid) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        cout << "Book not found!\n";
        return;
    }

    for (int i = index; i < size - 1; i++) {
        books[i] = books[i + 1];
    }

    size--;
    cout << "Book Removed Successfully!\n";
}

void Search(Book* books, int size) {
    string btitle;
    cout << "Enter book title: ";
    cin.ignore();
    getline(cin, btitle);

    bool found = false;
    for (int i = 0; i < size; i++) {
        if (books[i].title == btitle) {
            cout << "Book Found!\n";
            cout << "Book ID: " << books[i].BookID << endl;
            cout << "Author: " << books[i].Author << endl;
            cout << "Availability: " << (books[i].isAvailable ? "Available" : "Not Available") << endl;
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Book not found!\n";
    }
}

void Deallocate(Book* books) {
    delete[] books;
}

int main() {
    int size = 0;
    Book* books = AllocateMemory(size);
    int choice;

    do {
        cout << "1. Add Book\n2. Remove Book\n3. Search Book\n4. Exit the program\nEnter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addBook(books, size);
                break;
            case 2:
                RemoveBook(books, size);
                break;
            case 3:
                Search(books, size);
                break;
            case 4:
                cout << "You exited the program.\n";
                Deallocate(books);
                return 0;
            default:
                cout << "Invalid input, please try again.\n";
        }
    } while (choice != 4);

    return 0;
}
