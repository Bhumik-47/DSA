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
        if(!head || !head->next)return head;
        ListNode*slow=head;
        ListNode*fast=head->next;
        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode*mid=slow->next;
        slow->next=NULL;
        ListNode*left = sortList(head);
        ListNode*right = sortList(mid);
        return mergesort(left,right);

    }
    ListNode* mergesort(ListNode*l1 , ListNode*l2){
        if(l1==NULL)return l2;
        if(l2==NULL)return l1;
        ListNode dummy(-1);
        ListNode*temp=&dummy;
        while(l1!=NULL && l2!=NULL){
            if(l1->val<=l2->val){
                temp->next=l1;
                l1=l1->next;
            }
            else{
                temp->next=l2;
                l2=l2->next;
            }
            temp=temp->next;
        }
        temp->next=l1?l1:l2;
        return dummy.next;
    }

};