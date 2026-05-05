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
        if(!head || !head->next) return head;

        ListNode* tail = head;
        int L=1;
        while(tail->next) {
            tail = tail->next;
            L++;
        }

        k %= L;
        if(k==0) return head;

        int breakP = L-k-1;
        ListNode* prev = head;
        for(int i=0; i<breakP; i++) {
            prev = prev->next;
        }

        tail->next = head;
        head = prev->next;
        prev->next = NULL;

        return head;
    }
};