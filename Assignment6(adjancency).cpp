#include <iostream>
using namespace std;

class Graph {
    int adj[20][20], visited[20];
    int n;

public:
    void create();
    void display();
    void bfs(int start);
    void dfs(int start);
    void dfsUtil(int v);
};

void Graph::create() {
    cout << "Enter number of vertices: ";
    cin >> n;
    cout << "Enter adjacency matrix (0 or 1):\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> adj[i][j];
        }
    }
}

void Graph::display() {
    cout << "Adjacency Matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << adj[i][j] << " ";
        }
        cout << endl;
    }
}

void Graph::bfs(int start) {
    int queue[20], front = 0, rear = 0;
    for (int i = 0; i < n; i++)
        visited[i] = 0;

    cout << "BFS: ";
    queue[rear++] = start;
    visited[start] = 1;

    while (front < rear) {
        int curr = queue[front++];
        cout << curr << " ";

        for (int i = 0; i < n; i++) {
            if (adj[curr][i] == 1 && visited[i] == 0) {
                queue[rear++] = i;
                visited[i] = 1;
            }
        }
    }
    cout << endl;
}

void Graph::dfsUtil(int v) {
    cout << v << " ";
    visited[v] = 1;

    for (int i = 0; i < n; i++) {
        if (adj[v][i] == 1 && visited[i] == 0) {
            dfsUtil(i);
        }
    }
}

void Graph::dfs(int start) {
    for (int i = 0; i < n; i++)
        visited[i] = 0;

    cout << "DFS: ";
    dfsUtil(start);
    cout << endl;
}

int main() {
    Graph g;
    int choice, start;

    do {
        cout << "\n--- MENU ---\n";
        cout << "1. Create Graph\n";
        cout << "2. Display Graph\n";
        cout << "3. BFS\n";
        cout << "4. DFS\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                g.create();
                break;
            case 2:
                g.display();
                break;
            case 3:
                cout << "Enter start vertex (0 to n-1): ";
                cin >> start;
                g.bfs(start);
                break;
            case 4:
                cout << "Enter start vertex (0 to n-1): ";
                cin >> start;
                g.dfs(start);
                break;
            case 5:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice!\n";
        }
    } while (choice != 5);

    return 0;
}
