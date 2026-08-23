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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode dummy(0);
        ListNode*temp=&dummy;
        int carry = 0;
        while(l1 || l2 || carry){
            int s1=l1!=NULL?l1->val:0;
            int s2=l2!=NULL?l2->val:0;
            int total = s1+s2+carry;
            carry= (total)/10;
            
            temp->next=new ListNode(total%10);
            temp=temp->next;
            l1=l1!=NULL?l1->next:NULL;
            l2=l2!=NULL?l2->next:NULL;
        }
        return dummy.next;
        
        
    }
};