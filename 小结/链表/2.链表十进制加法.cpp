#include<iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		if (!l1) return l2;
		if (!l2) return l1;
		ListNode* dummy = new ListNode(-1);
		ListNode* res = dummy;
		int carry = 0;
		while (l1 || l2)
		{
			int v1 = l1 == NULL ? 0 : l1->val;
			int v2 = l2 == NULL ? 0 : l2->val;
			int cur = v1 + v2 + carry;
			carry = cur / 10;
			ListNode* t = new ListNode(cur % 10);
			dummy->next = t;
			dummy = dummy->next;
			if (l1) l1 = l1->next;
			if (l2) l2 = l2->next;
		}

		if (carry != 0)
		{
			ListNode* t = new ListNode(1);
			dummy->next = t;
			t->next = NULL;
		}

		return res->next;
	}
};