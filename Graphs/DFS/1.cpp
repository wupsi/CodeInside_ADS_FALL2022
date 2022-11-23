#include <iostream>
#include <vector>
using namespace std;

void dfs(vector<int> graph[], vector<bool> &visited, int v){
    visited[v] = true;
    cout << v << " ";

    for(int i = 0; i < graph[v].size(); i++){
        int u = graph[v][i];
        if(!visited[u])
            dfs(graph, visited, u);
    }
}

int main(){

    int n, m; cin >> n >> m;
    vector<int> graph[n];

    for(int i = 0; i < m; i++){
        int u, v; 
        cin >> u >> v;
        graph[u].push_back(v);          // Одностороннее ребро
    }

    vector<bool> visited(n, false);
    dfs(graph, visited, 1);
}

// [
//     0: [1, 2],
//     1: [2],
//     2: [0, 3],
//     3: [3]
// ]
