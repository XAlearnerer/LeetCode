#include <iostream>

using namespace std;


struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
public:
	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
		ListNode *a = headA, *b = headB;
		int la = 0, lb = 0;
		while (a)
		{
			a = a->next;
			++la;
		}
		while (b)
		{
			b = b->next;
			++lb;
		}

		if (a != b) return NULL;

		a = headA, b = headB;
		if (la > lb)
		{
			int dif = la - lb;
			while (dif)
			{
				a = a->next;
				--dif;
			}
		}
		else
		{
			int dif = lb - la;
			while (dif--)
				b = b->next;
		}
		while (a && b)
		{
			if (a == b)
				return a;
			else
			{
				a = a->next;
				b = b->next;
			}
		}
		return NULL;
	}
};


