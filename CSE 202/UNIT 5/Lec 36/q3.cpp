// You are using GCC
#include <iostream>
#include <string>
using namespace std;


class Book {
private:
    string* title;
    string* author;
    int* year;

public:

    Book(string t, string a, int y) {
        title = new string(t);  
        author = new string(a);  
        year = new int(y);       
    }

    
    ~Book() {
        delete title;
        delete author;
        delete year;
    }

    
    void displayDetails(int updatedYear) {
        cout << "Title: " << *title << endl;
        cout << "Author: " << *author << endl;
        cout << "Year of Publication: " << *year << endl;
        cout << "Updated Year of Publication: " << updatedYear << endl;
    }
};

int main() {
    string title, author;
    int year, updatedYear;

    
    getline(cin, title);  
    getline(cin, author); 
    cin >> year;          
    cin >> updatedYear;   

   
    Book book(title, author, year);
    
    book.displayDetails(updatedYear);

    return 0;
}
