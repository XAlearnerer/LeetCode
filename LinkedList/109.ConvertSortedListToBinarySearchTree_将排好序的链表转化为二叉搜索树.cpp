#include<iostream>
#include<vector>


using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};



class Solution {
public:
	TreeNode* sortedListToBST(ListNode* head) {
		if (!head) return NULL;
		return helper(head, NULL);
	}

	TreeNode* helper(ListNode* begin,ListNode* end)
	{
		if (begin == end) return NULL;
		ListNode* fast = begin, *slow = begin;
		while (fast != end && fast->next != end)
		{
			slow = slow->next;
			fast = fast->next->next;
		}

		TreeNode* cur = new TreeNode(slow->val);
		cur->left = helper(begin, slow);
		cur->right = helper(slow->next, end);

		return cur;
	}
};










class Solution2 {
public:
	TreeNode* sortedListToBST(ListNode* head) {
		if (!head) return NULL;
		return helper(head, NULL);
	}

	TreeNode* helper(ListNode* head, ListNode* tail) {
		if (head == tail) return NULL;
		ListNode *slow = head, *fast = head;
		while (fast != tail && fast->next != tail) {
			slow = slow->next;
			fast = fast->next->next;
		}
		TreeNode *cur = new TreeNode(slow->val);
		cur->left = helper(head, slow);
		cur->right = helper(slow->next, tail);
		return cur;
	}
};