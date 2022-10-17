#include <iostream>
using namespace std;

struct ListNode{
    int data;
    ListNode *next;

    ListNode(int x){
        data = x;
        next = NULL;
    }
};

void printReverse(ListNode *head){
    if(head == NULL) return;
    printReverse(head->next);
    cout << head->data << " ";
}

ListNode *print(ListNode *head){
    ListNode *prev = NULL, *current = head, *forward = head->next;

    while(forward != NULL){
        current->next = prev;
        prev = current;
        current = forward;
        forward = forward->next;
    }
    current->next = prev;

    return current;
}

int main(){

    int n, x; cin >> n;
    ListNode *head = NULL;

    for(int i = 0; i < n; i++){
        cin >> x;
        if(head == NULL) head = new ListNode(x);
        else{
            ListNode *current = head;
            while(current->next != NULL) current = current->next;
            current->next = new ListNode(x);
        }
    }

    // printReverse(head);      - recursion method

    ListNode *ans = print(head);

    while(ans != NULL){
        cout << ans->data << " ";
        ans = ans->next;
    }
}