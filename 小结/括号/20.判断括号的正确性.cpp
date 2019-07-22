#include<iostream>
#include<stack>

using namespace std;

class Solution {
public:
	bool isValid(string s) {
		if (s.empty()) return true;
		stack<char> t;
		for (int i = 0; i < s.size(); ++i)
		{
			if (s[i] == '(' || s[i] == '[' || s[i] == '{')
			{
				t.push(s[i]);
			}
			else
			{
				if (t.empty()) return false;
				char p = t.top();
				t.pop();
				if (s[i] == ')')
				{
					if (p != '(') return false;
				}
				else if (s[i] == ']')
				{
					if (p != '[') return false;
				}
				else
				{
					if (p != '{') return false;
				}
			}

		}
		if (!t.empty()) return false;
		return true;

	}
};
