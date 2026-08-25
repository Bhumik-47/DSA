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
    ListNode* sortList(ListNode* head) {
        vector<int>v;
        ListNode *t = head;
        while(t){
          v.push_back(t->val);
          t=t->next;
        }
        sort(v.begin(),v.end());
        ListNode *h2 = new ListNode(-1);
        ListNode *h1=h2;
        int i=0;
        while(i<v.size()){
            h1->next = new ListNode(v[i]);
            h1=h1->next;
            i++;
        }
        return h2->next;
    }
};