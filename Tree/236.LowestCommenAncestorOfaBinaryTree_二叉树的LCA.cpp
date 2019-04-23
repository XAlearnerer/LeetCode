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
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		if (!root) return NULL;
		if (root == q || root == p) return root;

		TreeNode* left = lowestCommonAncestor(root->left, p, q);
		TreeNode* right = lowestCommonAncestor(root->right, p, q);

		if (left && right) return root;
		if (left) return left;
		else return right;
	}
};







// ��������ֻ���ڶ�������������p��q��Ȼ���·�����ҵ����һ����ͬ�Ľڵ㼴Ϊ���ڵ㣬
// ���ǿ����õݹ���ʵ�֣��ڵݹ麯���У��������ȿ���ǰ����Ƿ�Ϊ�գ���Ϊ����ֱ�ӷ��ؿգ�
// ��Ϊp��q�е�����һ����Ҳֱ�ӷ��ص�ǰ��㡣
// ����Ļ��Ͷ��������ӽ��ֱ���õݹ麯����
// ���������������p��qһ�����ڶ������д��ڣ���ô�����ǰ��㲻����p��q��
// p��qҪô�ֱ�λ�����������У�Ҫôͬʱλ��������������ͬʱλ������������ô���Ƿֱ������ۣ�
// 
// ��p��qҪô�ֱ�λ�����������У���ô�������ӽ����õݹ麯������ֱ𷵻�p��q����λ�ã�
// ����ǰ������þ���p��q����С��ͬ����㣬ֱ�ӷ��ص�ǰ��㼴�ɣ��������Ŀ�е�����1�������
// 
// ��p��qͬʱλ�������������������������һ�������left�᷵��p��q�нϸߵ��Ǹ�λ�ã�
// ��right�᷵�ؿգ������������շ��طǿյ�left���ɣ��������Ŀ�е�����2�������
// ����һ������ǻ᷵��p��q����С����㣬����˵��ǰ�����������е�ĳ��������p��q����С����㣬
// �ᱻ���ء�
// 
// ��p��qͬʱλ����������ͬ�����������������һ�������right�᷵��p��q�нϸߵ��Ǹ�λ�ã�
// ��left�᷵�ؿգ������������շ��طǿյ�right���ɣ�����һ������ǻ᷵��p��q����С����㣬
// ����˵��ǰ�����������е�ĳ��������p��q����С����㣬�ᱻ���أ�д���ܼ�࣬�������£�

