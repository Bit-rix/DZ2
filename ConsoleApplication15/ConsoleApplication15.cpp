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
    cout << "\n�����: " << b.name << endl;
    cout << "�����: " << b.author << endl;
    cout << "г�: " << b.year << endl;
    cout << "�������: " << b.countPages << endl;
    cout << "����: " << b.genre << endl;
}

void showAllBooks(const Library& lib) {
    if (lib.count == 0) {
        cout << "���� ����.\n";
        return;
    }
    for (int i = 0; i < lib.count; i++) {
        showBook(lib.books[i]);
    }
}

void addBook(Library& lib) {
    if (lib.count < 100) {
        cout << "����� �����: ";
        getline(cin >> ws, lib.books[lib.count].name);

        cout << "�����: ";
        getline(cin, lib.books[lib.count].author);

        cout << "г�: ";
        cin >> lib.books[lib.count].year;

        cout << "ʳ������ �������: ";
        cin >> lib.books[lib.count].countPages;

        cout << "����: ";
        getline(cin >> ws, lib.books[lib.count].genre);

        lib.count++;
    }
    else {
        cout << "̳��� ����, �������� ���������!\n";
    }
}

void searchByName(const Library& lib, const string& name) {
    for (int i = 0; i < lib.count; i++) {
        if (lib.books[i].name == name) {
            showBook(lib.books[i]);
            return;
        }
    }
    cout << "����� �� ��������.\n";
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
            cout << "����������� ����� '" << lib.books[i].name << "':\n";

            cout << "���� �����: ";
            getline(cin >> ws, lib.books[i].name);

            cout << "����� �����: ";
            getline(cin, lib.books[i].author);

            cout << "����� ��: ";
            cin >> lib.books[i].year;

            cout << "���� ������� �������: ";
            cin >> lib.books[i].countPages;

            cout << "����� ����: ";
            getline(cin >> ws, lib.books[i].genre);

            return;
        }
    }
    cout << "����� �� ��������.\n";
}

void deleteBook(Library& lib, const string& name) {
    for (int i = 0; i < lib.count; i++) {
        if (lib.books[i].name == name) {
            for (int j = i; j < lib.count - 1; j++) {
                lib.books[j] = lib.books[j + 1];
            }
            lib.count--;
            cout << "����� ��������.\n";
            return;
        }
    }
    cout << "����� �� ��������.\n";
}



int main()
{
    setlocale(LC_ALL, "Ukrainian");

    Library lib;
    lib.year = 2024;
    lib.address = "���. ��������, 88";
    lib.name = "���������-���� #15";
    lib.owner = "������ �����";
    lib.maxCustomers = 100;
    lib.count = 0;

    addBook(lib);
    addBook(lib);

    cout << "\n�� �����:\n";
    showAllBooks(lib);

    string name;
    cout << "\n������ ����� ����� ��� ������: ";
    getline(cin >> ws, name);
    searchByName(lib, name);

    sortBooksByYear(lib);
    cout << "\n����� ���� ���������� �� �����:\n";
    showAllBooks(lib);

    cout << "\n������ ����� ����� ��� �����������: ";
    getline(cin >> ws, name);
    editBook(lib, name);

    cout << "\n����� ���� �����������:\n";
    showAllBooks(lib);

    cout << "\n������ ����� ����� ��� ���������: ";
    getline(cin >> ws, name);
    deleteBook(lib, name);

    cout << "\n����� ���� ���������:\n";
    showAllBooks(lib);

    return 0;


}

