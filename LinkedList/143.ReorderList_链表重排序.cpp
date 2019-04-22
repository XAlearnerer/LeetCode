//
// Created by zhao on 19-4-22.
//
#include <iostream>


using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
 };

//Given a singly linked list L: L0→L1→…→Ln-1→Ln,
//reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…

class Solution {
public:
    void reorderList(ListNode* head) {
        if(!head) return;
        ListNode* fast=head,*slow=head;
        while(fast->next && fast->next->next)
        {
            slow=slow->next;
            fast=fast->next->next;
        }

        ListNode* pre = slow->next;
        slow->next=NULL;
        ListNode* nhead=NULL;
        while(pre)
        {
            ListNode* p=pre->next;
            pre->next=nhead;
            nhead=pre;
            pre=p;
        }

        while (head && nhead)
        {
            ListNode *next = head->next;
            head->next = nhead;
            nhead = nhead->next;
            head->next->next = next;
            head = next;
        }

    }
};