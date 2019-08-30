#include<iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* removeNthFromEnd(ListNode* head, int n) {
		if (!head || !head->next) return NULL;
		ListNode* pre = head, *cur = head;
		for (int i = 0; i < n; ++i)
		{
			cur = cur->next;
		}
		if (!cur) return head->next;
		while (cur->next)
		{
			cur = cur->next;
			pre = pre->next;
		}
		pre->next = pre->next->next;
		return head;
	}
};


