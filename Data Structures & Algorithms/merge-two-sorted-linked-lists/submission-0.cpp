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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (list1 == nullptr)
            return list2;
        else if (list2 == nullptr)
            return list1;

        ListNode *curr1 = list1, *curr2 = list2;
        ListNode* newHead = nullptr;  // list1->val <= list2->val ? list1 : list2;
        ListNode* mergeCurr = nullptr;

        while (curr1 && curr2) {
            if (curr1->val <= curr2->val) {
                if (newHead == nullptr) {
                    newHead = curr1;
                    mergeCurr = curr1;
                    curr1 = curr1->next;
                    continue;
                }
                mergeCurr->next = curr1;
                mergeCurr = mergeCurr->next;
                curr1 = curr1->next;
            } else {
                if (newHead == nullptr) {
                    newHead = curr2;
                    mergeCurr = curr2;
                    curr2 = curr2->next;
                    continue;
                }
                mergeCurr->next = curr2;
                mergeCurr = mergeCurr->next;
                curr2 = curr2->next;
            }
        }

        if (curr1) mergeCurr->next = curr1;
        if (curr2) mergeCurr->next = curr2;

        return newHead;
    }
};
