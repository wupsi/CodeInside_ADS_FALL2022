#include <iostream>
using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode *prev;
    ListNode(int x){
        val = x;
        next = NULL;
        prev = NULL;
    }
};

void RemoveDuplicates(ListNode *head){
    ListNode *current = head;
    while(current != NULL){
        current = current->next;
    }
}

void print(ListNode *head){

}

int main(){
    int n, x; cin >> n;
    ListNode *head = NULL;

    for(int i = 0; i < n; i++){
        cin >> x;
        if(head == NULL) head = new ListNode(x);
        else{
            ListNode *current = head, newNode = new ListNode(x);
            while(current->next != NULL) current = current->next;
            newNode->prev = current;
            current->next = newNode;
        }
    }
    RemoveDuplicates(head);
}