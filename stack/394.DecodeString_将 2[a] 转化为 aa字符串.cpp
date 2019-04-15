#include<iostream>
#include<string>
#include<stack>

using namespace std;


class Solution {
public:
	string decodeString(string s) {
		stack<int> sta;
		string res;
		string cur;
		for (auto a : s)
		{
			if (a >= '0' && a <= '9')
			{
				sta.push(a);
			}

		}

	}
};