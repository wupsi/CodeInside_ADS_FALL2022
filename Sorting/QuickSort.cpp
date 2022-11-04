#include <iostream>
using namespace std;

void QuickSort(int arr[], int left, int right){
    if(left >= right) return;
    int l = left, r = right, pivot = (left + right) / 2;

    // cout << "Before sort: ";
    // for(int i = left; i <= right; i++)
    //     cout << arr[i] << " ";
    // cout << ", pivot: " << pivot;
    // cout << endl;
    while(l <= r){
        while(arr[l] < arr[pivot]) l++;
        while(arr[r] > arr[pivot]) r--;
        if(l <= r){
            swap(arr[l++], arr[r--]);

        }
    }
    // cout << "After sort: ";
    // for(int i = left; i <= right; i++)
    //     cout << arr[i] << " ";
    // cout << endl;

    QuickSort(arr, left, r);
    QuickSort(arr, l, right);
}

int main(){

    int n; cin >> n;
    int arr[n];

    for(int i = 0; i < n; i++)
        cin >> arr[i];

    QuickSort(arr, 0, n - 1);

    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";
}