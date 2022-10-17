#include <iostream>
#include <queue>
using namespace std;

int main(){

    int n; cin >> n;

    for(int i = 0; i < n; i++){
        int Amina, Eldana, dishes, kCal;
        priority_queue<int> pq;
        cin >> Amina >> Eldana >> dishes;

        for(int j = 0; j < dishes; j++){
            cin >> kCal;
            pq.push(kCal);
        }
        for(int j = 0; j < dishes; j++){
            int mx = pq.top();
            Amina -= mx;
            Eldana -= mx;
            pq.pop();
            if(Amina < 0 and Eldana < 0){
                cout << "Tie\n";
                break;
            }
            else if(Eldana < 0){
                cout << "Amina won\n";
                break;
            }
            else if(Amina < 0){
                cout << "Eldana won\n";
                break;
            }
        }
    }
}