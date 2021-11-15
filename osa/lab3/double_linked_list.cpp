#include <iostream>
#include <string>

using namespace std;


struct student {
    bool is_empty;
    string fio;
    string faculty;
    int book_number;
    int group_number;
};


class List {

    class Node {
    
    public:
        student stud;  // значение
        Node * next_node;  // ссылка на следующий узел
        Node * previous_node;  // ссылка на предыдущий узел

        Node() {
            /* конструктор без аргументов */

            stud.is_empty = true;
            next_node = NULL;
            previous_node = NULL;
        }

        Node(student s) {
            /* конструктор с одним аргументом */

            stud = s;  // инициализация значения
            stud.is_empty = false;
            next_node = NULL;
            previous_node = NULL;
        }
    };

private:
    Node * head;  // указатель на первый узел списка
    Node * tail;  // указатель на последний узел списка

    Node* number_search() {
        /* поиск числа в списке */

        int number_field;
        cout << "enter a number: "; cin >> number_field;

        for (Node * current_node = head; current_node != NULL; current_node = current_node->next_node) {
            if (current_node->stud.group_number == number_field || current_node->stud.book_number == number_field) {
                cout << "found" << endl;
                return current_node;
            }
        }

        cout << "not found" << endl;
        return NULL;
    }

    Node* string_search() {
        /* поиск строки в списке */

        string text_field;
        cout << "enter a string: "; cin >> text_field;
        
        for (Node * current_node = head; current_node != NULL; current_node = current_node->next_node) {
            if (current_node->stud.fio == text_field || current_node->stud.faculty == text_field) {
                cout << "found" << endl;
                return current_node;
            }
        }

        cout << "not found" << endl;
        return NULL;
    }

public:
    List() {
        /* конструктор без аргументов */

        head = NULL;
        tail = NULL;
    }

    List(student s) {
        /* конструктор с одним аргументом */

        head = new Node(s);  // инициализация корневого узла
        tail = NULL;
    }

    void append(student s) {
        /* добавление элемента в конец списка */

        Node * new_node = new Node(s);  // указатель на новый узел

        if (head == NULL) {  // если первый элемент пуст
            head = new_node;
            return;
        }

        if (tail == NULL) {  // если последний элемент пуст
            tail = new_node;
            tail->previous_node = head;
            head->next_node = tail;
            return;
        }

        tail->next_node = new_node;
        new_node->previous_node = tail;
        tail = new_node;
    }

    void insert(student s) {
        /* добавление элемента в начало списка */

        Node * new_node = new Node(s);

        if (head == NULL) {  // если первый элемент пуст
            head = new_node;
            tail = new_node;
            return;
        }

        new_node->next_node = head;
        head->previous_node = new_node;
        head = new_node;
    }

    void del_end() {
        /* удаление последнего элемента */

        Node * del_tail = tail;
        tail = tail->previous_node;
        tail->next_node = NULL;
        delete del_tail;
    }

    void del_start() {
        /* удаление начального элемента */

        if (tail == NULL) {
            delete head;
            return;
        }

        Node * del_head = head;
        head = head->next_node;
        head->previous_node = NULL;
        delete del_head;
    }

    void search() {
        /* поиск элемента */

        int ans;
        cout << "search number: 1" << endl;
        cout << "search text: 2" << endl;
        cout << "search: "; cin >> ans;

        switch (ans) {
            case 1: {
                number_search();
                break;
            }

            case 2: {
                string_search();
                break;
            }
        }
    }

    void search_add(student s) {
        /* добавление элемента после найденного */

        Node * found_element;
        int ans;
        cout << "search number: 1" << endl;
        cout << "search text: 2" << endl;
        cout << "search: "; cin >> ans;

        switch (ans) {
            case 1: {
                found_element = number_search();
                break;
            }

            case 2: {
                found_element = string_search();
                break;
            }
        }

        if (found_element != NULL) {
            Node * new_node = new Node(s);
            Node * found_next = found_element->next_node;

            new_node->next_node = found_next;
            found_next->previous_node = new_node;

            found_element->next_node = new_node;
            new_node->previous_node = found_element;
        }
    }

    void search_del() {
        /* удаление найденного элемента */

        Node * found_element;
        int ans;
        cout << "search number: 1" << endl;
        cout << "search text: 2" << endl;
        cout << "search: "; cin >> ans;

        switch (ans) {
            case 1: {
                found_element = number_search();
                break;
            }

            case 2: {
                found_element = string_search();
                break;
            }
        }

        if (found_element == NULL) {
            return;
        }
        if (found_element == head) {
            del_start();
            return;
        }
        if (found_element == tail) {
            del_end();
            return;
        }

        Node * current_node = head;
        while (current_node->next_node != found_element) {
            current_node = current_node->next_node;
        }

        Node * found_next = found_element->next_node;
        current_node->next_node = found_next;
        found_next->previous_node = current_node;
        delete found_element;
    }

    void display() {
        /* вывод всех элементов от первого к последнему */

        for (Node * current_node = head; current_node != NULL; current_node = current_node->next_node) {
            cout << current_node->stud.fio << endl;
            cout << current_node->stud.faculty << endl;
            cout << current_node->stud.group_number << endl;
            cout << current_node->stud.book_number << endl;
        }
    }

    void display_reverse() {
        /* вывод всвех элементов от последнего к первому */

        for (Node * current_node = tail; current_node != NULL; current_node = current_node->previous_node) {
            cout << current_node->stud.fio << endl;
            cout << current_node->stud.faculty << endl;
            cout << current_node->stud.group_number << endl;
            cout << current_node->stud.book_number << endl;
        }
    }
};


int main() {
    List list;

    int ans;

    while (true) {
        cout << endl;
        cout << "Choode function" << endl;
        cout << "1: add student to end" << endl;
        cout << "2: add student to start" << endl;
        cout << "3: search element" << endl;
        cout << "4: add student after search element" << endl;
        cout << "5: delete search element" << endl;
        cout << "6: display list" << endl;
        cout << "7: display reverse" << endl;

        cin >> ans;

        switch (ans) {
            case 1: {
                student s;
                cout << "fio: "; cin >> s.fio;
                cout << "faculty: "; cin >> s.faculty;
                cout << "group number: "; cin >> s.group_number;
                cout << "book_number: "; cin >> s.book_number;
                list.append(s);
                break;
            }

            case 2: {
                student s;
                cout << "fio: "; cin >> s.fio;
                cout << "faculty: "; cin >> s.faculty;
                cout << "group number: "; cin >> s.group_number;
                cout << "book_number: "; cin >> s.book_number;
                list.insert(s);
                break;
            }

            case 3: {
                list.search();
                break;
            }

            case 4: {
                student s;
                cout << "fio: "; cin >> s.fio;
                cout << "faculty: "; cin >> s.faculty;
                cout << "group number: "; cin >> s.group_number;
                cout << "book_number: "; cin >> s.book_number;
                list.search_add(s);
                break;
            }

            case 5: {
                list.search_del();
                break;
            }

            case 6: {
                list.display();
                break;
            }

            case 7: {
                list.display_reverse();
                break;
            }
        }
    }

    return 0;
}
