#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void bfs(vector<int> graph[], int V, int v){
    vector<bool> visited(V, false);
    queue<int> q;

    visited[v] = true;
    q.push(v);

    while(!q.empty()){

        v = q.front();
        cout << v << " ";

        for(int i = 0; i < graph[v].size(); i++){
            int u = graph[v][i];
            if(!visited[u])
                visited[u] = true, 
                q.push(u);
        }

        q.pop();
    }

}

int main(){

    int n, m; cin >> n >> m;
    vector<int> graph[n];

    for(int i = 0; i < m; i++){
        int u, v; 
        cin >> u >> v;
        graph[u].push_back(v);          // Двустороннее ребро
        graph[v].push_back(u);
    }

    bfs(graph, n, 1);
}

// [
//     0: [1, 2],
//     1: [2],
//     2: [0, 3],
//     3: [3]
// ]

// []