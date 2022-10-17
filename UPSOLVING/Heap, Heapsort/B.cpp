#include <iostream>
using namespace std;

bool isMinHeap(int arr[], int size, int i){
    if(2 * i + 2 > size) return true;

    bool left = (arr[i] <= arr[2 * i + 1]) and isMinHeap(arr, size, 2 * i + 1);
    bool right = (2 * i + 2 == size) or (arr[i] <= arr[2 * i + 2] and isMinHeap(arr, size, 2 * i + 2));

    return left and right;
}

int main(){
    
    int n, x; cin >> n; 
    int arr[n];

    for(int i = 0; i < n; i++)
        cin >> arr[i];

    cout << (isMinHeap(arr, n, 0) ? "This array represents min-Heap." : "This array doesn't represents min-Heap.");
}