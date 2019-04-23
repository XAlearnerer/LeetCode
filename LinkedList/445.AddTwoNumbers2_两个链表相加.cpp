#include<iostream>
#include<algorithm>

using namespace std;


struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		ListNode* cur = NULL;
		while (l1)
		{
			ListNode *ne = l1->next;
			l1->next = cur;
			cur = l1;
			l1 = ne;
		}
		ListNode* lfirst = cur;

		cur = NULL;
		while (l2)
		{
			ListNode *ne = l2->next;
			l2->next = cur;
			cur = l2;
			l2 = ne;
		}
		ListNode* lsecond = cur;

		ListNode *res = new ListNode(-1);
		ListNode* res2 = res;
		int carry = 0;
		while (lfirst || lsecond || carry)
		{
			int sum = 0;
			if (lfirst) { sum = sum + lfirst->val; lfirst = lfirst->next; }
			if (lsecond) { sum += lsecond->val; lsecond = lsecond->next; }
			sum += carry;
			carry = sum / 10;
			sum = sum % 10;
			ListNode* c = new ListNode(sum);

			res->next = c;
			res = res->next;
		}
		res = NULL;
		cur = NULL;
		while (res2->next)
		{
			ListNode *ne = res2->next->next;
			res2->next->next = cur;
			cur = res2->next;
			res2->next = ne;
		}
		return cur;
	}
};

