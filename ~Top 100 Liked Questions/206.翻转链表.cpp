#include<iostream>

using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};



class Solution {
public:
	ListNode* reverseList(ListNode* head) {
		if (!head || !head->next) return head;
		ListNode* dummy = new ListNode(-1);
		dummy->next = head;
		
		ListNode* cur = head, *post = head->next;
		while (post)
		{
			ListNode* pn = post->next;
			post->next = cur;
			cur = post;
			post = pn;
		}
		
		dummy->next->next = NULL;
		return cur;

	}
};




