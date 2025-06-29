#include <iostream>
#include <string>
using namespace std;

struct Book {
    string name;
    string author;
    int year;
    int countPages;
    string genre;
};

struct Library {
    int year;
    string address;
    string name;
    string owner;
    int maxCustomers;
    Book books[100];
    int count;
};

void showBook(const Book& b) {
    cout << "\nКнига: " << b.name << endl;
    cout << "Автор: " << b.author << endl;
    cout << "Рік: " << b.year << endl;
    cout << "Сторінок: " << b.countPages << endl;
    cout << "Жанр: " << b.genre << endl;
}

void showAllBooks(const Library& lib) {
    if (lib.count == 0) {
        cout << "Книг немає.\n";
        return;
    }
    for (int i = 0; i < lib.count; i++) {
        showBook(lib.books[i]);
    }
}

void addBook(Library& lib) {
    if (lib.count < 100) {
        cout << "Назва книги: ";
        getline(cin >> ws, lib.books[lib.count].name);

        cout << "Автор: ";
        getline(cin, lib.books[lib.count].author);

        cout << "Рік: ";
        cin >> lib.books[lib.count].year;

        cout << "Кількість сторінок: ";
        cin >> lib.books[lib.count].countPages;

        cout << "Жанр: ";
        getline(cin >> ws, lib.books[lib.count].genre);

        lib.count++;
    }
    else {
        cout << "Місця немає, бібліотека заповнена!\n";
    }
}



int main()
{
    
}

