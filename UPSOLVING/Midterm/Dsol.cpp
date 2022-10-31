#include<iostream>
using namespace std;
int main(){
    int n; cin>>n;
    int cnt=0;
    for(int i=2;i<=n;i++){
        if(n%i==0){
            cnt++;
            cout << i << " ";
            while(n%i==0){
                n=n/i;
            }
        }
        
    }
    cout<<cnt;
}