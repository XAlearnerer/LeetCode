//
// Created by zhao on 18-11-15.
//

#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *res=new ListNode(-1);
        ListNode* b=res;
        while(l1 && l2)
        {
            if(l1->val<l2->val) {
                res->next=new ListNode(l1->val);
                l1=l1->next;
            }
            else {
                res->next=new ListNode(l2->val);
                l2=l2->next;
            }
            res=res->next;
        }

        while(l1)
        {
            res->next=new ListNode(l1->val);
            l1=l1->next;
            res=res->next;
        }
        while(l2)
        {
            res->next=new ListNode(l2->val);
            l2=l2->next;
            res=res->next;
        }

        return b->next;
    }
};


class Solution2 {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *dummy = new ListNode(-1), *cur = dummy;
        while (l1 && l2) {
            if (l1->val < l2->val) {
                cur->next = l1;
                l1 = l1->next;
            } else {
                cur->next = l2;
                l2 = l2->next;
            }
            cur = cur->next;
        }
        cur->next = l1 ? l1 : l2;
        return dummy->next;
    }
};


