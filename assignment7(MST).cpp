#include <iostream>
using namespace std;

#define INF 9999  // Infinity value

class Graph {
    int n;              // Number of vertices
    int adj[10][10];    // Adjacency matrix

public:
    void create();
    void prims();
};

void Graph::create() {
    cout << "Enter number of vertices: ";
    cin >> n;
    cout << "Enter adjacency matrix (0 if no edge):\n";

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> adj[i][j];
            if (adj[i][j] == 0)  // If no edge, set to INF
                adj[i][j] = INF;
        }
    }
}

void Graph::prims() {
    int selected[10] = {0};  // Track selected vertices
    selected[0] = 1;         // Start from vertex 0

    int edge_count = 0;
    int total_cost = 0;

    cout << "Edges in MST:\n";

    while (edge_count < n - 1) {
        int min = INF;
        int x = 0, y = 0;

        for (int i = 0; i < n; i++) {
            if (selected[i]) {
                for (int j = 0; j < n; j++) {
                    if (!selected[j] && adj[i][j] < min) {
                        min = adj[i][j];
                        x = i;
                        y = j;
                    }
                }
            }
        }

        cout << x << " - " << y << " : " << adj[x][y] << endl;
        total_cost += adj[x][y];
        selected[y] = 1;
        edge_count++;
    }

    cout << "Total cost of MST: " << total_cost << endl;
}

int main() {
    Graph g;
    g.create();
    g.prims();
    return 0;
}
