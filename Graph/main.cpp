#include "ListGraph/ListGraph.h"
#include "MatrixGraph/MatrixGraph.h"
#include "SetGraph/SetGraph.h"
#include "ArcGraph/ArcGraph.h"
#include <vector>
#include <iostream>
#include <queue>


void dfs_aux(const IGraph &graph, int vertex, std::vector<bool> &visited, void (*callback)(int v)) {
    visited[vertex] = true;
    callback(vertex);

    std::vector<int> children = graph.GetNextVertices(vertex);
    for (auto &child: children) {
        if (!visited[child])
            dfs_aux(graph, child, visited, callback);
    }
}

void dfs(const IGraph &graph, void (*callback)(int v)) {
    std::vector<bool> visited(graph.VerticesCount(), false);

    for (int vertex = 0; vertex < graph.VerticesCount(); ++vertex) {
        if (!visited[vertex]) {
            dfs_aux(graph, vertex, visited, callback);
        }
    }
}

void bfs(const IGraph &graph, void (*callback)(int v)) {
    std::vector<bool> visited(graph.VerticesCount(), false);
    std::queue<int> q;

    for (int vertex = 0; vertex < graph.VerticesCount(); ++vertex) {
        if (!visited[vertex]) {
            visited[vertex] = true;
            q.push(vertex);
            while (!q.empty()) {
                int v = q.front();
                q.pop();
                callback(v);
                std::vector<int> children = graph.GetNextVertices(v);
                for (auto &child: children) {
                    if (!visited[child]) {
                        visited[child] = true;
                        q.push(child);
                    }
                }

            }
        }
    }

}

int main() {
    IGraph *list = new ListGraph(9);
    list->AddEdge(0, 1);
    list->AddEdge(1, 5);
    list->AddEdge(6, 0);
    list->AddEdge(1, 2);
    list->AddEdge(2, 3);
    list->AddEdge(3, 4);
    list->AddEdge(4, 2);
    list->AddEdge(0, 7);
    list->AddEdge(0, 8);
    IGraph *matrix = new MatrixGraph(*list);
    IGraph *set = new SetGraph(*matrix);
    IGraph *arc = new ArcGraph(*set);

    std::cout << "==========LISTGRAPH==========" << std::endl;
    std::cout << "=============DFS=============" << std::endl;

    dfs(*list, [](int v) {
        std::cout << v << std::endl;
    });

    std::cout << "=============BFS=============" << std::endl;

    bfs(*list, [](int v) {
        std::cout << v << std::endl;
    });

    std::cout << "=========MATRIXGRAPH=========" << std::endl;
    std::cout << "=============DFS=============" << std::endl;

    dfs(*matrix, [](int v) {
        std::cout << v << std::endl;
    });

    std::cout << "=============BFS=============" << std::endl;

    bfs(*matrix, [](int v) {
        std::cout << v << std::endl;
    });
    std::cout << "===========SETGRAPH==========" << std::endl;
    std::cout << "=============DFS=============" << std::endl;

    dfs(*set, [](int v) {
        std::cout << v << std::endl;
    });

    std::cout << "=============BFS=============" << std::endl;

    bfs(*set, [](int v) {
        std::cout << v << std::endl;
    });
    std::cout << "===========ARCGRAPH==========" << std::endl;
    std::cout << "=============DFS=============" << std::endl;

    dfs(*arc, [](int v) {
        std::cout << v << std::endl;
    });

    std::cout << "=============BFS=============" << std::endl;

    bfs(*arc, [](int v) {
        std::cout << v << std::endl;
    });

    delete list;
    delete matrix;
    delete set;
    delete arc;

    return 0;
}