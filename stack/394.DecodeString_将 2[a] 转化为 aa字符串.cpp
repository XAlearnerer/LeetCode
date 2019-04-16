#include<iostream>
#include<string>
#include<stack>

using namespace std;


class Solution2 {
public:
	string decodeString(string s) {
		int i = 0;
		return helper(s, i);
	}

	string helper(string s, int& i)
	{
		int n = s.size();
		string res;
		while (i < n && s[i] != ']')
		{
			if (s[i] > '9' || s[i] < '0')
			{
				res += s[i];
				++i;
			}
			else
			{
				int times = 0;
				while (s[i] >= '0' && s[i] <= '9')
				{
					times = times * 10 + (s[i] - '0');
					++i;
				}
				++i;
				string cur = helper(s, i);
				while (times > 0)
				{
					res += cur;
					--times;
				}
				++i;
			}
		}
		return res;
	}
};

class Solution {
public:
	string decodeString(string s) {
		stack<int> numstack;
		stack<string> prestack;
		string cur = "";
		int times = 0;

		for (int i = 0; i != s.size(); ++i)
		{
			if (s[i] >= '0' && s[i] <= '9')
			{
				times = times * 10 + (s[i] - '0');
			}
			else if (s[i] == '[')
			{
				numstack.push(times);
				times = 0;
				prestack.push(cur);
				cur.clear();
			}
			else if (s[i] == ']')
			{
				int t = numstack.top();
				numstack.pop();
				string sc = prestack.top();
				prestack.pop();
				while (t--)
				{
					sc += cur;
				}
				cur = sc;
			}
			else
			{
				cur += s[i];
			}
		}
		return cur;

	}
};

//int main()
//{
//	string s = "3[a]2[bc]";
//	Solution n;
//	cout << n.decodeString(s) << endl;
//
//	return 0;
//}
//
//





