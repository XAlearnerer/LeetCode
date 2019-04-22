//
// Created by zhao on 19-4-22.
//

#include <iostream>
using  namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution2 {  //? worng
    /////// head can be deleted
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *pre=new ListNode(-1);
        pre->next=head;
        ListNode *n=head;

        while(pre->next)
        {
            if(pre->next->val!=val)
                pre=pre->next;
            else
            {
                ListNode* cur=pre->next;
                pre->next=cur->next;

            /////////////////////
                cur->next=NULL;
                delete(cur);
            /////////////////////

            }
        }


        return n;
    }
};

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *dummy = new ListNode(-1), *pre = dummy;
        dummy->next = head;
        while (pre->next) {
            if (pre->next->val == val) {
                ListNode *t = pre->next;
                pre->next = t->next;
                t->next = NULL;
                delete t;
            } else {
                pre = pre->next;
            }
        }
        return dummy->next;
    }
};
