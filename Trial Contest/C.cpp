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

ListNode *OddEven(ListNode *head){
    ListNode *odd = head, *even = head->next, *evenHead = head->next;

    while(true){
        if(even == NULL or even->next == NULL){
            odd->next = evenHead;
            return head;
        }
        odd->next = odd->next->next;
        even->next = even->next->next;
        odd = odd->next;
        even = even->next;
    }
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

    ListNode *ans = OddEven(head);

    while(ans != NULL){
        cout << ans->data << " ";
        ans = ans->next;
    }
}