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




int main()
{
    
}

