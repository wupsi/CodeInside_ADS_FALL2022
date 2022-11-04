#include <iostream>
using namespace std;

void merge(int mainArr[], int left, int mid, int right){
    int leftSize = mid - left + 1, rightSize = right - mid;
    int leftArray[leftSize], rightArray[rightSize];

    for(int i = 0; i < leftSize; i++)
        leftArray[i] = mainArr[left + i];

    for(int i = 0; i < rightSize; i++)
        rightArray[i] = mainArr[mid + 1 + i];

    int i = 0, j = 0, index = left;

    while(i < leftSize and j < rightSize){
        if(leftArray[i] <= rightArray[j]) mainArr[index++] = leftArray[i++];
        else mainArr[index++] = rightArray[j++];
    }

    while(i < leftSize) mainArr[index++] = leftArray[i++];
    while(j < rightSize) mainArr[index++] = rightArray[j++];
}

void MergeSort(int arr[], int left, int right){
    if(left >= right) return;
    int mid = (left + right) / 2;
    MergeSort(arr, left, mid);
    MergeSort(arr, mid + 1, right);
    merge(arr, left, mid, right);
}

int main(){

    int n; cin >> n;
    int arr[n];

    for(int i = 0; i < n; i++)
        cin >> arr[i];

    MergeSort(arr, 0, n - 1);

    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";
}