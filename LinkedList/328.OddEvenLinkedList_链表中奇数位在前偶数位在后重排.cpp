#include <iostream>
using  namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

//Please note here we are talking about the node number and not the value in the nodes.

class Solution {
public:
	ListNode* oddEvenList(ListNode* head) {
		if (!head || !head->next) return head;
		ListNode* odd = head, *even = head->next;
		ListNode* ob=odd, *eb = even;
		int pos = 0;
		ListNode *cur = head->next->next;
		while (cur)
		{
			if (pos % 2 == 0)
			{
				odd->next = cur;
				odd = odd->next;
			}
			else
			{
				even->next = cur;
				even = even->next;
			}
			++pos;
		}

		odd->next = eb;
		even->next = NULL;

		return ob;
	}
};