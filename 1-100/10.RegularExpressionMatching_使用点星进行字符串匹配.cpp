#include<iostream>
#include<string>
#include <vector>
using namespace std;


class Solution2 {
public:
	bool isMatch(string s, string p) {
		if (p.empty()) return s.empty();
		if (p.size() == 1) {
			return (s.size() == 1 && (s[0] == p[0] || p[0] == '.'));
		}
		if (p[1] != '*') {
			if (s.empty()) return false;
			return (s[0] == p[0] || p[0] == '.') && isMatch(s.substr(1), p.substr(1));
		}
		while (!s.empty() && (s[0] == p[0] || p[0] == '.')) {
			if (isMatch(s, p.substr(2))) return true;
			s = s.substr(1);
		}
		return isMatch(s, p.substr(2));
	}
};


class Solution3 {
public:
	bool isMatch(string s, string p) {
		if (p.empty())
			return s.empty();
		if (p.length() == 1)
			return (s.length() == 1 && (p[0] == s[0] || p[0] == '.'));
		if (p[1] == '*')
		{
			while (!s.empty() && (p[0] == s[0] || p[0] == '.'))
			{
				if (isMatch(s, p.substr(2))) return true;
				s = s.substr(1);
			}
			return isMatch(s, p.substr(2));
		}
		else
		{
			if (!s.empty() && (p[0] == s[0] || p[0] == '.'))
				return isMatch(s.substr(1), p.substr(1));
			else
				return false;
		}
	}
};

class Solution4 {
public:
	bool isMatch(string s, string p) {
		int m = s.length(), n = p.length();
		vector<vector<bool> > dp(m + 1, vector<bool> (n + 1, false));
		dp[0][0] = true;
		for (int i = 0; i <= m; i++)
			for (int j = 1; j <= n; j++)
				if (p[j - 1] == '*')
					dp[i][j] = dp[i][j - 2] || (i > 0 && (s[i - 1] == p[j - 2] || p[j - 2] == '.') && dp[i - 1][j]);
				else dp[i][j] = i > 0 && dp[i - 1][j - 1] && (s[i - 1] == p[j - 1] || p[j - 1] == '.');
		return dp[m][n];
	}
};

class Solution {
public:
	bool isMatch(string s, string p) {
		int m=s.length(),n=p.length();
		vector<vector<bool>> dp(m+1,vector<bool>(n+1,false));
		dp[0][0]=true;
		for(int i=2;i<n+1;++i)
		{
			if(p[i-1]=='*')
				dp[0][i]=dp[0][i-2];
		}
		for(int i=1;i<m+1;++i)
		{
			for(int j=1;j<n+1;++j)
			{
				if(p[j-1]=='*' && j>1)
					dp[i][j]= (dp[i-1][j] && (s[i-1]==p[j-2] || p[j-2]=='.')) || dp[i][j-2];
				else
					dp[i][j]=dp[i-1][j-1] && (s[i-1]==p[j-1] || p[j-1]=='.');
			}
		}
		return dp[m][n];
	}
};

int main1058()
{
	string s = "a";
	string p = "";
	Solution n;
	cout << n.isMatch(s, p) << endl;
	return 0;
}
