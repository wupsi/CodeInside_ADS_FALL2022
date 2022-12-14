Сложность алгоритма


1. Константное время - O(1)
2. Логарифмическое время - O(log(n))
3. Линейное время - O(n)
4. Квадратичное время - O(n^2)
5. Линейно-логарифмическое - O(nlog(n))

n - размер массива


int arr[n] = {1, 2, 3, 4, 5, 7, 9, 13, 21, 34, 37, 50};
cout << arr[k] << endl;                                     // O(1)
---------------------------------------------------------------------

int arr[n] = {1, 2, 3, 4, 5, 7, 9, 13, 21, 34, 37, 50};
target = 13;
BinarySearch(arr, 0, n - 1, target);                        // O(log(n))
---------------------------------------------------------------------

int arr[n] = {1, 2, 3, 4, 5, 7, 9, 13, 21, 34, 37, 50};
int sum = 0

for(int i = 0; i < n; i++)                                  // O(n)
    sum += arr[i];
---------------------------------------------------------------------

int arr1[n] = {1, 2, 3, 4, 5};
int arr2[n] = {1, 3, 4, 7, 8};

for(int i = 0; i < n; i++){                                 // O(n^2)
    for(int j = 0; j < n; j++){
        cout << arr1[i] << " " << arr2[j] << endl;
    }
    cout << endl;
}
---------------------------------------------------------------------

int arr1[n] = {1, 2, 3, 4, 5};
int arr2[n] = {1, 3, 4, 7, 8};

for(int i = 0; i < n; i++){                                 // O(nlog(n))
    cout << (BinarySearch(arr2, 0, n - 1, arr1[i]) != -1 "YES\n" : "NO");
}
---------------------------------------------------------------------
// n = 100
// [1, 100]

// x = 5
// [1, 100]
// 1. 50
// [1, 49]
// 2. 25
// [1, 24]
// 3. 12
// [1, 11]
// 4. 6
// [1, 5]
// 5. 3
// [4, 5]
// 6. 4
// [5]

// 128
// [1, 124]
// 1. (124 + 1) / 2 = 64
// 2. (64 + 1) / 2 = 32
// 3. (32 + 1) / 2 = 16
// 4. (16 + 1) / 2 = 8
// 5. (8 + 1) / 2 = 4
// 6. (4 + 1) / 2 = 2
// 7. (2 + 1) / 2 = 1

// 129
// [1, 129]
// 1. (125 + 1) / 2 = 65
// 2. (65 + 1) / 2 = 33
// 3. (33 + 1) / 2 = 17
// 4. (17 + 1) / 2 = 9
// 5. (9 + 1) / 2 = 5
// 6. (5 + 1) / 2 = 3
// 7. (3 + 1) / 2 = 2
// 8. (2 + 1) / 2 = 1

// 255
// 1. (255 + 1) / 2 = 128
// 2. (128 + 1) / 2 = 64
// 3. (64 + 1) / 2 = 32
// 4. (32 + 1) / 2 = 16
// 5. (16 + 1) / 2 = 8
// 6. (8 + 1) / 2 = 4
// 7. (4 + 1) / 2 = 2
// 8. (2 + 1) / 2 = 1

// log(255) = 8
// log(125) = 8
// log(124) = 7
