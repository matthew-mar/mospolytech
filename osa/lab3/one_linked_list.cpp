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

        Node() {
            /* конструктор без аргументов */

            stud.is_empty = true;
            next_node = NULL;
        }

        Node(student s) {
            /* конструктор с одним аргументом */

            stud = s;  // инициализация значения
            stud.is_empty = false;
            next_node = NULL;
        }
    };


private:
    Node * root;  // указатель на корневой узел

    Node* number_search() {
        /* поиск числа в списке */

        int number_field;
        cout << "enter a number: "; cin >> number_field;

        for (Node * current_node = root; current_node != NULL; current_node = current_node->next_node) {
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
        
        for (Node * current_node = root; current_node != NULL; current_node = current_node->next_node) {
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

        root = NULL;
    }

    List(student s) {
        /* конструктор с одним аргументом */

        root = new Node(s);  // инициализация корневого узла
    }

    void append(student s) {
        /* добавление элемента в конец списка */

        Node * new_node = new Node(s);  // указатель на новый узел

        if (root != NULL) {  // если список не пустой
            Node * current_node = root;  // текущий узел указывает на корневой узел
            
            // движение по списку
            while (current_node->next_node != NULL) {
                current_node = current_node->next_node;
            }
            
            current_node->next_node = new_node;  // создание ссылки у конечного узла на новый узел
        } 
        else {  // если список пуст
            root = new_node;  // кладем новый элемент в корневой узел
        }
        new_node->next_node = NULL;
    }

    void insert(student s) {
        /* добавление элемента в начало списка */

        Node * new_node = new Node(s);  // указатель на новый узел
        new_node->next_node = root;  // создание ссылки на корневой элемент
        root = new_node;  // переопределение корневого элемента 
    }

    void del_end() {
        /* удаление последнего элемента */

        Node * current_node = root;  // текущий узел указывает на корневой узел
        Node * next_node = current_node->next_node;  // указатель на следующий узел

        // движение по списку
        while (next_node->next_node != NULL) {
            current_node = current_node->next_node;
            next_node = next_node->next_node;
        }

        current_node->next_node = NULL;
        delete next_node;
    }

    void del_start() {
        /* удаление начального элемента */

        if (root->next_node == NULL) {  // если список состоит из одного элемента
            delete root;
            return;
        }

        Node * del_root = root;
        root = root->next_node;
        delete del_root;
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
            new_node->next_node = found_element->next_node;
            found_element->next_node = new_node;
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
        if (found_element == root) {
            del_start();
            return;
        }

        Node * current_node = root;
        while (current_node->next_node != found_element) {
            current_node = current_node->next_node;
        }

        current_node->next_node = found_element->next_node;
        delete found_element;
    }

    void display() {
        /* вывод всех элементов списка */

        Node * current_node = root;
        while (current_node != NULL) {
            cout << current_node->stud.fio << endl;
            cout << current_node->stud.faculty << endl;
            cout << current_node->stud.group_number << endl;
            cout << current_node->stud.book_number << endl;
            current_node = current_node->next_node;
        }
    }
};


int main() {
    List list1;

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

        cin >> ans;

        switch (ans) {
            case 1: {
                student s;
                cout << "fio: "; cin >> s.fio;
                cout << "faculty: "; cin >> s.faculty;
                cout << "group number: "; cin >> s.group_number;
                cout << "book_number: "; cin >> s.book_number;
                list1.append(s);
                break;
            }

            case 2: {
                student s;
                cout << "fio: "; cin >> s.fio;
                cout << "faculty: "; cin >> s.faculty;
                cout << "group number: "; cin >> s.group_number;
                cout << "book_number: "; cin >> s.book_number;
                list1.insert(s);
                break;
            }

            case 3: {
                list1.search();
                break;
            }

            case 4: {
                student s;
                cout << "fio: "; cin >> s.fio;
                cout << "faculty: "; cin >> s.faculty;
                cout << "group number: "; cin >> s.group_number;
                cout << "book_number: "; cin >> s.book_number;
                list1.search_add(s);
                break;
            }

            case 5: {
                list1.search_del();
                break;
            }

            case 6: {
                list1.display();
                break;
            }
        }
    }

    return 0;
}
