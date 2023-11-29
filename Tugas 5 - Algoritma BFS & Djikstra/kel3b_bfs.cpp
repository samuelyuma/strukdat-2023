#include <iostream>
#include <queue>
#define MAX 100

using namespace std;

bool adj[MAX][MAX]; // Matriks adjacency
bool visited[MAX]; // Array untuk menandai simpul yang telah dikunjungi

// Fungsi untuk menambahkan edge ke graf
void addEdge(int v, int w) {
    adj[v][w] = true;
}

// Fungsi BFS
void BFS(int s, int V) {
    for(int i = 0; i < V; i++)
        visited[i] = false; // Menandai semua simpul sebagai belum dikunjungi

    queue<int> queue;

    visited[s] = true; // Menandai simpul awal sebagai dikunjungi
    queue.push(s); // Memasukkan simpul awal ke dalam queue

    while(!queue.empty()) {
        s = queue.front();
        queue.pop();

        cout << "Visited: ";
        for(int i = 0; i < V; i++) {
            if(visited[i]) {
                cout << i << " ";
            }
        }
        cout << endl;

        cout << "Queue: ";
        for(int i = 0; i < V; i++) {
            if(adj[s][i] && !visited[i]) {
                cout << i << " ";
            }
        }
        cout << endl;

        // Mengunjungi semua simpul yang berdekatan dengan simpul s
        for(int i = 0; i < V; i++) {
            if(adj[s][i] && !visited[i]) {
                queue.push(i);
                visited[i] = true;
            }
        }
    }
}

int main() {
    int V = 5;
    addEdge(0, 1);
    addEdge(0, 2);
    addEdge(1, 3);
    addEdge(2, 4);
    addEdge(3, 4);

    cout << "Breadth First Traversal (dimulai dari simpul 0):" << endl;
    BFS(0, V);

    return 0;
}
