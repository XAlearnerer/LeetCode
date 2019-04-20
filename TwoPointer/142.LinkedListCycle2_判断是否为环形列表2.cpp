#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode *detectCycle(ListNode *head) {
		ListNode* fast = head, *slow = head;
		while (fast && fast->next)
		{
			slow = slow->next;
			fast = fast->next->next;
			if (fast == slow) break;
		}

		if (!fast || !fast->next) return NULL;

		ListNode* cur = head;
		while (1)
		{
			if (cur == fast) break;
			cur = cur->next;
			fast = fast->next;
		}
		return cur;
	}
};

