#include<iostream>
#include<string>
#include <vector>
using namespace std;

class Solution3 {
public:
	bool isMatch(string s, string p) {
		if (p.empty()) return s.empty();
		if (p.length() == 1)
		{
			if (p[0] == '*')return true;
			else
				return(s.size() == 1 && (s[0] == p[0] || p[0] == '?'));
		}
		// worng
	}
};
class Solution2 {
public:
	bool isMatch(string s, string p) {
		string::iterator scur = s.begin(), pcur = p.begin(), sstar = p.end(), pstar = p.end();
		while (*scur) {
			if (*scur == *pcur || *pcur == '?') {
				++scur;
				++pcur;
			}
			else if (*pcur == '*') {
				pstar = pcur++;
				sstar = scur;
			}
			else if (pstar != p.end()) {
				pcur = pstar + 1;
				scur = ++sstar;
			}
			else return false;
		}
		while (*pcur == '*') ++pcur;
		return !*pcur;
	}
};

class Solution {
public:
    bool isMatch(string s, string p) {
        int m=s.length(),n=p.length();
        vector<vector<bool>> dp(m+1,vector<bool>(n+1,false));
        dp[0][0]=true;
        for(int i=1;i<=n;++i)
            if(p[i-1]=='*')
                dp[0][i]=dp[0][i-1];

        for(int i=1;i<=m;++i)
        {
            for(int j=1;j<=n;++j)
            {
                if(p[j-1]=='*')
                    dp[i][j]=dp[i-1][j] || dp[i][j-1];
                else
                    dp[i][j]=dp[i-1][j-1] && (s[i-1]==p[j-1] || p[j-1]=='?');
            }
        }

        return dp[m][n];
    }
};

