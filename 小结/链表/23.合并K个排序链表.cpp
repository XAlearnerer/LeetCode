#include<iostream>
#include<vector>
#include<queue>
#include<functional>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*/
class Solution {
public:
	ListNode* mergeKLists(vector<ListNode*>& lists) {
		priority_queue<ListNode*, vector<ListNode*>, cmp> q;
		for (auto i : lists)
			if (i) q.push(i);
		ListNode* dummy = new ListNode(-1);
		ListNode* res = dummy;
		while (!q.empty())
		{
			ListNode* cur = q.top();
			q.pop();
			dummy->next = cur;
			dummy = dummy->next;
			if (cur->next) q.push(cur->next);
		}

		return res->next;
	}

	struct cmp
	{
		bool operator()(ListNode* a, ListNode* b)
		{
			return a->val > b->val;
		}
	};

};






