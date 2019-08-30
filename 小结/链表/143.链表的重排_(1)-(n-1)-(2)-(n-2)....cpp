#include<iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
public:
	void reorderList(ListNode* head) {
		if (!head) return;
		ListNode* fast = head, *slow = head;
		while (fast->next && fast->next->next)
		{
			slow = slow->next;
			fast = fast->next->next;
		}

		ListNode* pre = slow->next;
		slow->next = NULL;
		ListNode* nhead = NULL;
		while (pre)
		{
			ListNode* p = pre->next;
			pre->next = nhead;
			nhead = pre;
			pre = p;
		}

		while (head && nhead)
		{
			ListNode *next = head->next;
			head->next = nhead;
			nhead = nhead->next;
			head->next->next = next;
			head = next;
		}

	}
};

