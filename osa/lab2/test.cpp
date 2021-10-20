#include <iostream>
#include <fstream>
#include <string>

using namespace std;


int main() {
    string fio;
    string faculty;
    int group_number;
    int book_number;
    char end;

    ifstream db;
    db.open("db.txt");

    while (!db.eof()) {
        for (int i = 0; i < 3; i++) {
            getline(db, fio);
            cout << fio;
            getline(db, faculty);
            cout << faculty;
            db >> group_number;
            cout << group_number;
            db >> book_number;
            cout << book_number;
            db >> end;
            cout << end;
        }
    }

    db.close();

    return 0;
}
