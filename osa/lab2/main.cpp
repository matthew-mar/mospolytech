#include <iostream>
#include <string>
#include <math.h>
#include <fstream>

using namespace std;

const int SIZE = 3;


struct student {
    bool isEmpty = true;
    string fio;
    string faculty;
    int groupNumber;
    int bookNumber;
};


void clear(student* s, int ind) {
    s[ind] = student();
    s[ind].isEmpty = true;
}


int findEmpty(student* s) {
    for (int i = 0; i < SIZE; i++) {
        if (s[i].isEmpty) {
            return i;
        }
    }
    return -1;
}


void dataInput(student* s, int ind) {
    cin >> s[ind].fio;
    cin >> s[ind].faculty;
    cin >> s[ind].groupNumber;
    cin >> s[ind].bookNumber;

    s[ind].isEmpty = false;
}


void dataOutput(student* s, int ind) {
    if (!s[ind].isEmpty) {
        cout << s[ind].fio << endl;
        cout << s[ind].faculty << endl;
        cout << s[ind].groupNumber << endl;
        cout << s[ind].bookNumber << endl;
    }
}


void output(student* s) {
    for (int i = 0; i < SIZE; i++) {
        if (!s[i].isEmpty) {
            cout << s[i].fio << endl;
            cout << s[i].faculty << endl;
            cout << s[i].groupNumber << endl;
            cout << s[i].bookNumber << endl;
        }
    }
}


int levenstein(string a, string b) {
    int M = a.length() / 2;
    int N = b.length() / 2;

    int F[M + 1][N + 1];

    for (int i = 0; i < M + 1; i++) {
        for (int j = 0; j < N + 1; j++) {
            if (i * j == 0) {
                F[i][j] = i + j;
            } else {
                F[i][j] = 0;
            }
        }
    }

    for (int i = 1; i < M + 1; i++) {
        for (int j = 1; j < N + 1; j++) {
            if ((a[i-1] == b[j-1])) {
                F[i][j] = F[i-1][j-1];
            } else {
                F[i][j] = 1 + min(min(F[i-1][j], F[i][j-1]), F[i-1][j-1]);
            }
        }
    }

    return F[M][N];
}


void search(student* s, int numberField, string textField) {
    if (textField != "") {
        int minimum = pow(2, 20);
        string closest = "";

        for (int i = 0; i < SIZE; i++) {
            if (!s[i].isEmpty) {
                int distance = levenstein(textField, s[i].fio);
                if (distance < minimum) {
                    minimum = distance;
                    closest = s[i].fio;
                }

                distance = levenstein(textField, s[i].faculty);
                if (distance < minimum) {
                    minimum = distance;
                    closest = s[i].faculty;
                }
            }
        }

        cout << closest << endl;
    }

    if (numberField != 0) {
        int closest = pow(2, 20);
        int minDifference = pow(2, 20);

        for (int i = 0; i < SIZE; i++) {
            if (!s[i].isEmpty) {
                int difference = abs(s[i].groupNumber - numberField);
                if (minDifference > difference) {
                    minDifference = difference;
                    closest = s[i].groupNumber;
                }

                difference = abs(s[i].bookNumber - numberField);
                if (minDifference > difference) {
                    minDifference = difference;
                    closest = s[i].bookNumber;
                }
            }
        }

        cout << closest << endl;
    }
}


void minimumElement(student* s, int field) {
    int minimum = pow(2, 20);
    string min;

    for (int i = 0; i < SIZE; i++) {
        if (!s[i].isEmpty) {
            switch (field) {
                case 1: {
                    if (s[i].fio.length() / 2 < minimum) {
                        minimum = s[i].fio.length() / 2;
                        min = s[i].fio;
                    }
                    break;
                }

                case 2: {
                    if (s[i].faculty.length() / 2 < minimum) {
                        minimum = s[i].faculty.length() / 2;
                        min = s[i].faculty;
                    }
                    break;
                }

                case 3: {
                    if (s[i].groupNumber < minimum) {
                        minimum = s[i].groupNumber;
                    }
                    break;
                }

                case 4: {
                    if (s[i].bookNumber < minimum) {
                        minimum = s[i].bookNumber;
                    }
                    break;
                }
            }
        }
    }

    if (min.length() != 0) {
        cout << min << endl;
    } else {
        cout << minimum << endl;
    }
}


void assendingSort(student* s, int field) {
    for (int i = 0; i < SIZE - 1; i++) {
        for (int j = 0; j < SIZE - 1 - i; j++) {
            if (!s[j].isEmpty && !s[j + 1].isEmpty) {
                switch (field) {
                    case 1: {
                        if (s[j].fio.length() > s[j + 1].fio.length()) {
                            student tmp = s[j];
                            s[j] = s[j + 1];
                            s[j + 1] = tmp;
                        }
                        break;
                    }

                    case 2: {
                        if (s[j].faculty.length() > s[j + 1].faculty.length()) {
                            student tmp = s[j];
                            s[j] = s[j + 1];
                            s[j + 1] = tmp;
                        }
                        break;
                    }

                    case 3: {
                        if (s[j].groupNumber > s[j + 1].groupNumber) {
                            student tmp = s[j];
                            s[j] = s[j + 1];
                            s[j + 1] = tmp;
                        }
                        break;
                    }

                    case 4: {
                        if (s[j].bookNumber > s[j + 1].bookNumber) {
                            student tmp = s[j];
                            s[j] = s[j + 1];
                            s[j + 1] = tmp;
                        }
                        break;
                    }
                }
            }
        }
    }
}


void descendingSort(student* s, int field) {
    for (int i = 0; i < SIZE - 1; i++) {
        for (int j = 0; j < SIZE - 1 - i; j++) {
            if (!s[j].isEmpty && !s[j + 1].isEmpty) {
                switch (field) {
                    case 1: {
                        if (s[j].fio.length() < s[j + 1].fio.length()) {
                            student tmp = s[j];
                            s[j] = s[j + 1];
                            s[j + 1] = tmp;
                        }
                        break;
                    }

                    case 2: {
                        if (s[j].faculty.length() < s[j + 1].faculty.length()) {
                            student tmp = s[j];
                            s[j] = s[j + 1];
                            s[j + 1] = tmp;
                        }
                        break;
                    }

                    case 3: {
                        if (s[j].groupNumber < s[j + 1].groupNumber) {
                            student tmp = s[j];
                            s[j] = s[j + 1];
                            s[j + 1] = tmp;
                        }
                        break;
                    }

                    case 4: {
                        if (s[j].bookNumber < s[j + 1].bookNumber) {
                            student tmp = s[j];
                            s[j] = s[j + 1];
                            s[j + 1] = tmp;
                        }
                        break;
                    }
                }
            }
        }
    }
}


void read(student* s) {
    ifstream db;
    char end;
    int i = 0;
    db.open("db.txt");

    while (!db.eof() && i < 3) {
        getline(db, s[i].fio);
        getline(db, s[i].faculty);
        db >> s[i].groupNumber;
        db >> s[i].bookNumber;
        db >> s[i].isEmpty;
        db >> end;
        i++;
    }

    db.close();
}


void write(student* s) {
    ofstream db;
    db.open("db.txt", ofstream::app);
    
    for (int i = 0; i < SIZE; i++) {
        if (!s[i].isEmpty) {
            db << s[i].fio << "\n";
            db << s[i].faculty << "\n";
            db << s[i].groupNumber << "\n";
            db << s[i].bookNumber << "\n";
            db << s[i].isEmpty << "\n";
        }
    }

    db.close();
}


int main() {
    student students[SIZE];
    int function;

    std::cout << "Выберите функцию: " << endl;
    std::cout << "1. Очистить элемент массива" << endl;
    std::cout << "2. Найти пустой элемент массива" << endl;
    std::cout << "3. Вписать данные в элемент массива" << endl;
    std::cout << "4. Вывести данные из элемента массива" << endl;
    std::cout << "5. Вывести данные из массива" << endl;
    std::cout << "6. Поиск максимально близкого по значению поля" << endl;
    std::cout << "7. Минимальный элемент" << endl;
    std::cout << "8. Сортировка по возрастанию" << endl;
    std::cout << "9. Сортировка по убыванию" << endl;
    std::cout << "10. Запись данных в файл" << endl;
    std::cout << "11. Чтение из файла" << endl;

    while (true) {
        cin >> function;
        switch (function) {
            case 1: {
                int ind;
                std::cout << "Введите индекс: "; cin >> ind;
                clear(students, ind);
                break;
            }

            case 2: {
                std::cout << findEmpty(students) << endl;
                break;
            }

            case 3: {
                int ind;
                std::cout << "Введите индекс: "; cin >> ind;
                dataInput(students, ind);
                break;
            }

            case 4: {
                int ind;
                std::cout << "Введите индекс: "; cin >> ind;
                dataOutput(students, ind);
                break;
            }

            case 5: {
                output(students);
                break;
            }

            case 6: {
                int num;
                string str;

                std::cout << "Введите число: "; cin >> num;
                std::cout << "Введите строку: "; cin >> str;

                search(students, num, str);
                break;
            }

            case 7: {
                int num;
                std::cout << "Введите номер поля: "; cin >> num;
                minimumElement(students, num);
                break;
            }

            case 8: {
                int num;
                std::cout << "Введите номер поля: "; cin >> num;
                assendingSort(students, num);
                output(students);
                break;
            }

            case 9: {
                int num;
                std::cout << "Введите номер поля: "; cin >> num;
                descendingSort(students, num);
                output(students);
                break;
            }

            case 10: {
                write(students);
                break;
            }

            case 11: {
                read(students);
                break;
            }

            default:
                break;
        }
    }

    std::cout << "\n";

    return 0;
}
