#include<iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* rotateRight(ListNode* head, int k) {
		if (!head) return head;
		if (!head->next) return head;

		ListNode* be = head;
		int n = 0;
		while (be) {
			be = be->next;
			++n;
		}
		k %= n;
		if (k == 0) return head;


		ListNode* pre = head, *post = head;
		for (int i = 0; i<k; ++i)
		{
			if (post)
				post = post->next;
		}
		if (!post) return NULL;

		while (post->next)
		{
			post = post->next;
			pre = pre->next;
		}

		ListNode* t = pre->next;
		pre->next = NULL;
		post->next = head;

		return t;
	}
};


