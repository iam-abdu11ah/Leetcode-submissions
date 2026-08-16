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
    ListNode* reverseList(ListNode* head) {
        if(head==nullptr) return nullptr;
        ListNode *l, *r;
        l=head;
        r=head;
        while(r->next) r = r->next;

        while(l != r){
            ListNode* tmp = l;
            l = l->next;
            tmp->next = r->next;
            r->next = tmp;
        }   
        return r;
    }


    /*ListNode* reverseList(ListNode* head) {
        utilityRec(head);
        return head;
    }
    ListNode* utilityRec(ListNode* head) {
        if(head->next == nullptr) return head;
        ListNode* h = head;
        ListNode* res = utilityRec(head->next);
        res->next = h;
        h->next = nullptr;
        head = res;
        return h;
    }*/
};
