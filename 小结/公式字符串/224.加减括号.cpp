#include<iostream>
#include<vector>
#include<stack>

using namespace std;


class Solution {
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
				{}
			}
		}

		res += num * op;
		return res;
	}
};


int main()
{
	string s = "(1+(4+5+2)-3)+(6+8)";
	//string s = "1+1";
	Solution n;
	cout << n.calculate(s) << endl;

	return 0;
}