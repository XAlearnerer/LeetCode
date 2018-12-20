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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head->next==NULL)
            return NULL;
        ListNode* p=head;
        ListNode* q=head;

        for(int i=0;i!=n;++i)
            q=q->next;

        if(!q) return head->next;  // 注意这里

        while( q->next)
        {
            p=p->next;
            q=q->next;
        }
        p->next=p->next->next;
        return head;
    }
};

