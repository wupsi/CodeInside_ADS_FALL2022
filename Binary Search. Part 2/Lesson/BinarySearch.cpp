#include <iostream>
using namespace std;

int BinarySearch(int arr[], int left, int right, int target){
    int left = 0, right = n - 1, mid;
    if(target > arr[right] or target < arr[left]) return -1;

    while(left <= right){
        mid = (left + right) / 2;
        if(arr[mid] > target) right = mid - 1;
        else if(arr[mid] < target) left = mid + 1;
        else return mid;
    }
    return -1;
}

int main(){

    int n = 12, target = 14;
    int arr[n] = {1, 2, 3, 4, 5, 7, 9, 13, 21, 34, 37, 50};

    cout << (BinarySearch(arr, 0, n - 1, target) != -1 ? "YES" : "NO");
}

// --------------------------------------------------------------
//  l              m                      r
//  v              v                      v
// [1, 2, 3, 4, 5, 7, 9, 13, 21, 34, 37, 50]

// n = 12;
// --------------------------------------------------------------
// Iteration 1:
// target = 13;
// left = 0;
// right = 11;
// mid = 5;
// arr[mid] < target -> 7 < 14 -> left = mid + 1 = 6;
// --------------------------------------------------------------
// Iteration 2:
// mid = (left + right) / 2 = (6 + 11) / 2 = 17 / 2 = 8;
// [9, 13, 21, 34, 37, 50]
// arr[mid] > target -> 21 > 14 -> right = 8 - 1 = 7;
// --------------------------------------------------------------
// Iteration 3:
// mid = 13 / 2 = 6;
// arr[mid] < target -> 9 < 14 -> left = mid + 1 = 7;
// --------------------------------------------------------------
// Iteration 4:
// mid = 14 / 2 = 7;
// arr[mid] < target -> 13 < 14 -> left = mid + 1 = 8;
// --------------------------------------------------------------
// Iteration 5:
// left = 8;
// right = 7;