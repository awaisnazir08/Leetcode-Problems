/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        for(Node* h = head; h; h = h->next)
        {
            if(head == NULL)
            {
                return NULL;
            }
            if(h-> child != NULL)
            {
                Node* next = h->next;
                // child->prev = h;
                h->next = h->child;
                h->next->prev = h;
                h->child = NULL;
                Node *p = h->next;
                while(p->next)
                {
                    p = p ->next;
                }
                p->next = next;
                if(next)
                {
                    next->prev =  p;
                }
                
            }
        }
        return head;
    }
};