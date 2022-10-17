#include <iostream>
using namespace std;

int main(){
    int n; cin >> n;
    int left = 0, right = n, mid;


    while(left <= right){
        mid = (left + right) / 2;

        if(mid * mid == n){
            cout << mid;
            return 0;
        }
        else if(mid * mid < n) left = mid + 1;
        else right = mid - 1;
    }
    cout << left - 1;
}