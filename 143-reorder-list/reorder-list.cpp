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
    void reorderList(ListNode* head) {
        ListNode*s=head;
        ListNode*f=head;
        while(f->next && f->next->next){
          s=s->next;
          f=f->next->next;
        }
        ListNode*sd=s->next;
        s->next=NULL;
        ListNode*p=NULL;
        while(sd){
            ListNode*nxt=sd->next;
            sd->next=p;
            p=sd;
            sd=nxt;
        }
        sd=p;
        ListNode*ft=head;
        while(sd){
            ListNode*t1=ft->next;
            ListNode*t2=sd->next;

            ft->next=sd;
            sd->next=t1;

            ft=t1;
            sd=t2;
        }
    }
};