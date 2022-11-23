#include <iostream>
#include <vector>
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

    for(int i = 0; i < n; i++){
        cout << i << ": ";
        for(auto j : graph[i])
            cout << j << " ";
        cout << endl;
    }
}

// [
//     0: [1, 4],
//     1: [0, 2, 3, 4],
//     2: [1, 3],
//     3: [1, 2, 4],
//     4: [0, 1, 3]
// ]