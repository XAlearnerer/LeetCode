#include<iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

//1 -> 2 -> 3 -> 4 -> 5 -> NULL
//1 -> 3 -> 2 -> 4 -> 5 -> NULL
//1 -> 4 -> 3 -> 2 -> 5 -> NULL
//
//我们可以看出来，总共需要n - m步即可，
//第一步是将结点3放到结点1的后面，第二步将结点4放到结点1的后面。


class Solution {
public:
	ListNode* reverseBetween(ListNode* head, int m, int n) {
		if (!head || !head->next) return head;
		ListNode* dummy = new ListNode(-1);
		dummy->next = head;
		ListNode* pre = dummy;
		for (int i = 1; i < m; ++i)
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