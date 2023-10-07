#include <iostream>
#include <vector>

#define WHITE 0
#define MAX 20
#define GRAY 1
#define BLACK 2

struct NWNode {
    int vertex;
    NWNode* next;
};

class NonWeightedGraph {
protected:
    NWNode* adj[MAX];
    int size;

public:
    NonWeightedGraph(int n);
    ~NonWeightedGraph();

    // Other member functions (addEdge, deleteEdge, inputGraph, printGraph, etc.) are omitted for simplicity.
    void DFSVisit(int u);
    void DFSRecursive(int s);
};

NonWeightedGraph::NonWeightedGraph(int n) {
    for (int i = 1; i <= n; i++)
        adj[i] = NULL;
    size = n;
}
// NonWeightedGraph class definition and other member functions ...

NonWeightedGraph::~NonWeightedGraph() {
    NWNode* temp, * ptr;
    for (int i = 1; i <= size; i++) {
        ptr = adj[i];
        while (ptr != NULL) {
            temp = ptr;
            ptr = ptr->next;
            delete temp;
        }
        adj[i] = NULL;
    }
}

// NonWeightedGraph class definition and other member functions ...


// Implementations for other member functions are omitted for simplicity.

void NonWeightedGraph::DFSVisit(int u) {
    NWNode* ptr;
    int color[MAX] = {WHITE};

    color[u] = GRAY;
    ptr = adj[u];

    while (ptr != NULL) {
        int v = ptr->vertex;
        if (color[v] == WHITE)
            DFSVisit(v);
        ptr = ptr->next;
    }

    std::cout << u << " ";
    color[u] = BLACK;
}

void NonWeightedGraph::DFSRecursive(int s) {
    int color[MAX] = {WHITE};

    for (int i = 1; i <= size; i++) {
        if (color[i] == WHITE)
            DFSVisit(i);
    }
}

int main() {
    int n, s;

    std::cout << "\nEnter number of nodes in the graph: ";
    std::cin >> n;

    NonWeightedGraph nwgraph(n);
    // Assuming the implementation of other member functions (addEdge, deleteEdge, inputGraph, printGraph) is present.

    std::cout << "\nEnter source vertex: ";
    std::cin >> s;

    std::cout << "\nDFS traversal from vertex " << s << " is:\n";
    nwgraph.DFSRecursive(s);

    return 0;
}

