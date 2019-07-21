#include<iostream>
#include<vector>
#include<string>

using namespace std;

//  "3[a2[c]]", return "accaccacc".

class Solution {
public:
	string decodeString(string s) {
		int i = 0;
		return helper(s, i);
	}

	string helper(string s, int &i)
	{
		string res;
		int n = s.size();
		while (i < n && s[i] != ']')
		{
			if (s[i]<'0' || s[i]>'9')
			{
				res += s[i]; 
				++i; 
			}
			else
			{
				int cnt = 0;
				while (s[i] >= '0' && s[i] <= '9')
				{
					cnt = 10 * cnt + (s[i] - '0');
					++i;
				}
				++i;
				string tmp = helper(s, i);
				++i;
				while (cnt-- > 0) res += tmp;
			}

		}
		return res;
	}
};



