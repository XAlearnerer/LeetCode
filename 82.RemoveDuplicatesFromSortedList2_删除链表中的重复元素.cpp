#include<iostream>
using namespace std;


struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

//class Solution {  //  ¾È²»»ØÀ´À²  wrong
//public:
//	ListNode* deleteDuplicates(ListNode* head) {
//		if (head == NULL) return NULL;
//		if (head->next == NULL) return head;
//		ListNode *pre = new ListNode(-1);
//		pre->next = head;
//		ListNode *a = pre;
//		ListNode *left = head;
//		ListNode *right = head->next;
//		while (right)
//		{
//			if (left->val == right->val)
//			{
//				right = right->next;
//				if (right->next == NULL)
//				{
//					if (left == right)
//						pre->next = left;
//					else
//						pre->next = NULL;
//					break;
//				}
//			}
//			else
//			{
//				if (left->next == right)
//				{
//					pre->next = left;
//					pre = pre->next;
//					left = right;
//					right = right->next;
//				}
//				else
//				{
//					left = right->next;
//					right = right->next;
//				}
//			}
//		}
//		return a->next;
//	}
//};



class Solution {
public:
	ListNode *deleteDuplicates(ListNode *head) {
		if (!head || !head->next) return head;

		ListNode *start = new ListNode(0);
		start->next = head;
		ListNode *pre = start;
		while (pre->next) {
			ListNode *cur = pre->next;
			while (cur->next && cur->next->val == cur->val) cur = cur->next;
			if (cur != pre->next) pre->next = cur->next;
			else pre = pre->next;
		}
		return start->next;
	}
};