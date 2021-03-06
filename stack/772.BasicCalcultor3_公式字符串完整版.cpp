#include<iostream>
#include<stack>
#include<string>

using namespace std;


//  Implement a basic calculator to evaluate a simple expression string.
//  
//  The expression string may contain open(and closing parentheses), 
//  the plus + or minus sign - , non - negative integers and empty spaces .
//  
//  The expression string contains only non - negative integers, +, -, *, / operators, 
//  open(and closing parentheses) and empty spaces.
//  The integer division should truncate toward zero.
//  
//  You may assume that the given expression is always valid.
//  All intermediate results will be in the range of[-2147483648, 2147483647].
//  
//  Some examples :
//  
//  "1 + 1" = 2
//  " 6-4 / 2 " = 4
//  "2*(5+5*2)/3+(6/2+8)" = 21
//  "(2+6* 3+5- (3*14/7+2)*5)+3" = -12
//  
//  
//  Note : Do not use the eval built - in library function.




class Solution {
public:
	int calculate(string s) {
		int n = s.size(), num = 0, curRes = 0, res = 0;
		char op = '+';
		for (int i = 0; i < n; ++i)
		{
			char c = s[i];
			if (c >= '0' && c <= '9')
			{
				num = num * 10 + c - '0';
			}
			else if (c == '(')
			{
				int j = i, cnt = 0;
				for (; i < n; ++i) {
					if (s[i] == '(') ++cnt;
					if (s[i] == ')') --cnt;
					if (cnt == 0) break;
				}

		// 这里就有一个小trick，由于表示可能会有括号嵌套括号，
		// 所以我们如果搜索右括号的话，就有可能使得括号没有正确的匹配上，
		// 所以我们用一个变量cnt，遇到左括号自增1，遇到右括号自减1，
		// 当cnt为0的时候，说明括号正好完全匹配，
		// 这个trick在验证括号是否valid的时候经常使用到


				num = calculate(s.substr(j + 1, i - j - 1));
			}

			if (c == '+' || c == '-' || c == '*' || c == '/' || i == n - 1)
			{
				switch (op)
				{
					case '+': curRes += num; break;
					case '-': curRes -= num; break;
					case '*': curRes *= num; break;
					case '/': curRes /= num; break;
				}
				if (c == '+' || c == '-' || i == n - 1)
				{
					res += curRes;
					curRes = 0;
				}
				op = c;
				num = 0;
			}
		}
		return res;
	}
};