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
    ListNode* reversel(ListNode*h){
        ListNode*prev=NULL;
        while(h){
            ListNode*next=h->next;
            h->next=prev;
            prev=h;
            h=next;
        }
        return h;
    }
    ListNode* getk(ListNode*temp, int k){
        k-=1;
        while(temp && k>0){
            temp=temp->next;
            k--;
        }
        return temp;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode*temp=head;
        ListNode*prevp=NULL;
        while(temp){
        ListNode*kth=getk(temp,k);
        if(kth==nullptr){
        if(prevp){
            prevp->next=temp;
        }
            break;
        
        }
        ListNode*nextp=kth->next;
        kth->next=NULL;
        reversel(temp);
        if(temp==head){
            head=kth;
        }else
        prevp->next=kth;
        prevp=temp;
        temp=nextp;
        
        }
        return head;
    }
};