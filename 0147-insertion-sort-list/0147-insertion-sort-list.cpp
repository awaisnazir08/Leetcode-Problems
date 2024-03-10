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
    ListNode* insertionSortList(ListNode* head) {
        ListNode *temp2 = head;
        int n = 0;
        while(temp2 != nullptr)
        {
            temp2 = temp2->next;
            n++;
        }
        temp2 = head;
        // stack<int>prv_nums;
        for(int i = 1; i < n; i++)
        {
            temp2 = head;
            for(int k = 0; k < i-1; k++)
            {
                // prv_nums.push(temp->val);
                temp2 = temp2->next;
            }
            ListNode* temp = temp2->next;
            int key = temp->val;
            ListNode* temp3 = head;
            for(int j = 0; j <= i-1; j++)
            {
                if(j==0 && temp3->val > key)
                {
                    temp2->next = temp->next;
                    // ListNode *n = new ListNode(key);
                    temp->next = head;
                    // n->next = head;
                    head = temp;
                    break;
                }
                else if(temp3->next->val < key)
                {
                    temp3 = temp3->next;
                }
                else
                {
                    temp2->next = temp->next;
                    ListNode* temp4 = temp3->next;
                    temp3->next = temp;
                    temp->next = temp4;
                    break;
                }
            }




            // while((!prv_nums.empty()) && key < prv_nums.top())
            // {

            // }
        }
        return head;
    }
};