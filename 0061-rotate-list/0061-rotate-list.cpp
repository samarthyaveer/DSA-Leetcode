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
        if(!head || !head->next || k==0) return head;

        ListNode* tail = head;
        int L=1;
        while(tail->next) {
            tail = tail->next;
            L++;
        }

        k %= L;
        if(k==0) return head;

        tail->next = head;

        int breakP = L-k;
        ListNode* newTail = head;
        for(int i=1; i<breakP; i++) {
            newTail = newTail->next;
        }

        head = newTail->next;
        newTail->next = NULL;

        return head;
    }
};