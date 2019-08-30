#include<iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};


class Solution1 {
public:
	ListNode* reverseList(ListNode* head) {
		if (!head || !head->next) return head;
		ListNode* t = reverseList(head->next);
		head->next->next = head;
		head->next = NULL;
		return t;
	}
};

/////////////////


class Solution {
public:
	ListNode* reverseList(ListNode* head) {
		if (!head || !head->next) return head;
		ListNode *newHead = NULL;
		while (head) {
			ListNode *t = head->next;
			head->next = newHead;
			newHead = head;
			head = t;
		}
		return newHead;
	}
};

