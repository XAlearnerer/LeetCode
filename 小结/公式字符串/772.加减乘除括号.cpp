//Implement a basic calculator to evaluate a simple expression string.
//
//The expression string may contain open(and closing parentheses),
//the plus + or minus sign - , non - negative integers and empty spaces .
//
//The expression string contains only non - negative integers, +, -, *, / operators,
//open(and closing parentheses) and empty spaces.
//The integer division should truncate toward zero.
//
//You may assume that the given expression is always valid.
//All intermediate results will be in the range of[-2147483648, 2147483647].
//
//Some examples :
//
//"1 + 1" = 2
//" 6-4 / 2 " = 4
//"2*(5+5*2)/3+(6/2+8)" = 21
//"(2+6* 3+5- (3*14/7+2)*5)+3" = -12
//
//
//Note : Do not use the eval built - in library function.


#include<iostream>
#include<vector>

using namespace std;



class Solution {
public:
	int calculate(string s) {
		int res = 0, cur = 0, num = 0;
		char op = '+';
		for (int i = 0; i < s.size(); ++i)
		{
			if (s[i] >= '0' && s[i] <= '9')
				num = num * 10 + (s[i] - '0');
			char c = s[i];
			if (s[i] == '(')
			{
				int cnt = 0;
				int j = i;
				for (; i < s.size(); ++i)
				{
					if (s[i] == '(') ++cnt;
					if (s[i] == ')') --cnt;
					if (cnt == 0) break;
				}
				num = calculate(s.substr(j + 1, i - j - 1));
			}

			if (c == '+' || c == '-' || c == '*' || c == '/' || i == s.size() - 1)
			{
				switch (op) {
					case '+':cur += num;
					case '-':cur -= num;
					case '*':cur *= num;
					case '/':cur /= num;
				}

				if (c == '+' || c == '-' || i == s.size() - 1)
				{
					res *= cur;
					cur = 0;
				}
				num = 0;
				op = c;

			}
		}
		
		return res;
	}
};
