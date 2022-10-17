#include <iostream>
using namespace std;

void printArray(int arr[], int n){
    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";
    
    cout << endl;
}

void heapify(int arr[], int size, int root){
    int largest = root, left = 2 * root + 1, right = 2 * root + 2;

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
    for(int i = size / 2 - 1; i >= 0; i--){
        heapify(arr, size, i);
    }
        printArray(arr, size);

    for(int i = size - 1; i >= 0; i--){
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}


int main(){

	int n = 12;
	int arr[n] = {5, 9, 1, 7, 2, 3, 11, 10, 12, 4, 8, 6};
	  
	heapSort(arr, n);
	  
	cout << "Sorted array:\n";
	for(int i = 0; i < n; i++)
		cout << arr[i] << " ";
}