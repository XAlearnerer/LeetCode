#include<iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
	ListNode* partition(ListNode* head, int x) {
		if (!head || !head->next) return head;
		ListNode* dummy = new ListNode(-1);
		dummy->next = head;
		ListNode* du2 = new ListNode(-1);
		ListNode* cur = dummy, *p = du2;
		while (cur->next)
		{
			if (cur->next->val < x)
			{
				cur = cur->next;
			}
			else
			{
				p->next = cur->next;
				p = p->next;
				cur->next = cur->next->next;
				p->next = NULL;
			}
		}

		cur->next = du2->next;
		return dummy->next;

	}
};




