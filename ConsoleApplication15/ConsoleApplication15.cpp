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



int main()
{
    
}

