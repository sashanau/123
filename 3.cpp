#include <iostream>
#include <vector>
#include <list>
#include <utility>
#include <set>
#include <queue>
#include <unordered_set>

class IGraph {
public:
    virtual ~IGraph() = default;

    virtual void AddEdge(int from, int to, int weight) = 0;

    virtual int VerticesCount() const = 0;

    virtual std::vector<std::pair<int, int>> GetNextVertices(int vertex) const = 0;

};

class ListGraph : public IGraph {
public:
    explicit ListGraph(int n) {
        vertices.resize(n);
    };

    ~ListGraph() override = default;

    void AddEdge(int from, int to, int size) override {
        vertices[from].push_back(std::make_pair(to, size));
        vertices[to].push_back(std::make_pair(from, size));
    };

    int VerticesCount() const override {
        return vertices.size();
    };

    std::vector<std::pair<int, int>> GetNextVertices(int vertex) const override {
        std::vector<std::pair<int, int>> result(vertices[vertex].begin(), vertices[vertex].end());
        return result;
    };

private:
    std::vector<std::vector<std::pair<int, int>>> vertices;
};


bool Relax(std::pair<int, int> &pair, int cour, std::vector<int> &visited) {
    if (visited[pair.first] > visited[cour] + pair.second) {
        visited[pair.first] = visited[cour] + pair.second;
        return true;
    }
    return false;
}

int bfs(const IGraph &graph, int start, int end) {
//не макс инт поскольку есть условие на (visited[child.first] > visited[cour] + child.second) что больше диопазона
    std::vector<int> visited(graph.VerticesCount(), 1000000);
    std::set<std::pair<int, int>> q;
    visited[start] = 0;
    q.insert(std::make_pair(0, start));

    while (!q.empty()) {
        int cour = q.begin()->second;
        q.erase(q.begin());
        std::vector<std::pair<int, int>> children = graph.GetNextVertices(cour);
        for (auto &child: children) {
            if (visited[child.first] > visited[cour] + child.second) {
                visited[child.first] = visited[cour] + child.second;
                q.insert(std::make_pair(visited[child.first], child.first));
            }
        }
    }
    return visited[end];
}



int main() {
    int N, M;
    std::cin >> N >> M;
    ListGraph list = ListGraph(N);

    int from, to, size;

    for (int i = 0; i < M; i++) {
        std::cin >> from >> to >> size;
        list.AddEdge(from, to, size);
    }

    int start, end;
    std::cin >> start >> end;
    std::cout << bfs(list, start, end);
    return 0;
}