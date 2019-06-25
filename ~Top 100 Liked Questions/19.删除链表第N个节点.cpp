#include<iostream>

using namespace std;


 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
	ListNode* removeNthFromEnd(ListNode* head, int n) {
		ListNode* dummy = new ListNode(-1);
		dummy->next = head;
		ListNode* begin = dummy;

		ListNode* r = head;
		for (int i = 0; i < n; ++i)
		{
			r = r->next;
		}
		ListNode* l = head;

		while (r)
		{
			r = r->next;
			l = l->next;
			begin = begin->next;
		}

		begin->next = l->next;
		return dummy->next;

	}
};
