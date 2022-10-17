#include <iostream>
#include <queue>
using namespace std;

int main(){
    int n, k, x; cin >> n >> k;
    priority_queue<int> pq;

    for(int i = 0; i < n; i++){
        cin >> x;
        pq.push(x);
    }
    k--;
    while(k--) pq.pop();

    cout << pq.top();
}