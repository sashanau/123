#ifndef UNTITLED_LISTGRAPH_H
#define UNTITLED_LISTGRAPH_H

#include "../IGraph.h"

class ListGraph : public IGraph {

public:
    explicit ListGraph(int vertices_count);
    explicit ListGraph(const IGraph &graph);
    ~ListGraph() override;
    void AddEdge(int from, int to) override;
    int VerticesCount() const override;
    std::vector<int> GetNextVertices(int vertex) const override;
    std::vector<int> GetPrevVertices(int vertex) const override;

private:
    std::vector<std::vector<int>> vertices;
};

#endif //UNTITLED_LISTGRAPH_H
