
#include<iostream>
#include<stack>

using namespace std;


class Solution {
public:
	bool isValid(string s) {
		stack<char> sta;
		for (auto i : s)
		{
			//if(sta.empty()) sta.push(i);
			if (i == '(' || i == '[' || i == '{') sta.push(i);
			else
			{
				if (sta.empty()) return false;
				char c = sta.top();
				//if (i == '(' && c != ')') return false;
				//if (i == '[' && c != ']') return false;
				//if (i == '{' && c != '}') return false;
				//sta.pop();
				if (i == ')')
				{
					if (c != '(') return false;
				}
				else if (i == ']')
				{
					if (c != '[') return false;
				}
				else
				{
					if (c != '{') return false;
				}
				sta.pop();
			}
		}
		if(sta.empty()) return true;
		else return false;
	}
};