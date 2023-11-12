#include <iostream>
#include <list>
#include <utility>
#include <queue>
#include <array>

using namespace std;

// Unweighted, Undirected
void add_edge(list<int> adjList[], int v, int u) {
    adjList[v].push_back(u);
    adjList[u].push_back(v);
}

// Weighted, Undirected
void add_edge(list<pair<int, int>> adjList[], int v, int u, int w) {
    adjList[v].push_back(make_pair(u, w));
    adjList[u].push_back(make_pair(v, w));
}

// UnWeighted, Directed
void dir_add_edge(list<int> adjList[], int v, int u) {
    adjList[v].push_back(u);
} 

// Weighted, Directed
void dir_add_edge(list<pair<int, int>> adjList[], int v, int u, int w) {
    adjList[v].push_back(make_pair(u, w));
}

void printAdjList(list<int> adjList[], int V) {
    for (int i = 0; i < V; i++) {
        cout << "Adjacency list of vertex " << i << ": ";
        for (auto it = adjList[i].begin(); it != adjList[i].end(); it++) {
            cout << *it << "->";
        }
        cout << "null\n";
    }
}

void printWeighAdjList(list<pair<int,int>> adjList[], int V) {
    for (int i = 0; i < V; i++) {
        cout << "Adjacency list of vertex " << i << ": ";
        for (auto it = adjList[i].begin(); it != adjList[i].end(); it++) {
            cout << "("<< it->first << ":" << it->second << ")" << "->";
        }
        cout << "null\n";
    }
}

void bfs(list<int> adjList[], int start, int V) {
    queue<int> adjQueue;
    vector<bool> visited(V, false);
    
    adjQueue.push(start);
    visited[start] = true;

    while (!adjQueue.empty()) {
        int cur_vertex = adjQueue.front();
        adjQueue.pop();
        cout << cur_vertex << " ";
        for (auto adj : adjList[cur_vertex]) {
            if (!visited[adj]) {
                adjQueue.push(adj);
                visited[adj] = true;
            }
        }
    }
    cout <<"\n";
}

int main() {
    std::cout << "Welcome to graph with Adjacency List!\n";
    int vertices = 4;
    // Undirected, Unweighted
    list<int> adjList[vertices];
    add_edge(adjList, 0, 1);
    add_edge(adjList, 1, 2);
    add_edge(adjList, 2, 3);
    add_edge(adjList, 3, 0);
    cout << "----UnWeighted, Undirected Graph----\n";
    printAdjList(adjList, vertices);

    // Undirected, Weighted
    list<pair<int, int>> weighAdjList[vertices];
    add_edge(weighAdjList, 0, 1, 20);
    add_edge(weighAdjList, 1, 2, 10);
    add_edge(weighAdjList, 2, 3, 30);
    add_edge(weighAdjList, 3, 0, 15);
    cout << "----Weighted, Undirected Graph----\n";
    printWeighAdjList(weighAdjList, vertices);

    // directed, UnWeighted
    list<int> dirAdjList[vertices];
    dir_add_edge(dirAdjList, 0, 1);
    dir_add_edge(dirAdjList, 1, 2);
    dir_add_edge(dirAdjList, 2, 3);
    dir_add_edge(dirAdjList, 3, 0);
    cout << "----UnWeighted, directed Graph----\n";
    printAdjList(dirAdjList, vertices);

    // directed, Weighted
    list<pair<int, int>> dirWeighAdjList[vertices];
    dir_add_edge(dirWeighAdjList, 0, 1, 20);
    dir_add_edge(dirWeighAdjList, 1, 2, 20);
    dir_add_edge(dirWeighAdjList, 2, 3, 30);
    dir_add_edge(dirWeighAdjList, 3, 0, 15);
    cout << "----Weighted, directed Graph----\n";
    printWeighAdjList(dirWeighAdjList, vertices);

    // BFS
    cout << "----BFS----\n";
    bfs(adjList, 0, vertices);
    bfs(adjList, 1, vertices);
    
    return  0;
}

/*
    0--------1   adj of 0 = 1 & 3
    |        |   adj of 1 = 0 & 2
    |        |   adj of 2 = 1 & 3
    |        |   adj of 3 = 0 & 2
    3--------2

*/
