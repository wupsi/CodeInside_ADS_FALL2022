#include<iostream>
#include<vector>
using namespace std;

bool isPrime(int n){

    for (int i = 3; i * i <= n; i += 2)
        if (n % i == 0) return false;

    return true;
}

int main(){

    int n, cnt = 0; cin >> n;
    for(int i = 3; i <= n / 2; i += 2)
        if(n % i == 0){
            if(isPrime(i)){
                cnt++;
            }
        }

    if(n >= 2) cnt++;
    cout << cnt;
}
