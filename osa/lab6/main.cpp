#include <iostream>
#include <fstream>
#include <string>
#include <queue>
#include <stack>

using namespace std;

const int N = 8;  // размер матрицы
// const string FILE_PATH = "./matrix1.txt";
const string FILE_PATH = "./matrix2.txt";


class Graph {
private:
    int graph[N][N];  // матрица вершин графа размером N*N
    int distances[N];  // массив хранит расстояния до каждой вершины

    queue <int> dfs_nodes_order;  // порядок пройденных вершин для обхода в глубину с использованием рекурсии

    void dfs2(int vertex, bool* used) {
        /* обход в глубину с использованием рекурсии */

        dfs_nodes_order.push(vertex);  // добавление вершины в очерель обхода
        used[vertex] = true;  // отметка вершины, как уже использованой
        for (int i = 0; i < N; i++) {
            if (graph[vertex][i] != 0 && !used[i]) {  // если есть дорога до вершины и вершина не использована
                dfs2(i, used);  // переход к вершине
            }
        }
    }

public:
    Graph() {}  // конструктор

    void read_graph() {
        /* считывание матрицы из файла */

        ifstream file;
        file.open(FILE_PATH);

        // считывание матрицы из файла
        if (file.is_open()) {
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++) {
                    file >> graph[i][j];
                }
            }
        }

        file.close();
    }

    void display() {
        /* вывод графа на экран в виде матрицы */

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                cout << graph[i][j] << " ";
            }
            cout << endl;
        }
    }

    void dijkstra() {
        /* алгоритм Дейкстра */

        distances[0] = 0;  // от первой вершины до самой себя расстояние 0
        for (int i = 1; i < N; i++) {
            distances[i] = 10000;  // остальным вершинам присваивается большое число
        }

        queue <int> vertexes;  // очередь просматриваемых вершин
        vertexes.push(0);  // добавление первой вершины в очередь

        while (!vertexes.empty()) {  // пока очередь не пуста
            int vertex_index = vertexes.front();  // берем индекс вершины из очереди
            vertexes.pop();  // удаляем индекс вершины из очереди
            for (int i = 0; i < N; i++) {
                if (graph[vertex_index][i] != 0) {  // если до вершины есть дорога
                    // если расстояние из текущей вершины до другой вершины меньше чем расстояние до этой вершины
                    if (distances[vertex_index] + graph[vertex_index][i] < distances[i]) {
                        // расстоянию до вершины присваивается расстояние от текущей вершины до нее
                        distances[i] = distances[vertex_index] + graph[vertex_index][i];
                        vertexes.push(i);  // вершина добавляется в очередь
                    }
                }
            }
        }

        // вывод массива путей
        for (int i = 0; i < N; i++) {
            cout << distances[i] << " ";
        }
        cout << endl;
    }

    void way(int vertex) {
        /* метод показывает путь до вершины vertex */

        int distance = distances[vertex];  // кратчайшее расстояние до вершины
        int way[N];  // массив хранит вершины, которые нужно пройти до вершины vertex
        way[0] = vertex;
        for (int i = 1; i < N; i++) {
            way[i] = 0;
        }
        int j = 0;  // индекс массива вершин

        while (distance != 0) {
            int v = way[j];
            for (int i = 0; i < N; i++) {
                if (graph[v][i] != 0) {
                    if (distance - graph[v][i] == distances[i]) {
                        distance = distances[i];
                        way[++j] = i;
                        break;
                    }
                }
            }
        }

        cout << "way: ";
        for (int i = j; i > -1; i--) {
            cout << way[i] << " ";
        }
        cout << endl;
    }

    void bfs(int begin, int end) {
        /* обход в ширину */

        queue <int> nodes_order;  // очередь хранит порядок обхода вершин
        nodes_order.push(begin);

        bool used_nodes[N];  // массив хранит метки использованных вершин
        used_nodes[begin] = true;
        for (int i = 1; i < N; i++) {
            if (i != begin) {
                used_nodes[i] = false;
            }
        }
        
        queue <int> que;
        que.push(begin);

        while (!que.empty()) {
            int vertex = que.front();  // забираем вершину из очереди
            que.pop();
            for (int i = 0; i < N; i++) {
                if (graph[vertex][i] != 0 && !used_nodes[i]) {  // если до вершины есть дорого и вершина раньше не использовалась
                    nodes_order.push(i);  // добавляем вершину в очередь обхода
                    used_nodes[i] = true;  // ставим метку, что вершина уже использовалась
                    que.push(i);  // добавляем вершину в очередь
                }
            }
        }

        queue <int> way_to_end = nodes_order;

        // вывод вершин в порядке обхода
        cout << "way order: ";
        for (int i = 0; i < N; i++) {
            cout << nodes_order.front() << " ";
            nodes_order.pop();
        }
        cout << endl;

        // вывод вершин в порядке обхода до конечной вершины
        cout << "way to end order: ";
        for (int i = 0; i < N; i++) {
            cout << way_to_end.front() << " ";
            if (way_to_end.front() == end) {
                cout << endl;
                break;
            }
            way_to_end.pop();
        }
        cout << endl;
    }

    void dfs1(int begin, int end) {
        /* обход в глубину с использованием стека */

        queue <int> nodes_order;  // очередь порядка обхода
        stack <int> s;  // стек для обхода вершин
        s.push(begin);
        
        bool used_nodes[N];  // массив с метками использованных вершин
        for (int i = 0; i < N; i++) {
            used_nodes[i] = false;
        }

        while (!s.empty()) {  // пока стек не пуст
            int top = s.top();  // берем последнюю вершину из стека
            s.pop();
            if (!used_nodes[top]) {  // если вершина не использована
                for (int i = N-1; i > -1; i--) {
                    if (graph[top][i] != 0) {
                        s.push(i);  // добавляем в стек все связанные вершины
                    }
                }
                nodes_order.push(top);  // добавляем вершину в стек
                used_nodes[top] = true;  // отмечаем как использованную
            }
        }

        queue <int> way_to_end = nodes_order;

        // вывод порядка обхода
        cout << "way order: ";
        while (!nodes_order.empty()) {
            cout << nodes_order.front() << " ";
            nodes_order.pop();
        }
        cout << endl;

        // вывод порядка обхода до конечной вершины
        cout << "way to end order: ";
        for (int i = 0; i < N; i++) {
            cout << way_to_end.front() << " ";
            if (way_to_end.front() == end) {
                cout << endl;
                break;
            }
            way_to_end.pop();
        }
        cout << endl;
    }

    void dfs(int begin, int end) {
        // int nodes[N];
        // for (int i = 0; i < N; i++) {
        //     nodes[i] = 0;
        // }

        bool used[N];
        for (int i = 0; i < N; i++) {
            used[i] = false;
        }

        dfs2(begin, used);

        queue <int> way_to_end = dfs_nodes_order;
        
        // вывод порядка обхода вершин
        cout << "way order: ";
        while (!dfs_nodes_order.empty()) {
            cout << dfs_nodes_order.front() << " ";
            dfs_nodes_order.pop();
        }
        cout << endl;

        // вывод порядка обхода до конечной вершины
        cout << "way to end order: ";
        for (int i = 0; i < N; i++) {
            cout << way_to_end.front() << " ";
            if (way_to_end.front() == end) {
                cout << endl;
                break;
            }
            way_to_end.pop();
        }
        cout << endl;
    }
};


int main() {
    Graph graph;
    graph.read_graph();

    cout << "choose function:" << endl;
    cout << "1: display graph" << endl;
    cout << "2: Dijkstra's algorithm" << endl;
    cout << "3: way to vertex" << endl;
    cout << "4: bfs" << endl;
    cout << "5: dfs1" << endl;
    cout << "6: dfs2" << endl;

    int ans;
    while (true) {
        cin >> ans;
        switch (ans) {
            case 1: {
                graph.display();
                cout << endl;
                break;
            }
            case 2: {
                graph.dijkstra();
                cout << endl;
                break;
            }
            case 3: {
                int v;
                cout << "enter a vertex: "; cin >> v;
                graph.way(v);
                cout << endl;
                break;
            }
            case 4: {
                int begin, end;
                cout << "write begin vertex: "; cin >> begin;
                cout << "write end vertex: "; cin >> end;
                graph.bfs(begin, end);
                cout << endl;
                break;
            }
            case 5: {
                int begin, end;
                cout << "write begin vertex: "; cin >> begin;
                cout << "write end vertex: "; cin >> end;
                graph.dfs1(begin, end);
                cout << endl;
                break;
            }
            case 6: {
                int begin, end;
                cout << "write begin vertex: "; cin >> begin;
                cout << "write end vertex: "; cin >> end;
                graph.dfs(begin, end);
                cout << endl;
                break;
            }
        }    
    }

    return 0;
}
