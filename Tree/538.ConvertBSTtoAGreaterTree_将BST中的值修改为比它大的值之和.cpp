#include<iostream>
#include<algorithm>
#include<vector>
#include<unordered_map>
#include<queue>

using namespace std;


struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:
	TreeNode* convertBST(TreeNode* root) {
		if (!root) return NULL;
		queue<TreeNode*> q;
		q.push(root);
		int sum = 0;
		while (!q.empty())
		{
			TreeNode* t = q.front();
			q.pop();
			sum += t->val;
			if (t->left) q.push(t->left);
			if (t->right) q.push(t->right);
		}

		TreeNode* be = root;
		helper(root, sum);
		return be;

	}

	void helper(TreeNode* cur, int& sum)
	{
		if (!cur) return;
		if (!cur) return;
		helper(cur->left, sum);
		sum -= cur->val;
		cur->val = sum + cur->val;
		helper(cur->right, sum);
	}



};














//�ҿ�ʼ��ķ�������������н��ֵ֮�ͣ�Ȼ��ʼ����������飬
//ͬʱ�ñ���sum����¼�ۼӺͣ�������������Ĺ������������е����顣
//����ͨ������̳�����ֻ��и�����ķ�������������������еĽ��ֵ֮�ͣ�
//��������Ľ������������ҵ�˳�������������Ҹ����˳��
//�����Ϳ��Է�������ۼӺ�sum��ͬʱ���½��ֵ����Ĳ���