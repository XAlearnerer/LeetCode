#include<iostream>
#include<stack>

using namespace std;

class Solution_2 {
public:
	int calculate(string s) {
		stack<int> t;
		int num = 0;
		char op = '+';

		//for (auto i : s)
		for (int i = 0; i < s.size(); ++i)
		{
			if (s[i] >= '0' && s[i] <= '9')
			{
				num = num * 10 + (s[i] - '0');
			}
			// 注意空格

			//else
			if (s[i] != ' ' && (s[i] < '0' || s[i] > '9') || i == s.size() - 1)
			{
				if (op == '+')
					t.push(num);
				else if (op == '-')
					t.push(-1 * num);
				else if (op == '*')
				{
					int p = t.top();
					t.pop();
					p *= num;
					t.push(p);
				}
				else
				{
					int p = t.top();
					t.pop();
					p /= num;
					t.push(p);
				}

				op = s[i];
				num = 0;
			}
		}

		int res = 0;
		while (!t.empty())
		{
			int p = t.top();
			res += p;
			t.pop();
		}

		return res;
	}
};




class Solution {
public:
	int calculate(string s) {
		int res = 0, num = 0;
		int cur = 0;
		char op = '+';
		for (int i = 0; i < s.size(); ++i)
		{
			if (s[i] >= '0'&&s[i] <= '9')
				num = num * 10 + (s[i] - '0');
			char c = s[i];
			if (c == '+' || c == '-' || c == '*' || c == '/' || i == s.size() - 1)
			{
				switch (op)
				{
					case '+':cur += num; break;
					case '-':cur -= num; break;
					case '*':cur *= num; break;
					case '/':cur /= num; break;

				}
				if (c == '+' || c == '-' || i == s.size() - 1)
				{
					res += cur;
					cur = 0;
				}
				op = c;
				num = 0;
			}
		}
		return res;
	}
};