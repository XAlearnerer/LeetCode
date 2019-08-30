#include<iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
public:
	ListNode* reverseBetween(ListNode* head, int m, int n) {
		if (!head || !head->next) return head;
		ListNode* dummy = new ListNode(-1);
		dummy->next = head;
		ListNode* pre = dummy;
		for (int i = 1; i<m; ++i)
			pre = pre->next;

		ListNode* cur = pre->next;
		for (int i = m; i < n; ++i) {
			ListNode *t = cur->next;
			cur->next = t->next;
			t->next = pre->next;
			pre->next = t;
		}

		return dummy->next;
	}
};