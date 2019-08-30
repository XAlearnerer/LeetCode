#include<iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution1 {
public:
	ListNode* deleteDuplicates(ListNode* head) {
		if (!head || !head->next) return head;
		ListNode* cur = head;
		while (cur && cur->next)
		{
			if (cur->val == cur->next->val)
				cur->next = cur->next->next;
			else
				cur = cur->next;
		}
		return head;
	}
};


/////////////////////////////////////////////

class Solution {
public:
	ListNode* deleteDuplicates(ListNode* head) {
		if (!head || !head->next) return head;
		head->next = deleteDuplicates(head->next);
		if (head->val == head->next->val)
		{
			//head->next=head->next->next;
			return head->next;
		}
		else
			return head;
	}
};



