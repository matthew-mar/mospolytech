#include <iostream>

using namespace std;

const int N = 5;


class stack {

private:
    int* arr;
    int top;

public:
    // конструктор без параметров
    stack() {
        arr = new int[N];
        top = -1;
    }

    // деструктор
    ~stack() { 
        delete[] arr;
    }

    // контроль на отсутствие элемнтов
    bool isEmpty() {
        return top == -1;
    }

    // контроль на переполнение
    bool isFull() {
        return top == N-1;
    }

    // добавление элемента
    void push(int a) {
        if (isFull()) {
            cout << "stack is full" << endl;
        } else {
            arr[++top] = a;
        }
    }

    // извлечение элемента
    int pop() {
        if (isEmpty()) {
            cout << "stack is empty" << endl;
            exit(1);
        }
        
        return arr[top--];
    }
};


int main() {
    setlocale(LC_ALL, "rus");

    stack s = stack();
    bool in;  // выбор: вставка/извлечение
    int a;
    
    while (true) {
        cout << "Введите 1, чтобы добавить элемент в стек и 0, чтобы извлечь\n";
        cin >> in;

        if (in) {
            cout << "Введите число: "; cin >> a;
            s.push(a);
        } else
            cout << s.pop() << endl;
    }

    return 0;
}
