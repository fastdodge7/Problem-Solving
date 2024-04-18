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
    ListNode* reverseAGroup(ListNode* head, int k)
    {
        ListNode* groupNext = head;
        for(int i = 0; i < k; i++)
        {
            if(groupNext)
                groupNext = groupNext->next;
            else
                return head;
        }

        ListNode* cur = head;
        for(int i = 0; i < k - 1; i++)
        {
            ListNode* next = head->next;
            head->next = next->next;
            next->next = cur;
            cur = next;
        }
        head->next = reverseAGroup(head->next, k);

        return cur;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        return reverseAGroup(head, k);
    }
};