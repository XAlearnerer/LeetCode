#include<iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* deleteDuplicates(ListNode* head) {
		if (!head || !head->next) return head;
		ListNode* dummy = new ListNode(-1);
		dummy->next = head;
		ListNode* pre = dummy;

		while (pre->next)
		{
			ListNode* cur = pre->next;
			while (cur->next && cur->next->val == cur->val)
				cur = cur->next;
			if (cur == pre->next)
				pre = pre->next;
			else
				pre->next = cur->next;
		}

		return dummy->next;
	}
};










