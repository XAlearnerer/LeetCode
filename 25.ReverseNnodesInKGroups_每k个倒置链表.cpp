#include<iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* reverseKGroup(ListNode* head, int k) {
		if (k == 0) return head;
		int i = 1;
		ListNode *pre = new ListNode(-1);
		pre->next = head;
		ListNode *end = head;
		ListNode *pp = pre;
		
		while (end)
		{
			if (i == k)
			{
				//cout << pre->val << " --- " << end->val << endl;
				end = rever(pre, end);
				pre = end;
				end = end->next;
				i = 1;
			}
			else {
				if (end->next == NULL) break;
				end = end->next;
				++i;
			}
		}
		return pp->next;
	}

	ListNode* rever(ListNode *Pre,ListNode *end)
	{
		ListNode *head = Pre->next;
		ListNode *End = end->next;
		ListNode *pre = head, *cur = pre->next;
		ListNode *nex;
		while (cur != End)
		{
			nex = cur->next;
			cur->next = pre;
			pre = cur;
			cur = nex;
		}
		head->next = End;
		Pre->next = pre;
		return head;
	}

};



int main2014() {
	ListNode *a = new ListNode(1);
	a->next = new ListNode(2);
	a->next->next = new ListNode(3);
	a->next->next->next = new ListNode(4);
	a->next->next->next->next = new ListNode(5);
	a->next->next->next->next->next = NULL;

	Solution n;
	ListNode *r = n.reverseKGroup(a, 6);
	
	//n.rever(a, a->next->next->next);
	//ListNode *r  = a;
	
	while (r)
	{
		cout << r->val << " -> ";
		r = r->next;
	}
	cout << endl;

	return 0;
}