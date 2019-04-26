#include<iostream>
#include<algorithm>
#include<vector>
#include<unordered_set>
#include<queue>
#include<string>

using namespace std;


struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//class Solution {
//public:
//	TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
//		if (nums.size() == 0) return NULL;
//		return helper(nums);
//	}
//
//	TreeNode* helper(vector<int>& n)
//	{
//		if (n.size() == 0) return NULL;
//		auto i = max_element(n.begin(), n.end());
//		TreeNode* cur = new TreeNode(*i);
//		if (n.begin() < i)
//		{
//			vector<int> l(n.begin(), i);
//			cur->left = helper(l);
//		}
//		else
//		{
//			vector<int> l(0);
//			cur->left = helper(l);
//		}
//
//		if (i + 1 < n.end())
//		{
//			vector<int> r(i + 1, n.end());
//			cur->left = helper(r);
//		}
//		else
//		{
//			vector<int> r(0);
//			cur->right = helper(r);
//		}
//
//		return cur;
//	}
//
//};


class Solution2 {
public:
	TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
		if (nums.empty()) return NULL;
		return helper(nums, 0, nums.size() - 1);
	}

	TreeNode* helper(vector<int> nums, int left, int right)
	{
		if (left > right) return NULL;
		auto mid = max_element(nums.begin() + left, nums.begin() + right + 1);
		TreeNode* cur = new TreeNode(nums[mid - nums.begin()]);
		cur->left = helper(nums, left, mid - nums.begin() - 1);
		cur->right = helper(nums, mid - nums.begin() + 1, right);
		return cur;
	}
};

class Solution {
public:
	TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
		if (nums.empty()) return NULL;
		return helper(nums, 0, nums.size() - 1);
	}
	TreeNode* helper(vector<int>& nums, int left, int right) {
		if (left > right) return NULL;
		int mid = left;
		for (int i = left + 1; i <= right; ++i) {
			if (nums[i] > nums[mid]) {
				mid = i;
			}
		}
		TreeNode *node = new TreeNode(nums[mid]);
		node->left = helper(nums, left, mid - 1);
		node->right = helper(nums, mid + 1, right);
		return node;
	}
};









//下面这种解法是论坛上的高分解法，使用到了一个辅助数组v来让保持降序。
//我们遍历数组，对于每个遍历到的数字，创建一个结点，然后进行循环，如果数组v不空，
//且末尾结点值小于当前数字，那么将末尾结点连到当前结点的左子结点，
//并且移除数组中的末尾结点，这样可以保证子结点都会小于父结点。循环结束后，
//如果此时数组v仍不为空，说明结点值很大，那么将当前结点连到数组末尾结点的右子结点上。
//之后别忘了将当前结点加入数组v中，最后返回数组v的首结点即可，
//
//如果不太容易理解的话，就把题目中的例子带入一步一步运行看一下吧，参见代码如下：



class Solution3 {
public:
	TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
		vector<TreeNode*> v;
		for (int num : nums) {
			TreeNode *cur = new TreeNode(num);
			while (!v.empty() && v.back()->val < num) {
				cur->left = v.back();
				v.pop_back();
			}
			if (!v.empty()) {
				v.back()->right = cur;
			}
			v.push_back(cur);
		}
		return v.front();
	}
};
