
#include<iostream>

using namespace std;

 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };


 class Solution {
 public:
	 ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		 if (!l1) return l2;
		 if (!l2) return l1;
		 int carry = 0;
		 ListNode* dummy = new ListNode(-1);
		 ListNode* res = dummy;

		 //while (l1 && l2)
		 while (l1 || l2)
		 {
			 int a = 0, b = 0;
			 if (l1) a = l1->val;
			 if (l2) b = l2->val;
			 int num = a + b + carry;
			 carry = num / 10;
			 num = num % 10;
			 ListNode* cur = new ListNode(num);
			 res->next = cur;
			 res = res->next;
			 if (l1) l1 = l1->next;
			 if (l2) l2 = l2->next;
		 }

		 if (carry == 1)
			 res->next = new ListNode(1);

		 return dummy->next;
	 }
 };