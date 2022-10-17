#include <iostream>
using namespace std;

int inf = -99999999;        // Переменная для вывода ошибок

// Узел односвязного списка
struct ListNode{
    int val;
    ListNode *next;

    ListNode(int x){
        val = x;
        next = NULL;
    }
};

// Структура стека
struct Queue{
    int sz;                                             // Счетчик для размера массива
    ListNode *head;                                     // Головной элемент

    Queue(){
        sz = 0;                                         // Счетчик изначально равен нулю
        head = NULL;                                    // Головной элемент изначально не указывает никуда
    }

    void push(int x){
        if(head == NULL) head = new ListNode(x);        // Для головного элемента создаем новый узел, если элемент первый в листе
        else{                                           // Если элемент не первый
            ListNode *current = head;                   // Создаем "текущий" узел, изначально указывающий на головной элемент
            while(current->next != NULL)                // Пока не дойдем до последнего элемента
                current = current->next;                // Переходим к следующему узлу
            
            current->next = new ListNode(x);            // next узел после последнего узла будет новый узел со значением x
        }
        sz++;                                           // Увеличиваем счетчик размера
    }

    int pop(){
        if(head == NULL) return inf;                    // Если список пустой, удалять нам нечего, возвратим ошибку
        sz--;                                           // Уменьшаем счетчик размера
        int x = head->val;                              // Заранее сохраняем значение в переменной
        head = head->next;                              // Теперь головным элементом будет следующий после первого
        return x;                                       // Возвращаем сохраненное значение
    }

    int front(){
        if(head == NULL) return inf;                    // Если список пустой, возвратим ошибку
        return head->val;                               // Возвращаем значение первого узла
    }

    int size(){
        return sz;
    }

    void clear(){
        sz = 0;
        head = NULL;                                    // Обнуляем head. При следующем push будет создаваться новый список
    }
    
    void print(){
        ListNode *current = head;
        while(current != NULL){
            cout << current->val << " ";
            current = current->next;
        }
        cout << endl;
    }
};

int main(){
    Queue q;                                    // Объявляем очередь
    int x;
    string command;                         

    while(cin >> command){
        if(command == "push"){
            cin >> x;
            q.push(x);                          // Добавляем в очередь
            cout << "ok\n";
        }
        if(command == "pop"){
            x = q.pop();                        // Удаление последнего элемента
            if(x == inf) cout << "error\n";     // Если возвратило inf, выводим ошибку
            else cout << x << endl;             // Вывод последнего элемента
        }
        if(command == "front"){
            x = q.front();                      // Берем последний элемент
            if(x == inf) cout << "error\n";     // Если возвратило inf, выводим ошибку
            else cout << x << endl;             // Вывод последнего элемента
        }
        if(command == "size"){
            cout << q.size() << endl;           // Вывод размера очереди
        }
        if(command == "clear"){
            q.clear();                          // Очистка очереди
            cout << "ok\n";
        }
        if(command == "exit"){
            cout << "bye";
            break;
        }
    }
}