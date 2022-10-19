#include <iostream>
#include <queue>
using namespace std;

int main(){

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    pq.push({7, 0});
    pq.push({4, 1});
    pq.push({-1, 2});
    pq.push({5, 3});
    pq.push({6, 4});
    pq.push({4, 5});

    while(!pq.empty()){
        cout << pq.top().first << " " << pq.top().second << endl;
        pq.pop();        
    }
}