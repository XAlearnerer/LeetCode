#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

//这道题是快慢指针的经典应用。
//只需要设两个指针，一个每次走一步的慢指针和一个每次走两步的快指针，
//如果链表里有环的话，两个指针最终肯定会相遇。实在是太巧妙了。

class Solution {
public:
	bool hasCycle(ListNode *head) {
		ListNode* fast = head,* slow = head;
		while (fast && fast->next)
		{
			fast = fast->next->next;
			slow = slow->next;
			if (fast == slow) return true;
		}
		return false;
	}
};

