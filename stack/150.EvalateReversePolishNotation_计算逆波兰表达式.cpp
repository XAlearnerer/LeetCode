#include<iostream>
#include<vector>
#include<stack>

using namespace std;


//! "-11"  

class Solution2 {  ////// worng
public:
	int evalRPN(vector<string>& tokens) {
		stack<int> s;
		for (auto c : tokens)
		{
			if (c >= "0" && c <= "9")
			{
				s.push(atoi(c.c_str()));
			}
			else
			{
				int a = s.top(); s.pop();
				int b = s.top(); s.pop();
				if (c == "+")
					s.push(a + b);
				else if (c == "-")
					s.push(a - b);
				else if (c == "*")
					s.push(a*b);
				else
					s.push(b / a);
			}
		}
		return s.top();
	}
};


class Solution {
public:
	int evalRPN(vector<string>& tokens) {
		stack<int> s;
		for (auto c : tokens)
		{
			if (c == "+" || c == "-" || c == "*" || c == "/")
			{
				int a = s.top(); s.pop();
				int b = s.top(); s.pop();
				if (c == "+")
					s.push(a + b);
				else if (c == "-")
					s.push(b - a);
				else if (c == "*")
					s.push(a*b);
				else
					s.push(b / a);
			}
			else
			{
				s.push(atoi(c.c_str()));
			}
		}
		return s.top();
	}
};
