#ifndef UNTITLED_ARCGRAPH_H
#define UNTITLED_ARCGRAPH_H

#include "../IGraph.h"
#include <unordered_set>

class ArcGraph : public IGraph {
public:
    explicit ArcGraph(const IGraph &graph);
    ~ArcGraph() override = default;
    void AddEdge(int from, int to) override;
    int VerticesCount() const override;
    std::vector<int> GetNextVertices(int vertex) const override;
    std::vector<int> GetPrevVertices(int vertex) const override;

private:
    std::vector<std::pair<int, int>> vertices;
};

#endif //UNTITLED_ARCGRAPH_H
