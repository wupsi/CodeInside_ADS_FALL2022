#include <iostream>
using namespace std;

int limit = 2147483647;

struct deque{

    int l, r;
    int arr[100000];

    deque(){
        l = 50000;
        r = 50000;
    }

    void push_back(int x){
        arr[r++] = x;
    }

    void push_front(int x){
        arr[--l] = x;
    }

    int back(){
        return (empty() ? limit : arr[r - 1]);
    }

    int front(){
        return (empty() ? limit : arr[l]);
    }

    void pop_back(){
        if(!empty()) r--;
    }

    void pop_front(){
        if(!empty()) l++;
    }

    int size(){
        return r - l;
    }

    bool empty(){
        return r == l;
    }

    void clear(){
        l = 50000, r = 50000;            
    }
};

int main(){

    deque dq;
    string command;

    while(cin >> command){
        if(command == "push_front"){
            int x; cin >> x;
            dq.push_front(x);
            cout << "ok\n";
        }

        if(command == "push_back"){
            int x; cin >> x;
            dq.push_back(x);
            cout << "ok\n";
        }

        if(command == "pop_front"){
            if(dq.front() == limit) cout << "error\n";
            else cout << dq.front() << endl;
            if(!dq.empty()) dq.pop_front();
        }

        if(command == "pop_back"){
            if(dq.back() == limit) cout << "error\n";
            else cout << dq.back() << endl;
            if(!dq.empty()) dq.pop_back();
        }

        if(command == "front"){
            if(dq.front() == limit) cout << "error\n";
            else cout << dq.front() << endl;
        }

        if(command == "back"){
            if(dq.back() == limit) cout << "error\n";
            else cout << dq.back() << endl;
        }

        if(command == "size")
            cout << dq.size() << endl;

        if(command == "clear"){
            dq.clear();
            cout << "ok\n";
        }

        if(command == "exit"){
            cout << "bye";
            return 0;
        }
    }
}


// Гоблины и Шаманы
// 12
// + 1                      [1]                              [1], []
// + 2                      [1, 2]                           [2], [1]
// -                        [2], Вывод: 1                    [2], []
// + 3                      [2, 3]                           [3], [2]
// + 4                      [2, 3, 4]                        [3, 4], [2]
// + 5                      [2, 3, 4, 5]                     [4, 5], [2, 3]
// * 6                      [2, 3, 6, 4, 5]                  [4, 5], [2, 3, 6]
// -                        [3, 6, 4, 5], Вывод: 2           [4, 5], [3, 6]
// -                        [6, 4, 5], Вывод: 3              [4, 5], [6]
// * 7                      [6, 7, 4, 5]                     [4, 5], [6, 7]
// -                        [7, 4, 5], Вывод: 6              [4, 5], [7]
// -                        [4, 5], Вывод: 7                 [4], [5]
