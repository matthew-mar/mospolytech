#include <iostream>
#include <string.h>
#include <math.h>

using namespace std;

const int SIZE = 5;


struct student {
    bool isEmpty;
    char* fio;
    char* faculty;
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


int levenstein(char* a, char* b) {
    int M = strlen(a) / 2;
    int N = strlen(b) / 2;

    cout << M << " " << N << " " << endl;

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


void search(student* s, int numberField = 0, char* textField) {
    if (!(textField == "")) {
        int minimum = pow(2, 20);
        char* closest = "";

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

    if (numberField) {
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
    switch (field) {
        case 1: {
            int minimumLength = pow(2, 20);
            char* min;
            
            for (int i = 0; i < SIZE; i++) {
                if (!s[i].isEmpty) {
                    if (strlen(s[i].fio) / 2 < minimumLength) {
                        minimumLength = strlen(s[i].fio) / 2;
                        min = s[i].fio;
                    }
                }
            }

            cout << min << endl;
        }
        
        case 2: {
            int minimumLength = pow(2, 20);
            char* min;

            for (int i = 0; i < SIZE; i++) {
                if (!s[i].isEmpty) {
                    if (strlen(s[i].faculty) / 2 < minimumLength) {
                        minimumLength = strlen(s[i].faculty) / 2;
                        min = s[i].faculty;
                    }
                }
            }

            cout << min << endl;
        } 
        
        case 3: {
            int minimum = pow(2, 20);

            for (int i = 0; i < SIZE; i++) {
                if (!s[i].isEmpty) {
                    if (s[i].groupNumber < minimum) {
                        minimum = s[i].groupNumber;
                    }
                }
            }

            cout << minimum << endl;
        }
        
        case 4: {
            int minimum = pow(2, 20);

            for (int i = 0; i < SIZE; i++) {
                if (!s[i].isEmpty) {
                    if (s[i].bookNumber < minimum) {
                        minimum = s[i].bookNumber;
                    }
                }
            }

            cout << minimum << endl;
        }
    }
}


void assendingSort(student* s, int field) {
    for (int i = 0; i < SIZE - 1; i++) {
        for (int j = 0; j < SIZE - 1 - i; j++) {
            if (!s[j].isEmpty && !s[j + 1].isEmpty) {
                switch (field) {
                    case 1: {
                        if (strlen(s[j].fio) > strlen(s[j + 1].fio)) {
                            student tmp = s[j];
                            s[j] = s[j + 1];
                            s[j + 1] = tmp;
                        }
                    }

                    case 2: {
                        if (strlen(s[j].faculty) > strlen(s[j + 1].faculty)) {
                            student tmp = s[j];
                            s[j] = s[j + 1];
                            s[j + 1] = tmp;
                        }
                    }

                    case 3: {
                        if (s[j].groupNumber > s[j + 1].groupNumber) {
                            student tmp = s[j];
                            s[j] = s[j + 1];
                            s[j + 1] = tmp;
                        }
                    }

                    case 4: {
                        if (s[j].bookNumber > s[j + 1].bookNumber) {
                            student tmp = s[j];
                            s[j] = s[j + 1];
                            s[j + 1] = tmp;
                        }
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
                        if (strlen(s[j].fio) < strlen(s[j + 1].fio)) {
                            student tmp = s[j];
                            s[j] = s[j + 1];
                            s[j + 1] = tmp;
                        }
                    }

                    case 2: {
                        if (strlen(s[j].faculty) < strlen(s[j + 1].faculty)) {
                            student tmp = s[j];
                            s[j] = s[j + 1];
                            s[j + 1] = tmp;
                        }
                    }

                    case 3: {
                        if (s[j].groupNumber < s[j + 1].groupNumber) {
                            student tmp = s[j];
                            s[j] = s[j + 1];
                            s[j + 1] = tmp;
                        }
                    }

                    case 4: {
                        if (s[j].bookNumber < s[j + 1].bookNumber) {
                            student tmp = s[j];
                            s[j] = s[j + 1];
                            s[j + 1] = tmp;
                        }
                    }
                }
            }
        }
    }
}


void write(student* s) {
    FILE* db = fopen("db.txt", "a");

    for (int i = 0; i < SIZE; i++) {
        fprintf(db, s[i].fio);
    }

    fclose(db);
}


int main() {
    student students[SIZE];
    
    for (int i = 0; i < SIZE; i++) {
        dataInput(students, i);
    }

    write(students);

    return 0;
}
