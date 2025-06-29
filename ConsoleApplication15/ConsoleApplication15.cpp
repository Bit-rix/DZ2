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

void searchByName(const Library& lib, const string& name) {
    for (int i = 0; i < lib.count; i++) {
        if (lib.books[i].name == name) {
            showBook(lib.books[i]);
            return;
        }
    }
    cout << "Книгу не знайдено.\n";
}

void sortBooksByYear(Library& lib) {
    for (int i = 0; i < lib.count - 1; i++) {
        for (int j = 0; j < lib.count - i - 1; j++) {
            if (lib.books[j].year > lib.books[j + 1].year) {
                Book temp = lib.books[j];
                lib.books[j] = lib.books[j + 1];
                lib.books[j + 1] = temp;
            }
        }
    }
}

void editBook(Library& lib, const string& name) {
    for (int i = 0; i < lib.count; i++) {
        if (lib.books[i].name == name) {
            cout << "Редагування книги '" << lib.books[i].name << "':\n";

            cout << "Нова назва: ";
            getline(cin >> ws, lib.books[i].name);

            cout << "Новий автор: ";
            getline(cin, lib.books[i].author);

            cout << "Новий рік: ";
            cin >> lib.books[i].year;

            cout << "Нова кількість сторінок: ";
            cin >> lib.books[i].countPages;

            cout << "Новий жанр: ";
            getline(cin >> ws, lib.books[i].genre);

            return;
        }
    }
    cout << "Книгу не знайдено.\n";
}



int main()
{
    
}

