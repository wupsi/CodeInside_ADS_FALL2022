#include <iostream>
using namespace std;
int error = -999999999;

struct Node{
    int data;
    Node *next;
    Node *prev;

    Node(int x){
        data = x;
        next = NULL;
        prev = NULL;
    }
};

struct DoublyLinkedList{

private:
    Node *head;
    Node *tail;
    int sz;

public:

    DoublyLinkedList(){
        sz = 0;
        head = NULL;
        tail = NULL;
    }

    void push_front(int x){                     // Добавление в начало
        sz++;
        Node *newNode = new Node(x);            // Создаем новый узел

        if(head == NULL)                        // Если узел первый в списке
            head = tail = newNode;              // Объявим новый узел головным и конечным
        else{
            head->prev = newNode;
            newNode->next = head;
            head = newNode;
        }
    }

    void push_back(int x){                      // Добавление в конец
        sz++;
        Node *newNode = new Node(x);            // Создаем новый узел
        
        if(tail == NULL)                        // Если узел первый в списке
            head = tail = newNode;              // Объявим новый узел головным и конечным
        else{
            tail->next = newNode;
            newNode->prev = tail;
            tail = tail->next;
        }
    }

    int pop_front(){                            // Удаление головного узла
        if(empty()) return error;               // Если узел пустой, удалять нечего
        sz--;

        int value = front();
        if(head->next == NULL)
            head = tail = NULL;
        else{
            head = head->next;
            head->prev = NULL;
        }

        return value;
    }

    int pop_back(){                             // Удаление конечного узла
        if(empty()) return error;               // Если узел пустой, удалять нечего
        sz--;

        int value = back();
        if(head->next == NULL)
            head = tail = NULL;
        else{
            tail = tail->prev;
            tail->next = NULL;
        }

        return value;
    }

    int front(){                                // Возвращает головной узел
        return (empty() ? error : head->data);
    }

    int back(){                                 // Возвращает конечный узел
        return (empty() ? error : tail->data);
    }

    bool empty(){
        return head == NULL;
    }

    int size(){
        return sz;
    }

    void printBegin(){
        Node *current = head;

        while(current != NULL){
            cout << current->data << " ";
            current = current->next;
        }
    }

    void printEnd(){
        Node *current = tail;

        while(current != NULL){
            cout << current->data << " ";
            current = current->prev;
        }
    }
};


int main(){

    DoublyLinkedList dll;

    dll.push_front(5);              // [5]
    dll.push_front(4);              // [4, 5]
    dll.push_front(3);              // [3, 4, 5]
    dll.push_front(2);              // [2, 3, 4, 5]
    dll.push_front(1);              // [1, 2, 3, 4, 5]
    dll.push_back(6);               // [1, 2, 3, 4, 5, 6]
    dll.push_back(7);               // [1, 2, 3, 4, 5, 6, 7]
    dll.push_back(8);               // [1, 2, 3, 4, 5, 10, 6, 7, 8]
    cout << dll.pop_back() << endl;
    cout << dll.pop_front() << endl;
    cout << dll.pop_front() << endl;
    cout << dll.pop_front() << endl;
    cout << "Front: " << dll.front() << endl;
    cout << "Back: " << dll.back() << endl;
    cout << "Size: " << dll.size() << endl;
    cout << dll.pop_front() << endl;
    cout << dll.pop_front() << endl;
    cout << dll.pop_front() << endl;
    cout << dll.pop_front() << endl;
    cout << dll.pop_front() << endl;

    cout << dll.size() << endl;
    dll.printBegin();
    cout << endl;
    dll.printEnd();
}