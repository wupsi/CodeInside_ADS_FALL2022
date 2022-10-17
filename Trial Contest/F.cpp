#include <iostream>
using namespace std;

bool check(int mid, int arr[], int n, int days){
    int cnt = 1, sum = 0;

    for(int i = 0; i < n; i++){
        sum += arr[i];
        if(sum >= mid) cnt++, sum = arr[i];
    }

    return cnt <= days;
}

int main(){

    int n, days, left = 0, right = 0, mid, result; 
    cin >> n >> days;
    int arr[n];

    for(int i = 0; i < n; i++){
        cin >> arr[i];
        left = max(left, arr[i]);
        right += arr[i];
    }

    while(left <= right){
        mid = (left + right);

        if(check(mid, arr, n, days)) result = mid, right = mid - 1;
        else left = mid + 1;
    }

    cout << result;
}