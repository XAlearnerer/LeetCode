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
		ListNode* f = head, *s = head;

		////////////////////////
		ListNode* s2 = head;
		///////////////////////

		while (f && f->next)
		{
			f = f->next->next;
			s2 = s;
			s = s->next;
		}

		s2->next = NULL;

		//sortList(head);
		//sortList(s);

		return merge(sortList(head), sortList(s));
	}

	ListNode* merge(ListNode* l, ListNode* r)
	{
		ListNode* dummy = new ListNode(-1);
		ListNode* cur = dummy;
		while (l&&r)
		{
			if (l->val < r->val) { cur->next = l; l = l->next; }
			else { cur->next = r; r = r->next; }
			cur = cur->next;
		}

		if (l) cur->next = l;
		if (r) cur->next = r;

		return dummy->next;
	}


};

