/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*,Node*>mp;
        Node*t=head;
        
        while(t){
            mp[t]=new Node(t->val);
            t=t->next;
        }
        t=head;
        while(t){
            mp[t]->next=mp[t->next];
            mp[t]->random =mp[t->random];
            t=t->next;
        }
       return mp[head];
    }
};