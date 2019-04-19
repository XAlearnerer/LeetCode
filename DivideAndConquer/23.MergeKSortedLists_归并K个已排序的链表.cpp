#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;


struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

//0 1 2 3 4 5  -> 0 1 2  -> 0 1  -> 0
//0 1 2 3 4  -> 0 1 2 -> 0 1  -> 0

class Solution2 {
public:
	ListNode* mergeKLists(vector<ListNode*>& lists) {
		if (lists.empty()) return nullptr;
		int n = lists.size();
		
		while (n > 1) {
			int k = (n + 1) / 2;
			for (int i = 0; i < n / 2; ++i) {
				lists[i] = mergeTwo(lists[i], lists[i + k]);
			}
			n = k;
		}
		return lists[0];
	}

	ListNode *mergeTwo(ListNode* a, ListNode* b)
	{
		if (!a) return b;
		if (!b) return a;

		ListNode* cur = new ListNode(-1);
		ListNode* be = cur;
		while (a && b)
		{
			if (a->val >= b->val)
			{
				be->next = b;
				be = be->next;
				b = b->next;
			}
			else
			{
				be->next = a;
				be = be->next;
				a = a->next;
			}
		}

		while (a)
		{
			be->next = a;
			a = a->next;
			be = be->next;
		}
		while (b)
		{
			be->next = b;
			be = be->next;
			b = b->next;
		}

		return cur->next;
	}

};


class Solution {
public:
	ListNode* mergeKLists(vector<ListNode*>& lists) {
		priority_queue<ListNode*, vector<ListNode*>, cmp> q;
		for (auto i : lists)
			if(i) q.push(i);
		

		ListNode* begin = new ListNode(-1);
		ListNode* cur = begin;
		while (!q.empty())
		{
			cur->next = q.top();
			if (q.top()->next)
				q.push(q.top()->next);
			q.pop();
			cur = cur->next;
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
