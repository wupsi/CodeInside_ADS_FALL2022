#include <iostream>
using namespace std;

struct Node{
    int value;
    Node *next;
};

struct LinkedList{

private:
    Node *head;

public:
    LinkedList(){
        head = NULL;
    }

    void addNode(int x){
        Node *newNode = new Node();         // Создаем новый узел
        newNode->value = x;                 // Передаем значение узла
        newNode->next = NULL;               // Пока указатель будет NULL

        if(head == NULL){                   // Если это первый элемент списка
            head = newNode;                 // Тогда head присвоим новый узел
        }
        else{                               // Если узел не первый
            Node *current = head;           // Создаем текущий узел
            while(current->next != NULL){   // Проходимся по всем узлам, пока не найдем конечный
                current = current->next;
            }            
            current->next = newNode;        // Конечный элемент будет указывать на новый узел
        }
    }

    void printNodes(){
        Node *current = head;

        while(current){
            cout << current->value << " ";
            current = current->next;
        }
    }
};

int main(){

    LinkedList list;

    list.addNode(1);
    list.addNode(2);
    list.addNode(3);
    list.addNode(4);
    list.addNode(5);
    list.addNode(6);

    list.printNodes();
}
