#include <iostream>
#include <vector>

/* Topic 7: Processing Graph Data (Adjacency Matrix Mapping)
   Uses standard vectors to build a dynamic grid map of network relationships.
*/
class NetworkGraph {
private:
    int totalVertices;
    std::vector<std::vector<int>> adjacencyMatrix;

public:
    // Dynamic constructor initializing a matrix based on requested vertices
    NetworkGraph(int vertices) : totalVertices(vertices) {
        adjacencyMatrix.resize(vertices, std::vector<int>(vertices, 0));
    }

    // Connects two nodes with an edge connection pathway
    void addNetworkLink(int source, int destination) {
        if (source < totalVertices && destination < totalVertices) {
            adjacencyMatrix[source][destination] = 1;
            adjacencyMatrix[destination][source] = 1; // Bidirectional edge setup
        }
    }

    void renderTopology() {
        std::cout << "     ";
        for (int i = 0; i < totalVertices; i++) std::cout << "Node[" << i << "] ";
        std::cout << "\n";

        for (int i = 0; i < totalVertices; i++) {
            std::cout << "Node[" << i << "]  ";
            for (int j = 0; j < totalVertices; j++) {
                std::cout << adjacencyMatrix[i][j] << "       ";
            }
            std::cout << "\n";
        }
    }
};

int main() {
    std::cout << "--- Network Graph Topological Mapping (C++) ---\n\n";
    NetworkGraph graph(4); // Instantiate a graph with 4 dynamic nodes

    graph.addNetworkLink(0, 1);
    graph.addNetworkLink(0, 2);
    graph.addNetworkLink(1, 3);
    graph.addNetworkLink(2, 3);

    graph.renderTopology();
    return 0;
}
