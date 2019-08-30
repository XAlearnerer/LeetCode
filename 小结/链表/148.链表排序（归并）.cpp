#include<iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
public:
	ListNode* sortList(ListNode* head) {
		if (!head || !head->next) return head;
		ListNode* s = head, *f = head;
		ListNode* pre = head;
		while (f && f->next)
		{
			pre = s;
			f = f->next->next;
			s = s->next;
		}

		pre->next = NULL;
		return merge(sortList(head), sortList(s));
	}

	ListNode* merge(ListNode* l, ListNode*r)
	{
		ListNode* dummy = new ListNode(-1);
		ListNode* cur = dummy;
		while (l && r)
		{
			if (l->val<r->val)
			{
				cur->next = l;
				l = l->next;
			}
			else {
				cur->next = r;
				r = r->next;
			}
			cur = cur->next;
		}

		if (l) cur->next = l;
		if (r) cur->next = r;

		return dummy->next;
	}

};


