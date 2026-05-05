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
        if(head==NULL || head->next==NULL) return head;
        vector<int> listArr;
        ListNode* temp = head;
        while(temp) {
            listArr.push_back(temp->val);
            temp = temp->next;
        }
        int n = listArr.size();
        k = k%n;
        reverse(listArr.begin(), listArr.end());
        reverse(listArr.begin(), listArr.begin()+k);
        reverse(listArr.begin()+k, listArr.end());
        temp = head;
        int i=0;
        while(temp) {
            temp->val = listArr[i];
            i++;
            temp = temp->next;
        }
        return head;
    }
};