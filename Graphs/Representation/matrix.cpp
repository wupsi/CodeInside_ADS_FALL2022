#include <iostream>
#include <vector>
using namespace std;

int main(){

    int n, m; cin >> n >> m;
    vector<int> row(n, 0);
    vector<vector<int>> graph(n, row);

    for(int i = 0; i < m; i++){
        int u, v; 
        cin >> u >> v;
        graph[u][v] = 1;
        graph[v][u] = 1;
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << graph[i][j] << " ";
        }
        cout << endl;
    }
}

// [
//     [0, 0, 0, 0, 0],
//     [0, 0, 0, 0, 0],
//     [0, 0, 0, 0, 0],
//     [0, 0, 0, 0, 0],
//     [0, 0, 0, 0, 0]
// ]