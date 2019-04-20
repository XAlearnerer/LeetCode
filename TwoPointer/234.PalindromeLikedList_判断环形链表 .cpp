#include<iostream>
#include<string>
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
	bool isPalindrome(ListNode* head) {
		if (!head) return true;
		vector<int> v;
		while (head)
		{
			v.push_back(head->val);
			head = head->next;
		}

		int i = 0, j = v.size() - 1;
		while (i < j)
		{
			if (v[i] != v[j]) return false;
			++i;
			--j;
		}
		return true;
	}
};

