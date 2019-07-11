#include<iostream>

using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};



class Solution {
public:
	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
		if (!headA || !headB) return NULL;
		int l1 = 1, l2 = 1;
		ListNode* a = headA, *b = headB;
		while (a->next) { a = a->next; ++l1; }
		while (b->next) { b = b->next; ++l2; }
		if (a != b) return NULL;

		ListNode* f, *s;
		int dif = -1;
		if (l1 < l2)
		{
			f = headB;
			s = headA;
			dif = l2 - l1;
		}
		else
		{
			f = headA;
			s = headB;
			dif = l1 - l2;
		}

		for (int i = 0; i < dif; ++i) f = f->next;
		while (f != s)
		{
			f = f->next;
			s = s->next;
		}
		return f;

	}
};


