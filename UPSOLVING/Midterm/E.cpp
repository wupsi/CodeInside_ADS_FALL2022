#include <iostream>
#include <vector>
using namespace std;

struct Stack{
private:
    vector<pair<int, int>> v;

public:

    void push(int x){
        if(v.empty()) v.push_back({x, x});
        else v.push_back({x, max(x, v.back().second)});
    }

    void pop(){
        if(!v.empty()) v.pop_back();
    }

    int top(){
        if(v.empty()) return 0;
        return v.back().first;
    }

    int getMax(){
        if(v.empty()) return 0;
        return v.back().second;
    }
};

int main(){

    int n, x, y; cin >> n;
    string q;
    Stack st;

    for(int i = 0; i < n; i++){
        cin >> q;
        if(q == "add"){
            cin >> x;
            st.push(x);
        }

        if(q == "delete"){
            st.pop();
        }

        if(q == "getcur"){
            y = st.top();
            (y == 0) ? cout << "error\n" : cout << y << endl;
        }

        if(q == "getmax"){
            y = st.getMax();
            (y == 0) ? cout << "error\n" : cout << y << endl;
        }
    }
}

// vector<pair<int, int>> v;

// 4
// 43
// 3
// 2
// 5
// 51
// 42

// [[43, 43], [3, 43], [2, 43], [5, 43], [51, 51], [42, 51]]