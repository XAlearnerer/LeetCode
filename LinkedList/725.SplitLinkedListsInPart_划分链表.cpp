#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;


struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
public:
	vector<ListNode*> splitListToParts(ListNode* root, int k) {
		vector<ListNode*> res(k, NULL);
		int nums = 0;

		ListNode* be = root;

		while (be)
		{
			++nums;
			be = be->next;
		}
		int eve = nums / k, act = nums%k;

		for (int i = 0; i != k && root; ++i)
		{
			res[i] = root;
			for (int j = 1; j < eve + (i < act); ++j)
			{
				root = root->next;
			}
			ListNode *cur = root->next;
			root->next = NULL;
			root = cur;
		}
		return res;
	}
};