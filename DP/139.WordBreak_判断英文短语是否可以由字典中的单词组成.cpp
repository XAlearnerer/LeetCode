#include<iostream>
#include<string>
#include<vector>
#include<unordered_set>
#include<queue>

using namespace std;

//����ʹ�ü�������memo�ĵݹ�д������ʹ��dp����ĵ���д�����˽��������������
//��������dp����⣬һ��Ҳ���ü�������ĵݹ�ⷨ

//��������������ַ�������ֵ���⣬��������DPû���ˣ���Ȼ�����û����ֵ��
//���������ַ���Ҳ����DP��״̬ת�Ƶ��ص㡣

class Solution2 {
public:
	bool wordBreak(string s, vector<string>& wordDict) {
		unordered_set<string>set(wordDict.begin(), wordDict.end());
		vector<bool> dp(s.length() + 1, false);
		dp[0] = true;
		for (int i = 1; i < dp.size(); ++i)
		{
			for (int j = 0; j < i; ++j)
			{
				if (set.count(s.substr(j, i - j)) && dp[j] == 1)
				{
					dp[i] = true;
					break;
				}
			}
		}
		return dp.back();
	}
};


class Solution {
public:
	bool wordBreak(string s, vector<string>& wordDict) {
		unordered_set<string>set(wordDict.begin(), wordDict.end());
		queue<int> q;
		vector<bool> v(s.size());
		q.push(0);
		while (!q.empty())
		{
			int start = q.front();
			q.pop();
			if (v[start] != true)
			{
				for (int i = start + 1; i != s.size() + 1; ++i)
				{
					if (set.count(s.substr(start, i - start)))
					{
						q.push(i);
						if (i == s.size()) return true;
					}
				}
				v[start] = true;
			}
		}
		return false;
	}
};

