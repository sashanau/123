#include "MatrixGraph.h"

MatrixGraph::MatrixGraph(int vertices_count) {
    vertices.resize(vertices_count);
    for (auto& vert : vertices) {
        vert.resize(vertices_count, false);
    }
}

MatrixGraph::MatrixGraph(const IGraph &graph) {
    vertices.resize(graph.VerticesCount());
    for (int i = 0; i < graph.VerticesCount(); i++) {
        vertices[i].resize(graph.VerticesCount(), false);
        for(auto &vert : graph.GetNextVertices(i)){
            vertices[i][vert] = true;
        }
    }
}

void MatrixGraph::AddEdge(int from, int to) {
    vertices[from][to] = true;
}

int MatrixGraph::VerticesCount() const {
    return vertices.size();
}

std::vector<int> MatrixGraph::GetNextVertices(int vertex) const {
    std::vector<int> result;
    for(int i = 0; i < vertices[vertex].size(); i++){
        if (vertices[vertex][i]){
            result.push_back(i);
        }
    }
    return result;
}

std::vector<int> MatrixGraph::GetPrevVertices(int vertex) const {
    std::vector<int> result;

    for(int i = 0; i < vertices.size(); i++){
        if (vertices[i][vertex]){
            result.push_back(i);
        }
    }
    return result;
}
