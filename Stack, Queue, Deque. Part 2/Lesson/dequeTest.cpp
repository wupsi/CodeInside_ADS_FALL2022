#include <iostream>
#include <deque>
using namespace std;

void print(deque<int>& dq){                 // print deque

    deque<int> someDeq = dq;

    cout << "deque: ";
    while(!someDeq.empty()){
        cout << someDeq.back() << " ";
        someDeq.pop_back();
    }
    cout << endl;
}

int main(){

    deque<int> dq;                  // []

    dq.push_back(1);                // [1]
    dq.push_back(2);                // [1, 2]
    dq.push_back(3);                // [1, 2, 3]
    dq.push_front(4);               // [4, 1, 2, 3]
    dq.push_front(5);               // [5, 4, 1, 2, 3]
    dq.push_front(6);               // [6, 5, 4, 1, 2, 3]
    print(dq);                      // Вывод: 3 2 1 4 5 6

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


// Свойства
// stack[] = [1, 2, 3, 4, 5, 6, 7, 8] <- top()
// queue[] = top() -> [1, 2, 3, 4, 5, 6, 7, 8] <- push()
// deque[] = push(), pop() -> [1, 2, 3, 4, 5, 6, 7, 8] <- push(), pop()