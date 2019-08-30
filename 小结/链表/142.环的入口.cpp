#include<iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
public:
	ListNode *detectCycle(ListNode *head) {
		if (!head || !head->next) return NULL;
		ListNode* f = head, *s = head;
		bool flag = false;
		while (f && f->next)
		{
			f = f->next->next;
			s = s->next;
			if (f == s)
			{
				flag = true;
				break;
			}
		}
		if (!flag) return NULL;

		ListNode* b = head;
		while (b != s)
		{
			b = b->next;
			s = s->next;
		}

		return s;
	}
};
