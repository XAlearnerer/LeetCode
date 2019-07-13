#include<iostream>
#include<stack>

using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

//
//class Solution_worng { 
//	//?  Memory Limit Exceeded
//public:
//	bool isPalindrome(ListNode* head) {
//		ListNode* f = head, *s = head;
//		while (f && f->next)
//		{
//			f = f->next->next;
//			s = s->next;
//		}
//		ListNode* s2 = s;
//		stack<int> t;
//		while (s)
//		{
//			t.push(s->val);
//		}
//		ListNode* b = head;
//		while (b != s2)
//		{
//			int p = t.top();
//			t.pop();
//			if (p != b->val) return false;
//			b = b->next;
//		}
//
//		return true;
//	}
//};



class Solution {
public:
	bool isPalindrome(ListNode* head) {
		if (!head || !head->next) return true;
		ListNode* f = head, *s = head;
		//while (f && f->next)
		while(f->next && f->next->next)
		{
			f = f->next->next;
			s = s->next;
		}

		s->next = helper(s->next);
		s = s->next;
		ListNode* b = head;
		while (s)
		{
			if (b->val != s->val) return false;
			b = b->next;
			s = s->next;
		}


		return true;
	}

	ListNode* helper(ListNode* head)
	{
		ListNode* pre = NULL, *next = NULL;
		while (head)
		{
			next = head->next;
			head->next = pre;
			pre = head;
			head = next;
		}
		return pre;
	}
};






