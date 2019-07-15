#include<iostream>
#include<vector>
#include<unordered_set>
#include<queue>

using namespace std;


class Solution {
public:
	vector<string> removeInvalidParentheses(string s) {
		vector<string> res;
		unordered_set<string> t;
		queue<string> q;
		q.push(s);

		bool found = false;

		while (!q.empty())
		{
			string cur = q.front();
			q.pop();
			if (helper(cur))
			{
				res.push_back(cur);
				//continue;
				found = true;
			}

			if (found) continue; //? 题目要求 寻找最修改最少的 字符串，已存在 成功的字符串，只需查找与其长度相同的字符串即可 

			for (int i = 0; i < cur.size(); ++i)
			{
				if (cur[i] != '(' && cur[i] != ')') continue;
				string temp = cur.substr(0, i) + cur.substr(i + 1);
				if (t.count(temp) == 0)
				{
					t.insert(temp);
					q.push(temp);
				}
			}
		}

		return res;
	}


	bool helper(string s)
	{
		int count = 0;
		for (auto i : s)
		{
			if (i == '(') ++count;
			if (i == ')')
			{
				--count;
				if (count < 0) return false;
			}
		}
		if (count == 0) return true;
		else return false;
	}

};










