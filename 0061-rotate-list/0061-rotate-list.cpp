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
    ListNode* rotateRight(ListNode* head, int k) {
         if(!head || !head->next || k == 0) return head;

    int n = 0;
    ListNode* temp = head;
    while(temp){
        temp = temp->next;
        n++;
    }

    k = k % n;
    if(k == 0) return head;

    int steps = n - k;

    ListNode* curr = head;
    for(int i = 1; i < steps; i++){
        curr = curr->next;
    }

    ListNode* newHead = curr->next;
    curr->next = NULL;

    ListNode* tail = newHead;
    while(tail->next){
        tail = tail->next;
    }

    tail->next = head;

    return newHead;
    }
};