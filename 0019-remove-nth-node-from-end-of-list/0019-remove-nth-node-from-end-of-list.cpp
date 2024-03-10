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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
    int count = 0;
    ListNode * temp = head;
    while(temp)
    {
        temp = temp->next;
        count++;
    }
    int togo = count - n - 1;
    temp = head;
    for(int i = 0; i < togo; i++)
    {
        temp = temp->next;
    }

    if(temp->next == nullptr && togo <=0)
    {
        return head->next;
    }
    else if(temp->next != nullptr && togo <0)
    {
        return head->next;
    }
    if(temp->next!=nullptr)
    {
        ListNode *toDelete = temp->next;
        temp->next = temp->next->next;
        delete toDelete;
    }
    else
    {
        ListNode* toDelete = temp->next;
        temp->next = nullptr;
        delete toDelete;
    }
    return head;
    }
};