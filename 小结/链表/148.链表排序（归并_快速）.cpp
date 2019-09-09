#include<iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};


class Solution2 {
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
			if (l->val < r->val)
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


/////////////////////////////////////////////////////////////////////


class Solution {
public:
	ListNode* sortList(ListNode* head) {
		if (!head || !head->next) return head;
		ListNode* cur = head->next;
		ListNode* small = new ListNode(0);
		ListNode* large = new ListNode(0);
		ListNode* sp = small;
		ListNode* lp = large;
		while (cur)
		{
			if (cur->val < head->val)
			{
				sp->next = cur;
				sp = cur;
			}
			else
			{
				lp->next = cur;
				lp = cur;
			}
			cur = cur->next;
		}

		sp->next = NULL;
		lp->next = NULL;
		small = sortList(small->next);
		large = sortList(large->next);
		cur = small;
		if (cur)
		{
			while (cur->next) cur = cur->next;
			cur->next = head;
			head->next = large;
			return small;
		}
		else {
			head->next = large;
			return head;
		}
	}
};

