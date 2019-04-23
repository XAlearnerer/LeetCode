#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;


struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	int kthSmallest(TreeNode* root, int k) {
		helper(root,k);
		return res[k - 1];
	}

	void helper(TreeNode* root, int k)
	{
		if (!root) return;
		helper(root->left, k);
		res.push_back(root->val);
		if (res.size() == k) return;
		helper(root->right, k);
	}

	vector<int> res;
};



//  Follow up :
//  What if the BST is modified(insert / delete operations) often 
//  and you need to find the kth smallest frequently ? 
//  How would you optimize the kthSmallest routine ?

//http://www.cnblogs.com/grandyang/p/4620012.html

//������һ�ַ��η���˼·������BST�����ʣ�
//���ǿ��Կ��ٶ�λ����kС��Ԫ������������������������
//�������ȼ�����������Ľ������ܺ�cnt�����kС�ڵ�������������ܺ�cnt��
//˵����kС��Ԫ�����������У�ֱ�Ӷ����ӽ����õݹ鼴�ɡ����k����cnt + 1��
//˵��Ŀ��ֵ���������У������ӽ����õݹ麯����ע���ʱ��kӦΪ k - cnt - 1��
//ӦΪ�Ѿ�������cnt + 1����㡣���k���õ���cnt + 1��˵����ǰ��㼴Ϊ����
//���ص�ǰ���ֵ���ɣ��μ��������£�



//�ⷨ����

class Solution2 {
public:
	int kthSmallest(TreeNode* root, int k) {
		int cnt = count(root->left);
		if (k <= cnt) {
			return kthSmallest(root->left, k);
		}
		else if (k > cnt + 1) {
			return kthSmallest(root->right, k - cnt - 1);
		}
		return root->val;
	}
	int count(TreeNode* node) {
		if (!node) return 0;
		return 1 + count(node->left) + count(node->right);
	}
};


//������Follow up��˵�����BST���޸ĵĺ�Ƶ����
//���Ҳ��ҵ�kСԪ�صĲ���Ҳ��Ƶ��������������Ż���
//��ʵ��õķ�������������Ľⷨ�������÷��η������ٶ�λĿ�����ڵ�λ�ã�
//����ÿ���ݹ鶼�������������н������������Ĳ���������Ч��
//��������Ӧ���޸�ԭ�����Ľṹ��ʹ�䱣�������ǰ�����������������н��ĸ�����
//��������ʹ�õ�ʱ��Ϳ��Կ��ٵõ��κ���������������������ǿ��ٶ�λĿ��ֵ�ˡ�
//�������½��ṹ�壬Ȼ���Ҫ���������������õݹ�ķ�������������
//ע�����ɵĽ���countֵҪ�ۼ��������ӽ���countֵ��Ȼ�������kСԪ�صĺ����У�
//�����������µ�����Ȼ����õݹ麯�����ڵݹ麯���У�����ֱ�ӷ������ӽ���countֵ��
//��Ϊ���ӽڽ�㲻һ�����ڣ������������жϣ�������ӽ����ڵĻ���
//��ô������ⷨ�Ĳ�����ͬ����������ڵĻ�������ʱkΪ1��ʱ��ֱ�ӷ��ص�ǰ���ֵ��
//����Ͷ����ӽ����õݹ麯����k�Լ�1���μ��������£�


// Follow up
class Solution3 {
public:
	struct MyTreeNode {
		int val;
		int count;
		MyTreeNode *left;
		MyTreeNode *right;
		MyTreeNode(int x) : val(x), count(1), left(NULL), right(NULL) {}
	};

	MyTreeNode* build(TreeNode* root) {
		if (!root) return NULL;
		MyTreeNode *node = new MyTreeNode(root->val);
		node->left = build(root->left);
		node->right = build(root->right);
		if (node->left) node->count += node->left->count;
		if (node->right) node->count += node->right->count;
		return node;
	}

	int kthSmallest(TreeNode* root, int k) {
		MyTreeNode *node = build(root);
		return helper(node, k);
	}

	int helper(MyTreeNode* node, int k) {
		if (node->left) 
		{
			int cnt = node->left->count;
			if (k <= cnt) {
				return helper(node->left, k);
			}
			else if (k > cnt + 1) {
				return helper(node->right, k - 1 - cnt);
			}
			return node->val;
		}
		else {
			if (k == 1) return node->val;
			return helper(node->right, k - 1);
		}
	}
};