//
// Created by zhao on 18-11-15.
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
    ListNode* swapPairs(ListNode* head) {
        ListNode* a=head;
        ListNode* tmp;
        while(a->next)
        {
            tmp=a->next;
            a->next=a;
            a=tmp;
            a=a->next;
            cout<<a->val<<endl;
        }
        return head;

    }
};

int main() {
    ListNode *a = new ListNode(1);
    a->next = new ListNode(2);
    a->next->next = new ListNode(3);
    a->next->next->next = new ListNode(4);
    a->next->next->next->next = NULL;

    Solution n;
    ListNode *r= n.swapPairs(a);
    while(r)
    {
        cout<<r->val<<" -> ";
        r=r->next;
    }
    cout<<endl;

}