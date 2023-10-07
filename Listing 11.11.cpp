#include <iostream>
#include <vector>
#include <queue>
using namespace std;
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

    void addEdge(int i, int j, int w);
    void deleteEdge(int i, int j);
    void inputGraph();
    void printGraph();
    void BFS(int a);
    // Other member functions (DFS related) are omitted for simplicity
};

NonWeightedGraph::NonWeightedGraph(int n) {
    for (int i = 1; i <= n; i++)
        adj[i] = NULL;
    size = n;
}

// Implementations for other member functions (addEdge, deleteEdge, inputGraph, printGraph, etc.) are omitted for simplicity.
// NonWeightedGraph class definition and other member functions ...

void NonWeightedGraph::inputGraph() {
    NWNode* ptr, * last;
    int i, j, m, val;

    for (i = 1; i <= size; i++) {
        last = NULL;
        cout << "\nNumber of nodes in the adjacency list of node " << i << ": ";
        cin >> m;

        for (j = 1; j <= m; j++) {
            cout << "Enter node i" << j << ": ";
            cin >> val;

            ptr = new NWNode;
            ptr->vertex = val;
            ptr->next = NULL;

            if (adj[i] == NULL)
                adj[i] = last = ptr;
            else {
                last->next = ptr;
                last = ptr;
            }
        }
    }
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



// NonWeightedGraph class definition and other member functions ...


// NonWeightedGraph class definition and other member functions ...


// NonWeightedGraph class definition and other member functions ...

void NonWeightedGraph::BFS(int s) {
    int color[MAX] = {WHITE};
    queue<int> q;

    color[s] = GRAY;
    q.push(s);

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        NWNode* ptr = adj[u];
        while (ptr != NULL) {
            int v = ptr->vertex;
            if (color[v] == WHITE) {
                color[v] = GRAY;
                q.push(v);
            }
            ptr = ptr->next;
        }

        color[u] = BLACK;
        cout << u << " ";
    }
}

int main() {
    int n, s;

    cout << "\nEnter the number of nodes in the graph: ";
    cin >> n;

    NonWeightedGraph nwgraph(n);
    nwgraph.inputGraph();

    cout << "\nEnter the source vertex: ";
    cin >> s;

    cout << "\n\nBFS from vertex " << s << " is\n\n";
    nwgraph.BFS(s);

    return 0;
}

