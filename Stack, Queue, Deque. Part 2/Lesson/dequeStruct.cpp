#include <iostream>
using namespace std;

struct deque{

    int l, r;
    int arr[100000];

    deque(){
        l = 50000;
        r = 50000;
    }

    void push_back(int x){
        arr[r] = x;
        r++;
    }

    void push_front(int x){
        l--;
        arr[l] = x;
    }

    int back(){
        return arr[r - 1];
    }

    int front(){
        return arr[l];
    }

    void pop_back(){
        r--;
    }

    void pop_front(){
        l++;
    }

    int size(){
        return r - l;
    }

    bool empty(){
        return r == l;
    }

    void clear(){
        l = 50000, r = 50000;
    }
};

int main(){

    deque dq;

    dq.push_back(1);                // [1]
    dq.push_back(2);                // [1, 2]
    dq.push_back(3);                // [1, 2, 3]
    dq.push_front(4);               // [4, 1, 2, 3]
    dq.push_front(5);               // [5, 4, 1, 2, 3]
    dq.push_front(6);               // [6, 5, 4, 1, 2, 3]

    cout << "Deque size: " << dq.size() << endl;                    // Вывод: 6
    cout << "Deque front: " << dq.front() << endl;                  // Вывод: 6
    cout << "Deque back: " << dq.back() << endl;                    // Вывод: 3
    cout << "Deque is empty? " << (dq.empty() ? "YES\n" : "NO\n");  // Вывод: NO

    dq.pop_front();                                                 // [5, 4, 1, 2, 3]
    dq.pop_back();                                                  // [5, 4, 1, 2]
    cout << "Deque front: " << dq.front() << endl;                  // Вывод: 5
    cout << "Deque back: " << dq.back() << endl;                    // Вывод: 2

    dq.pop_front();                                                 // [4, 1, 2]
    dq.pop_back();                                                  // [4, 1]
    cout << "Deque front: " << dq.front() << endl;                  // Вывод: 4
    cout << "Deque back: " << dq.back() << endl;                    // Вывод: 1

    dq.pop_back();                                                  // [4]
    cout << "Deque front: " << dq.front() << endl;                  // Вывод: 4
    dq.pop_back();                                                  // []

    cout << "Deque is empty? " << (dq.empty() ? "YES\n" : "NO\n");  // Вывод: YES

}

// Основные функции
// push_back(x)        - Добавление в конец
// push_front(x)       - Добавление в начало
// back()              - Возвращает конечный элемент
// front()             - Возвращает начальный элемент
// pop_back()          - Удаляет конечный элемент
// pop_front()         - Удаляет начальный элемент
// size()              - Возвращает размер
// empty()             - Проверяет, является ли дек пустым

//                                            l                       r
//                                            v                       v
// front -> [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, x, x, x, x, x, x, x, x, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0] <- back

// Указатели на середину массива
// l = 50000
// r = 50000

// ____________________________________________

// push_back(x);
//     1. arr[r] = x;
//     2. r++;
// ____________________________________________

// push_front(x);
//     1. l--;
//     2. arr[l] = x
// ____________________________________________

// back();
//     1. return arr[r - 1];
// ____________________________________________

// front()
//     1. return arr[l];
// ____________________________________________

// pop_back()
//     1. r--;
// ____________________________________________

// pop_front()
//     1. l++;
// ____________________________________________

// size()
    
//     Если наш отрезок следующий:

//      l      50000         r
//      v        v           v
//     [x, x, x, x, x, x, x, 0]

//     l = 49997
//     r = 50004
//     size = r - l = 50004 - 49997 = 7;

//     1. return r - l;
// ____________________________________________

// empty()
//     if(r == l) return true;
//     else return false;

//     1. return r == l;
// ____________________________________________

// clear()

//      l      50000         r
//      v        v           v
//     [x, x, x, x, x, x, x, 0]

//      l = 49997
//      r = 50004    
//      1. i = 49997, while i < 50004;
//           arr[i] = 0;
//      2. l = 50000, r = 50000;
// ____________________________________________
