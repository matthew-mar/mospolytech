// 1 12 19 89 25 8 20 10 91 63 45 56 76

#include <iostream>
#include <fstream>

using namespace std;


const string FILE_PATH = "db.txt";


class Tree {

private:

    class Node {
    
    public:
        int data;  // значение узла
        Node* left;  // указател на левый узел
        Node* right;  // указатель на првый узел

        Node() {}  // конструктор без аргументов

        Node(int d) {  // конструктор с одним аргументом
            data = d;  // запись данных
            left = NULL;
            right = NULL;
        }
    };

    
    Node* get_most_left(Node* node) {
        Node* current_node = node;
        while (current_node->left != NULL) {
            current_node = current_node->left;
        }
        return current_node;
    }

    Node* get_previous_node(Node* need_node) {
        Node* current_node = root;  // начало поиска

        if (current_node->left == NULL && current_node->right == NULL) {
            return current_node;
        }

        while (current_node->left != need_node && current_node->right != need_node) {
            if (need_node->data < current_node->data) {
                current_node = current_node->left;
            } else if (need_node->data > current_node->data) {
                current_node = current_node->right;
            }
        }

        return current_node;
    }

public:
    Node* root;  // указатель на корень дерева

    Tree() {  // конструктор без аргументов
        root = NULL;
    }

    Tree(int d) {  // конструктор с одним аргументом
        root = new Node(d);
    }

    void print(Node* node) {
        /* Вывод дерева */

        if (node != NULL) {  // если переданный узел существует
            cout << node->data << " ";  // вывод данных
            print(node->left);  // печать данных левого узла
            print(node->right);  // печать данных правого узла
        }
    }

    Node* search(int s) {
        /* 
            * Поиск в дереве
            * Возвращает 1, если элемент найден.
            * Возвращает 0, если элемент не найден 
        */

        Node* current_node = root;

        while (current_node != NULL) {  // пока узел не пустой
            if (current_node->data == s) {  // если значение в узле равно поисковому значению
                cout << 1 << endl;
                return current_node;  // значение найдено
            } else if (s < current_node->data) {  // если поисковое значение меньше значения в узле
                current_node = current_node->left;  // спускаемся в левый узел
            } else {  // иначе поисковое значение больше значения в узле
                current_node = current_node->right;  // спускаемся в правый узел
            }
        }

        cout << 0 << endl;
        return NULL;  // значение не найдено
    }

    Node* add_node(int d, Node** node) {
        /* Добавление элемента в дерево */

        if (*node == NULL) {  // если узел пустой
            *node = new Node(d);  // текущий узел указывает на новый узел
        }

        if (d < (*node)->data) {  // если переданное занчение меньше значения узла
            (*node)->left = add_node(d, &(*node)->left);  // спускаемся в левый узел
        } else if (d > (*node)->data) {  // если переданное занчение больше значения узла
            (*node)->right = add_node(d, &(*node)->right);  // спускаемся в правый узел
        }

        return *node;
    }

    void delete_node(int s) {
        Node* search_node = search(s);  // узел, который нужно удалить
        
        if (search_node == root) {  // если нужный узел - корневой узел
            // если узел является листом
            if (root->left == NULL && root->right == NULL) {
                clear();
            }

            // если узел хранит одно поддерево
            if (root->left != NULL && root->right == NULL) {  // если поддерево слева
                root = root->left;
            } else if (root->right != NULL && root->left == NULL) {  // если поддерево справа
                root = root->right;
            }

            // если узел хранит два поддерева
            if (root->left != NULL && root->right != NULL) {
                Node* most_left = get_most_left(root->right);
                Node* pre_most_left = get_previous_node(most_left);

                if (most_left->right == NULL) {
                    if (most_left == root->right) {
                        most_left->left = root->left;
                    } else {
                        most_left->left = root->left;
                        most_left->right = root->right;
                    }
                    pre_most_left->left = NULL;
                    root = most_left;
                } else {
                    if (most_left == root->right) {
                        most_left->left = root->left;
                    } else {
                        pre_most_left->left = most_left->right;
                        most_left->left = root->left;
                        most_left->right = root->right;
                    }
                    root = most_left;
                }
            }
        } else {
            Node* previous_node = get_previous_node(search_node);  // узел, предыдущий от поискового

            if (previous_node->left == search_node) {  // если нужный узел слева
                // если узел является листом
                if (search_node->left == NULL && search_node->right == NULL) {
                    previous_node->left = NULL;
                    return;
                }

                // если узел хранит одно поддерево
                if (search_node->left != NULL && search_node->right == NULL) {  // если поддерево слева
                    previous_node->left = search_node->left;
                    return;
                } else if (search_node->right != NULL && search_node->left == NULL) {  // если поддерево справа
                    previous_node->left = search_node->right;
                    return;
                }

                // если узел хранит два поддерева
                if (search_node->left != NULL && search_node->right != NULL) {
                    Node* most_left = get_most_left(search_node->right);  // берем самый левый элемент от нужного элемента
                    Node* pre_most_left = get_previous_node(most_left);  // узел перед самым левым

                    if (most_left->right == NULL) {  // если самый левый узел не хранит поддеревьев
                        previous_node->left = most_left;
                        if (most_left == search_node->right) {
                            most_left->left = search_node->left;
                        } else {
                            most_left->left = search_node->left;
                            most_left->right = search_node->right;
                        }
                        pre_most_left->left = NULL;
                    } else {
                        if (most_left == search_node->right) {
                            previous_node->left = most_left;
                            most_left->left = search_node->left;
                        } else {
                            pre_most_left->left = most_left->right;
                            previous_node->left = most_left;
                            most_left->left = search_node->left;
                            most_left->right = search_node->right;
                        }
                    }
                }
            }

            if (previous_node->right == search_node) {  // если нужный узел справа
                // если узел является листом
                if (search_node->left == NULL && search_node->right == NULL) {
                    previous_node->right = NULL;
                    return;
                }

                // если узел хранит одно поддерево
                if (search_node->left != NULL && search_node->right == NULL) {  // если поддерево слева
                    previous_node->right = search_node->left;
                    return;
                } else if (search_node->right != NULL && search_node->left == NULL) {  // если поддерево справа
                    previous_node->right = search_node->right;
                    return;
                }

                // если узел хранит два поддерева
                if (search_node->left != NULL && search_node->right != NULL) {
                    Node* most_left = get_most_left(search_node->right);  // берем самый левый элемент от нужного элемента
                    Node* pre_most_left = get_previous_node(most_left);  // узел перед самым левым

                    if (most_left->right == NULL) {  // если самый левый узел не хранит поддеревьев
                        previous_node->right = most_left;
                        if (most_left == search_node->right) {
                            most_left->left = search_node->left;
                        } else {
                            most_left->left = search_node->left;
                            most_left->right = search_node->right;
                        }
                        pre_most_left->left = NULL;
                    } else {
                        if (most_left == search_node->right) {
                            previous_node->right = most_left;
                            most_left->left = search_node->left;
                        } else {
                            pre_most_left->left = most_left->right;
                            most_left->left = search_node->left;
                            most_left->right = search_node->right;
                        }
                    }
                }
            }
        }
    }

    void write(Node* node) {
        /* Запись данных из дерева в файл */

        ofstream db_out;
        db_out.open(FILE_PATH, ofstream::app);  // открытие файла в режиме добавления данных

        if (node != NULL) {
            if (db_out.is_open()) {
                db_out << node->data << "\n";  // запись данных файл
                db_out.close();
            }
            write(node->left);  // запись для левого узла
            write(node->right);  // запись для правого узла
        }

        db_out.close();
    }

    void read() {
        /* Чтение данных из файла */

        ifstream db_in;
        db_in.open(FILE_PATH);

        if (db_in.is_open()) {
            db_in.seekg(0);  // перемещение указателя в начало файла
            while (!db_in.eof()) {  // движение до конца файла
                int d;
                db_in >> d;
                this->root = add_node(d, &this->root);  // добавление значения из файла в дерево
            }
        }

        db_in.close();
    }

    void clear() {
        /* Очистка дерева */

        this->root = NULL;
    }
};


int main() {
    Tree t;
    int input, ans;

    cout << "Fill the tree:" << endl;
    for (int i = 0; i < 13; i++) {
        cout << "number: "; cin >> input;
        t.add_node(input, &t.root);
    }

    cout << "choose function: " << endl;
    cout << "print tree: 1" << endl;
    cout << "search in tree: 2" << endl;
    cout << "write data to file: 3" << endl;
    cout << "read data from file: 4" << endl;
    cout << "delete node: 5" << endl;
    cout << "clear tree: 6" << endl;

    while (true) {
        cout << endl;
        cin >> ans;

        switch (ans) {
            case 1: {
                t.print(t.root);
                break;
            }

            case 2: {
                int s;
                cout << "enter a number: "; cin >> s;
                cout << t.search(s) << endl;
                break;
            }

            case 3: {
                t.write(t.root);
                cout << "data recorded" << endl;
                break;
            }

            case 4: {
                t.read();
                cout << "data read" << endl;
                break;
            }

            case 5: {
                int s;
                cout << "enter a number: "; cin >> s;
                t.delete_node(s);
                cout << "node deleted" << endl;
                break;
            }
        }
    }

    return 0;
}
