#include<iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
public:
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		if (!l1) return l2;
		if (!l2) return l1;
		ListNode* dummy = new ListNode(-1);
		ListNode* res = dummy;
		while (l1 && l2)
		{
			if (l1->val > l2->val)
			{
				dummy->next = l2;
				l2 = l2->next;
			}
			else
			{
				dummy->next = l1;
				l1 = l1->next;
			}

			dummy = dummy->next;
		}
		if (l1)
		{
			dummy->next = l1;
		}
		if (l2) dummy->next = l2;

		return res->next;
	}
};




