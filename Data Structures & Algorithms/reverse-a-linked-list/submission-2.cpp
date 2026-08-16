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
    ListNode* reverseListIt(ListNode* head) {
        ListNode *prev = nullptr, *curr = head;
    
        while(curr != nullptr){
            ListNode *tmp = curr;
            curr = curr->next;
            tmp->next = prev;
            prev = tmp;
        }   
        return prev;
    }

    ListNode* reverseList(ListNode* head) {
        if(head==nullptr || head->next == nullptr) return head;
        ListNode* h = head;
        ListNode* remainder = h->next;

        ListNode* remHead = reverseList(remainder);
        ListNode* tail = h->next;
        tail->next = h;
        h->next = nullptr;
        return remHead;
    }

};
