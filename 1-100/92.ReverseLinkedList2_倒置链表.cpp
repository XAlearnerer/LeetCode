//
// Created by zhao on 18-11-23.
//

#include <iostream>
using  namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if(m==n) return head;
        ListNode* pre=new ListNode(-1);
        pre->next=head;
        ListNode* start=pre;
        int i=0;
        ListNode* pa;
        ListNode* a;

        while(i<m-1)
        {
            ++i;
            pre=pre->next;
        }
        pa=pre;
        ++i;
        pre=pre->next;

        a=pre;
        ++i;
        pre=pre->next;

        ListNode* prei=a;
        while(i<=n)
        {
            ListNode *nex=pre->next;
            pre->next=prei;
            ++i;
            prei=pre;
            pre=nex;
        }

        pa->next=prei;
        a->next=pre;

        return start->next;
    }
};

int main1135() {
    ListNode *a = new ListNode(1);
    a->next = new ListNode(2);
    a->next->next = new ListNode(3);
    a->next->next->next = new ListNode(4);
    a->next->next->next->next = new ListNode(5);
    a->next->next->next->next->next = NULL;

    Solution n;
    ListNode *r = n.reverseBetween(a,2,4);


    while (r)
    {
        cout << r->val << " -> ";
        r = r->next;
    }
    cout << endl;

    return 0;
}