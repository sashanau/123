#include "SetGraph.h"

SetGraph::SetGraph(int vertices_count) {
    vertices.resize(vertices_count);
}

SetGraph::SetGraph(const IGraph &graph) {
    vertices.resize(graph.VerticesCount());
    for (int i = 0; i < graph.VerticesCount(); i++) {
        std::vector<int> tmp = graph.GetNextVertices(i);
        for (auto &vert: tmp) {
            vertices[i].insert(vert);
        }
    }
}

void SetGraph::AddEdge(int from, int to) {
    vertices[from].insert(to);
}

int SetGraph::VerticesCount() const {
    return vertices.size();
}

std::vector<int> SetGraph::GetNextVertices(int vertex) const {
    std::vector<int> result;
    for (auto vert: vertices[vertex]) {
        result.push_back(vert);
    }
    return result;
}

std::vector<int> SetGraph::GetPrevVertices(int vertex) const {
    std::vector<int> result;
    for (int i = 0; i < vertices.size(); i++)
        for (auto vert : vertices[i]) {
            if (vert == vertex)
                result.push_back(i);
        }
    return result;
}
