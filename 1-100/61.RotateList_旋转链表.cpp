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
		if (head == NULL) return NULL;
		if (head->next == NULL || k == 0) return head;
		ListNode *link = head;
		int length = 1;
		while (link->next)
		{
			link = link->next;
			++length;
		}
		link->next = head;

		ListNode *begin = head;
		int i = 1;
		while (i < length - k%length)
		{
			begin = begin->next;
			++i;
		}
		ListNode *a = begin->next;
		begin->next = NULL;
		return a;
	}
};