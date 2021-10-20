#include <iostream>

using namespace std;

const int N = 5;


class queue {

private:
    int* arr;
    int head;
    int tail;

public:
    queue() {
        head = 0;
        tail = 0;
        arr = new int[N];
    }

    ~queue() {
        delete[] arr;
    }

    bool isFull() {
        return head == (tail + 1) % (N + 1);
    }

    bool isEmpty() {
        return head == tail;
    }

    void add(int a) {
        if (isFull())
            cout << "queue is full" << endl;
        else {
            arr[tail] = a;
            tail = (tail + 1) % (N + 1);
        }
    }

    int extract() {
        if (isEmpty()) {
            cout << "queue is empty" << endl;
            exit(1);
        }

        int out = arr[head];
        head = (head + 1) % (N + 1);
        return out;
    }
};


int main() {
    int znach;
    bool r;
    queue q;

    while (true) {
        cout << "Enter 1 for add and 0 for extract: "; cin >> r;
        if (r) {
            cout << "Enter a number: "; cin >> znach;
            q.add(znach);
        } else {
            cout << q.extract() << endl;
        }
    }
}
