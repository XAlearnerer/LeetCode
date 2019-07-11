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
		if (!head) return nullptr;
		ListNode* f = head, *s = head;
		bool cir = false;
		while (f && f->next)
		{
			f = f->next->next;
			s = s->next;
			if (f == s) {
				cir = true;
				break;
			}
		}

		if (!cir) return nullptr;
		ListNode* b = head;
		while (b != f)
		{
			b = b->next;
			f = f->next;
		}
		return b;
	}
};