#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>

using namespace std;


class Solution2 {			//	Time Limit Exceeded
public:
	vector<int> dailyTemperatures(vector<int>& T) {
		vector<int> res;
		for (int i = 0; i != T.size() - 1; ++i)
		{
			int j = i + 1;
			int prel = res.size();
			while (j != T.size())
			{
				if (T[j] > T[i])
				{
					res.push_back(j - i);
					break;
				}
				++j;
			}
			if (prel == res.size()) res.push_back(0);
		}
		res.push_back(0);
		return res;
	}
};



class Solution {
public:
	vector<int> dailyTemperatures(vector<int>& T) {
		stack<int> s;
		vector<int> res(T.size(), 0);
		for (int i = 0; i != T.size(); ++i)
		{
			int cur = T[i];
			while (!s.empty() && cur > T[s.top()])
			{
				res[s.top()] = i - s.top();
				s.pop();
			}

			s.push(i);
		}

		return res;
	}
};