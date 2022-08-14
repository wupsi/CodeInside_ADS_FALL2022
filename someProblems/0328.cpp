/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* oddEvenList(ListNode* head){
        if(head == NULL or head->next == NULL) return head;
        ListNode *even = head, *odd = head->next;
        ListNode *oddHead = odd, *evenHead = even;
        
        while(true){
            if(odd == NULL){
                even->next = oddHead;
                return evenHead;
            }
            if(odd->next == NULL){
                even->next = oddHead;
                return evenHead;
            }
            even->next = even->next->next;
            odd->next = odd->next->next;
            even = even->next;
            odd = odd->next;
        }
    }
};

// Space Complexity - O(1);
// Time Complexity - O(n);