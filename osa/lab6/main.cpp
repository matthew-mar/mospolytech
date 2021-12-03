#include <iostream>
#include <fstream>
#include <string>
#include <queue>

using namespace std;

const int N = 6;  // размер матрицы
const string FILE_PATH = "./graph.txt";


class Graph {
private:
    int graph[N][N];  // матрица вершин графа размером N*N

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
        int distances[N];  // массив хранит расстояния до каждой вершины
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

        for (int i = 0; i < N; i++) {
            cout << distances[i] << " ";
        }
        cout << endl;
    }
};


int main() {
    Graph graph;
    graph.read_graph();
    graph.display();
    cout << endl;
    graph.dijkstra();
    return 0;
}
