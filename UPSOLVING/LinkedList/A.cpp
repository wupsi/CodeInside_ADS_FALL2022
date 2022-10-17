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
struct Stack{
    int sz;                                             // Счетчик для размера массива
    ListNode *head;                                     // Головной элемент

    Stack(){
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
        if(head->next == NULL){                         // Если в узле только 1 элемент, тогда удалим головной элемент
            int x = head->val;                          // Заранее сохраним значение в переменную
            head = NULL;                                // Укажем что головной элемент ничему не равен
            return x;                                   // Возвращаем сохраненное значение
        }    

        ListNode *current = head;
        while(current->next->next != NULL)              // Пока не дойдем до предпоследнего элемента
            current = current->next;                    // Переходим к следующему узлу
        
        int x = current->next->val;                     // Сохраним значение последнего элемента
        current->next = NULL;                           // Так как мы на предпоследнем элементе, мы можем удалить последний
        return x;                                       // Выведем значение последнего элемента
    }

    int back(){
        if(head == NULL) return inf;                    // Если список пустой, возвратим ошибку
        ListNode *current = head;                       // Создаем "текущий" узел, изначально указывающий на головной элемент
        while(current->next != NULL)                    // Пока не дойдем до последнего элемента
            current = current->next;                    // Переходим к следующему узлу
        return current->val;                            // Возвращаем значение последнего узла
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
    Stack st;                                   // Объявляем стек
    int x;
    string command;                         

    while(cin >> command){
        if(command == "push"){
            cin >> x;
            st.push(x);                         // Добавляем в стек
            cout << "ok\n";
        }
        if(command == "pop"){
            x = st.pop();                       // Удаление последнего элемента
            if(x == inf) cout << "error\n";     // Если возвратило inf, выводим ошибку
            else cout << x << endl;             // Вывод последнего элемента
        }
        if(command == "back"){
            x = st.back();                      // Берем последний элемент
            if(x == inf) cout << "error\n";     // Если возвратило inf, выводим ошибку
            else cout << x << endl;             // Вывод последнего элемента
        }
        if(command == "size"){
            cout << st.size() << endl;          // Вывод размера стека
        }
        if(command == "clear"){
            st.clear();                         // Очистка стэка
            cout << "ok\n";
        }
        if(command == "exit"){
            cout << "bye";
            break;
        }
    }
}