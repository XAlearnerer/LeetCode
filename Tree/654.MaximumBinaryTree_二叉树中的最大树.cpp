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









//�������ֽⷨ����̳�ϵĸ߷ֽⷨ��ʹ�õ���һ����������v���ñ��ֽ���
//���Ǳ������飬����ÿ�������������֣�����һ����㣬Ȼ�����ѭ�����������v���գ�
//��ĩβ���ֵС�ڵ�ǰ���֣���ô��ĩβ���������ǰ�������ӽ�㣬
//�����Ƴ������е�ĩβ��㣬�������Ա�֤�ӽ�㶼��С�ڸ���㡣ѭ��������
//�����ʱ����v�Բ�Ϊ�գ�˵�����ֵ�ܴ���ô����ǰ�����������ĩβ�������ӽ���ϡ�
//֮������˽���ǰ����������v�У���󷵻�����v���׽�㼴�ɣ�
//
//�����̫�������Ļ����Ͱ���Ŀ�е����Ӵ���һ��һ�����п�һ�°ɣ��μ��������£�



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
