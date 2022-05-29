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

    virtual void AddEdge(int from, int to) = 0;

    virtual int VerticesCount() const = 0;

    virtual std::vector<int> GetNextVertices(int vertex) const = 0;

};

class ListGraph : public IGraph {
public:
    explicit ListGraph(int n) {
        vertices.resize(n);
    };

    ~ListGraph() override = default;

    void AddEdge(int from, int to) override {
        vertices[from].push_back(to);
        vertices[to].push_back(from);
    };

    int VerticesCount() const override {
        return vertices.size();
    };

    std::vector<int> GetNextVertices(int vertex) const override {
        std::vector<int> result(vertices[vertex].begin(), vertices[vertex].end());
        return result;
    };

private:
    std::vector<std::vector<int>> vertices;
};


int bfs(const IGraph &graph, int start, int end) {
    //INT32_MAX - 1 для условия r[child] > r[cur] + 1
    std::vector<int> r(graph.VerticesCount(), INT32_MAX - 1);
    std::vector<int> k(graph.VerticesCount(), 0);

    std::queue<int> queue;
    queue.push(start);
    r[start] = 0;
    k[start] = 1;

    while (!queue.empty()){
        int cur = queue.front();
        queue.pop();

        std::vector<int> children = graph.GetNextVertices(cur);
        for (auto child: children) {
            if (r[child] == r[cur] + 1){
                k[child] += k[cur];
            } else if (r[child] > r[cur] + 1){
                r[child] = r[cur] + 1;
                k[child] = k[cur];
                queue.push(child);
            }
        }
    }
    return k[end];
}



int main() {
    int N, M;
    std::cin >> N >> M;
    ListGraph list = ListGraph(N);

    int from, to, size;

    for (int i = 0; i < M; i++) {
        std::cin >> from >> to;
        list.AddEdge(from, to);
    }

    int start, end;
    std::cin >> start >> end;
    std::cout << bfs(list, start, end);
    return 0;
}
