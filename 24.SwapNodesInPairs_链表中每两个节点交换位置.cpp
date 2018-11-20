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



class Solution2 {
public:
    ListNode* swapPairs(ListNode* head) {
		ListNode **pp = &head;
		ListNode *a, *b;
		while ((a = *pp) && (b = a->next))
        {
			a->next = b->next;
			b->next = a;
			*pp = b;
			pp = &(a->next);
        }
        return head;
    }
};


class Solution {
public:
	ListNode* swapPairs(ListNode* head) {
		ListNode *dd= new ListNode(-1);
		dd->next = head;
		ListNode *pre = dd;
		while (pre->next && pre->next->next)
		{
			ListNode *tmp = pre->next->next;
			pre->next->next = tmp->next;
			tmp->next = pre->next;
			pre->next = tmp;
			pre = tmp->next;
		}

		return dd->next;
	}
};




int main1634() {
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

	return 0;
}