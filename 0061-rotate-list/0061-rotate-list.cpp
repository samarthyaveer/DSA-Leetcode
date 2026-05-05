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
        vector<int> listArr;
        ListNode* temp = head;

        while(temp) {
            listArr.push_back(temp->val);
            temp = temp->next;
        }

        int n = listArr.size();
        k = k%n;
        vector<int> rotatedArr(n);

        for(int i=0; i<n; i++) {
            rotatedArr[(i+k) % n] = listArr[i];
        }

        temp = head;
        int i=0;
        while(temp) {
            temp->val = rotatedArr[i++];
            temp = temp->next;
        }
        return head;
    }
};