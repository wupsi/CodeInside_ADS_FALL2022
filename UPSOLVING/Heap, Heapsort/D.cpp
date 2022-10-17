#include <iostream>
using namespace std;

void heapify(int arr[], int size, int root){
    int largest = root;   
    int left = 2 * root + 1;
    int right = 2 * root + 2;

    if(left < size and arr[left] > arr[largest])
        largest = left;
    if(right < size and arr[right] > arr[largest])
        largest = right;

    if(largest != root){
        swap(arr[root], arr[largest]);
        heapify(arr, size, largest);
    }
}

void heapSort(int arr[], int size){
    for(int i = size / 2 - 1; i >= 0; i--)
        heapify(arr, size, i);

    for(int i = size - 1; i >= 0; i--){
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

int main(){

    int n; cin >> n;
    int arr[n];

    for(int i = 0; i < n; i++)
        cin >> arr[i];

    heapSort(arr, n);

    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";
}