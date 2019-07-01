#include<iostream>
#include<vector>
#include<stack>

using namespace std;


class Solution_2 {
public:
	int calculate(string s) {
		stack<int> t;
		int res = 0, num = 0;
		int op = 1;

		for (auto i : s)
		{
			if (i >= '0' && i <= '9')
			{
				num = num * 10 + (i - '0');
			}
			else
			{
				res += num * op;
				num = 0;
				if (i == '+')
				{
					op = 1;
				}
				else if (i == '-')
				{
					op = -1;
				}
				else if (i == '(')
				{
					t.push(res);
					t.push(op);
					res = 0;
					op = 1;
				}
				else if (i == ')')
				{
					res *= t.top();
					t.pop();
					res += t.top();
					t.pop();
				}
				else  //? OJ上提供的string中含有 ' ' 
				{
				}
			}
		}

		res += num * op;
		return res;
	}
};


//int main()
//{
//	string s = "(1+(4+5+2)-3)+(6+8)";
//	//string s = "1+1";
//	Solution n;
//	cout << n.calculate(s) << endl;
//
//	return 0;
//}




class Solution {
public:
	int calculate(string s) {
		int res = 0, num = 0, op = 1;
		for (int i = 0; i < s.size(); ++i)
		{
			if (s[i] >= '0' && s[i] <= '9')
			{
				num = num * 10 + (s[i] - '0');
			}
			char c = s[i];
			if (c == '(')
			{
				int j = i;
				int cnt = 0;
				for (; i < s.size(); ++i)
				{
					if (s[i] == '(') ++cnt;
					if (s[i] == ')') --cnt;
					if (cnt == 0) break;
				}
				num = calculate(s.substr(j + 1, i - j - 1));
			}

			if (c == '+' || c == '-' || i == s.size() - 1)
			{
				res = res + num*op;
				num = 0;
				op = c == '+' ? 1 : -1;
			}
		}

		return res;
	}
};






