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
    ListNode* swapPairs(ListNode* head) {
        if(head == NULL)
        {
            return head;
        }
        else if(head->next == NULL)
        {
            return head;
        }
        ListNode* temp = head->next;
        ListNode* temp2;
        if(temp->next == NULL)
        {
            temp2 = NULL;
        }
        else
        {
            temp2 = temp->next;
        }
        // head->next = temp2;
        temp->next = head;
        // head->next->next = temp2;
        // head = temp;
        // head->next = temp;
        // head= head->next->next;
        head->next = swapPairs(temp2);
        return temp;
    }
};