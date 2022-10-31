#include <iostream>
#include <deque>
using namespace std;

int main(){

    int n, x, q, cnt = 0; cin >> n;
    deque<int> dq;

    for(int i = 0; i < n; i++){
        cin >> q;
        if(q == 1){
            cin >> x;
            if(cnt % 2 == 0) dq.push_back(x);
            else dq.push_front(x);
        }
        if(q == 2) cnt++;
    }

    if(cnt % 2 == 1){
        while(!dq.empty()){
            cout << dq.back() << " ";
            dq.pop_back();
        }
    }
    else{
        while(!dq.empty()){
            cout << dq.front() << " ";
            dq.pop_front();
        }
    }
}

// 9
// 1 2
// 1 3
// 2
// 1 4
// 1 5
// 2
// 1 1
// 2
// 1 1

// arr = [1, 5, 4, 2, 3, 1]