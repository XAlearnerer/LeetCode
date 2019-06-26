#include<iostream>
#include<vector>
#include<queue>

using namespace std;


struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* mergeKLists(vector<ListNode*>& lists) {
		priority_queue<ListNode*, vector<ListNode*>, cmp> q;
		for (int i = 0; i < lists.size(); ++i)
			if(lists[i]) q.push(lists[i]);
		ListNode* dummy = new ListNode(-1);
		ListNode* begin = dummy;
		while (!q.empty())
		{
			auto i = q.top();
			q.pop();
			dummy->next = i;
			i = i->next;
			if (i) q.push(i);
			dummy = dummy->next;
		}
		return begin->next;

	}

	struct cmp
	{
		bool operator()(ListNode* a, ListNode* b)
		{
			return a->val > b->val;
		}
	};

};