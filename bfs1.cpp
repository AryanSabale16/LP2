#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define MAX 100

int adjMatrix[MAX][MAX];
bool visited[MAX];
int n;

void BFS(int start) {
    queue<int> q;
    visited[start] = true;
    q.push(start);

    while (!q.empty()) {
        int v = q.front();
        q.pop();
        cout << v << " ";

        for (int i = 0; i < n; i++) {
            if (adjMatrix[v][i] == 1 && !visited[i]) {
                visited[i] = true;
                q.push(i);
            }
        }
    }
}

int main() {
    int edges;
    cout << "Enter number of vertices: ";
    cin >> n;

    cout << "Enter number of edges: ";
    cin >> edges;

    for (int i = 0; i < n; i++) {
        visited[i] = false;
        for (int j = 0; j < n; j++) {
            adjMatrix[i][j] = 0;
        }
    }

    cout << "Enter edges (format: source destination):" << endl;
    for (int i = 0; i < edges; i++) {
        int u, v;
        cin >> u >> v;
        adjMatrix[u][v] = 1;
        adjMatrix[v][u] = 1; 
    }

    int startVertex;
    cout << "Enter starting vertex for BFS: ";
    cin >> startVertex;

    cout << "BFS traversal starting from vertex " << startVertex << ": ";
    BFS(startVertex);

    return 0;
}
