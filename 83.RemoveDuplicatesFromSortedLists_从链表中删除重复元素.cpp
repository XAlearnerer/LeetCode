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
		if (head == NULL) return NULL;
		if (head->next == NULL) return head;
		ListNode *left = head, *right = head->next;
		while (right)
		{
			if (left->val == right->val)
			{
				right = right->next;
				if (right == NULL)
					left->next = NULL;
			}
			else
			{
				left->next = right;
				left = right;
				right = right->next;
			}
		}
		return head;
	}
};