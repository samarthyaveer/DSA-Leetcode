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
    ListNode* ans(ListNode* curr, ListNode* prev, ListNode* after) {
        if(curr == NULL) return prev;
        after = curr->next;
        curr->next = prev;
        return ans(after, curr, NULL);
    }
    ListNode* reverseList(ListNode* head) {
        if(head == NULL) return head;
        ListNode* curr = head;
        return ans(curr, NULL, NULL);
    }
};