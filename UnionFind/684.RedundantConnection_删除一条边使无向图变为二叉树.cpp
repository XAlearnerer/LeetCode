
#include<iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution2 {
public:
	vector<int> findRedundantConnection(vector<vector<int>>& edges) {
		unordered_map<int, unordered_set<int>> m;
		for (auto i : edges)
		{
			if (helper(i[0], i[1], m, -1)) return i;
			m[i[0]].insert(i[1]);
			m[i[1]].insert(i[0]);
		}
		return {};
	}

	bool helper(int cur, int tar, unordered_map<int, unordered_set<int>>& m, int pre)
	{
		if (m[cur].count(tar)) return true;
		for (auto i : m[cur])
		{
			if (i == pre) continue;
			if (helper(i, tar, m, cur)) return true;
		}

		return false;
	}
};


//��ʵUnion Find�ĺ���˼�벢���Ǻ�����⣬
//�������ǽ���һ������Ϊ(n + 1)������root��
//��������Ⲣû����ȷ��˵��n�Ƕ��٣�
//ֻ��˵������Ķ�λ����ĳ��Ȳ�����1000����ôn���Բ��ᳬ��2000��
//���Ǽ�1��ԭ�������ڽ��ֵ�Ǵ�1��ʼ�ģ��������Ǵ�0��ʼ�ģ���������ת���ˣ�
//�Ͷ��һλ���ˡ����ǽ�������鶼��ʼ��Ϊ - 1����Щ��ϲ����ʼ��Ϊi�������ԡ�
//��ʼ��ʾÿ����㶼��һ���������飬��ν��Union Find����Ҫ�ý��֮�佨��������
//������root[1] = 2���ͱ�ʾ���1�ͽ��2�������ģ�
//root[2] = 3��ʾ���2�ͽ��3�������ģ�������Ǵ�ʱ�¼�һ����[1, 3]�Ļ���
//����ͨ��root[1]�õ�2����ͨ��root[2]�õ�3��˵�����1����һ��·���ܵ����3��
//������˵�����Ǵ��ڵģ����û������·������ô����Ҫ�����1�ͽ��3����������
//��root[1] = 3���ɣ��μ��������£�



class Solution {
public:
	vector<int> findRedundantConnection(vector<vector<int>>& edges) {
		vector<int> root(2001, -1);
		for (auto i : edges)
		{
			int m = find(i[0], root);
			int n = find(i[1], root);
			if (m == n) return i;
			root[m] = n;
		}
		return {};
	}

	int find(int cur,vector<int>& root)
	{
		while (root[cur] != -1)
		{
			cur = root[cur];
		}
		return cur;
	}
};










