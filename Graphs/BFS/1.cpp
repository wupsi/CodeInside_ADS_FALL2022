#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main(){

    int n, m; cin >> n >> m;
    vector<int> graph[n];

    for(int i = 0; i < m; i++){
        int u, v; 
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    // BFS

    vector<bool> visited(n, false);
    queue<int> q;

    visited[0] = true;
    q.push(0);

    while(!q.empty()){

        int v = q.front();
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

// [
//     0: [1, 2],
//     1: [2],
//     2: [0, 3],
//     3: [3]
// ]

// []