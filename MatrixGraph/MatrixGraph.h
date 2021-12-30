#ifndef UNTITLED_MATRIXGRAPH_H
#define UNTITLED_MATRIXGRAPH_H

#include "../IGraph.h"

class MatrixGraph : public IGraph {

public:
    explicit MatrixGraph(int vertices_count);
    explicit MatrixGraph(const IGraph &graph);
    ~MatrixGraph() override = default;
    void AddEdge(int from, int to) override;
    int VerticesCount() const override;
    std::vector<int> GetNextVertices(int vertex) const override;
    std::vector<int> GetPrevVertices(int vertex) const override;

private:
    std::vector<std::vector<bool>> vertices;
};

#endif //UNTITLED_MATRIXGRAPH_H
