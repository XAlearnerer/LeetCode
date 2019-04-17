#include<iostream>
#include<stack>
#include<vector>

using namespace std;


class Solution {
public:
	int calPoints(vector<string>& ops) {
		stack<int> s;
		for (auto i : ops)
		{
			if(i == "C")
			{
				s.pop();
			}
			else if (i == "D")
			{
				s.push(s.top() * 2);
			}
			else if (i == "+")
			{
				int a = s.top(); s.pop();
				int b = s.top(); s.pop();
				int c = a + b;
				s.push(b);
				s.push(a);
				s.push(c);
			}
			else
			{
				s.push(atoi(i.c_str()));
			}
		}

		int res = 0;
		while (!s.empty())
		{
			res += s.top();
			s.pop();
		}

		return res;
	}
};