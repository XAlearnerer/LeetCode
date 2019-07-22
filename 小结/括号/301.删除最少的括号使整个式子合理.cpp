#include<iostream>
#include<vector>
#include<queue>
#include<unordered_set>
#include<string>

using namespace std;


class Solution {
public:
	vector<string> removeInvalidParentheses(string s) {
		vector<string> res;
		unordered_set<string> t;
		queue<string> q;
		q.push(s);
		bool flag = false;
		while (!q.empty())
		{
			string cur = q.front();
			q.pop();
			if (check(cur))
			{
				res.push_back(cur);
				flag = true;
			}
			if (flag) continue;



			for (int i = 0; i < cur.size(); ++i)
			{
				if (cur[i] != '(' && cur[i] != ')') continue;
				string tmp = cur.substr(0, i) + cur.substr(i + 1);
				if (t.count(tmp) == 0)
				{
					t.insert(tmp);
					q.push(tmp);
				}
			}
		}

		return res;
	}


	bool check(string s)
	{
		int cnt = 0;
		for (auto i : s)
		{
			if (i == '(') ++cnt;
			else if (i == ')')
			{
				--cnt;
				if (cnt < 0) return false;
			}
			else continue;
		}
		if (cnt == 0) return true;
		else return false;
	}

};

