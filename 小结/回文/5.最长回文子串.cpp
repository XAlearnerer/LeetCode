#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

class Solution_ha {
public:
	string longestPalindrome(string s) {
		if (s.empty()) return "";
		if (s.size() == 1) return s;
		int pos = 0, len = 0;
		for (int i = 0; i < s.size() - 1; ++i)
		{
			//就是要注意奇偶情况，由于回文串的长度可奇可偶，
			//比如 "bob" 是奇数形式的回文，"noon" 就是偶数形式的回文，
			//两种形式的回文都要搜索
			helper(s, i, i, pos, len);
			helper(s, i, i + 1, pos, len);
		}
		return s.substr(pos, len);
	}

	void helper(string s, int l, int r, int& pos, int& len)
	{
		while (l >= 0 && r < s.size() && s[l] == s[r])
		{
			--l; ++r;
		}

		if (r - l - 1 > len)
		{
			pos = l + 1;
			len = r - l - 1;
		}
	}
};


//////////////////////////////////////////////////////////////////////////////

// 其中 dp[i][j] 表示字符串区间[i, j] 是否为回文串，
// 当 i = j 时，只有一个字符，肯定是回文串，
// 如果 i = j + 1，说明是相邻字符，此时需要判断 s[i] 是否等于 s[j]，
// 如果i和j不相邻，即 i - j >= 2 时，除了判断 s[i] 和 s[j] 相等之外，
// dp[i + 1][j - 1] 若为真，就是回文串，通过以上分析，可以写出递推式如下：
// 
// dp[i, j] = 1                          if i == j
// 
// = s[i] == s[j]                        if j = i + 1
// = s[i] == s[j] && dp[i + 1][j - 1]    if j > i + 1


class Solution_dp {
public:
	string longestPalindrome(string& s) {
		if (s.empty()) return "";
		int n = s.size();
		vector<vector<int>> dp(n, vector<int>(n, 0));
		int left = 0, len = 1;
		for (int i = 0; i < n; ++i)
		{
			dp[i][i] = 1;
			for (int j = 0; j < i; ++j)
			{
				if (i - j < 2)
				{
					if (s[i] == s[j])
					{
						dp[j][i] = 1;

						if (i - j + 1 > len)
						{
							len = i - j + 1;
							left = j;
						}
					}
				}
				else
				{
					if (s[i] == s[j] && dp[j + 1][i - 1] == 1)
					{
						dp[j][i] = 1;

						if (i - j + 1 > len)
						{
							len = i - j + 1;
							left = j;
						}
					}
				}
			}
		}

		return s.substr(left, len);
	}
};




//////////////////////////////////////////////////////////////////////////////

class Solution_mlc_web {
public:
	string longestPalindrome(string s) {
		string cur = "$#";
		for (int i = 0; i < s.size(); ++i) {
			cur += s[i];
			cur += "#";
		}

		vector<int> p(cur.size(), 0);
		int id = 0, mx = 0;
		int resid = 0, reslen = 0;

		for (int i = 1; i < cur.size(); ++i)
		{
			if (mx > i) p[i] = min(p[2 * id - i], mx - i);
			else p[i] = 1;
			while (cur[p[i] + i] == cur[i - p[i]]) ++p[i];

			if (p[i] + i > mx)
			{
				mx = p[i] + i;
				id = i;
			}
			if (reslen < p[i])
			{
				reslen = p[i];
				resid = i;
			}
		}

		return s.substr((resid - reslen) / 2, reslen - 1);
	}
};



//比如 "bob" 是奇数形式的回文，"noon" 就是偶数形式的回文，
//马拉车算法的第一步是预处理，做法是在每一个字符的左右都加上一个特殊字符，
//比如加上 '#'，那么
//bob-->    #b#o#b#
//noon-->   #n#o#o#n# 
//这样做的好处是不论原字符串是奇数还是偶数个，处理之后得到的字符串的个数都是奇数个，


//"#b#o#b#"，我们很容易看出来以中间的 'o' 为中心的回文串的半径是4，而 "bob"的长度是3，
//"#n#o#o#n#"，以最中间的 '#' 为中心的回文串的半径是5，而 "noon" 的长度是4
//
//
//"#1#2#2# 1 #2#2#" 中的位置是7，而半径是6，貌似 7-6=1，
//刚好就是回文子串 "22122" 在原串 "122122" 中的起始位置1。
//那么我们再来验证下 "bob"，"o" 在 "#b#o#b#" 中的位置是3，但是半径是4，
//这一减成负的了，肯定不对。

//所以我们应该至少把中心位置向后移动一位，才能为0啊，那么我们就需要在前面增加一个字符

//////////////////////////////////////////////////////////////////////
//!!! 最长子串的长度是半径减1，起始位置是中间位置减去半径再除以2。
//"$#1#2#2#1#2#2#" : (8 - 6) / 2;
//"$#b#o#b#" : (4 - 4) / 2 = 0;
//////////////////////////////////////////////////////////////////////

//需要新增两个辅助变量 mx 和 id，
//其中 id 为能延伸到最右端的位置的那个回文子串的中心点位置，
//mx 是回文串能延伸到的最右端的位置，
//需要注意的是，这个 mx 位置的字符不属于回文串，
//所以才能用 mx - i 来更新 p[i] 的长度而不用加1，



//https://www.cnblogs.com/grandyang/p/4475985.html



class Solution {
public:
	string longestPalindrome(string& s) {
		string cur = "$#";
		for (int i = 0; i < s.size(); ++i) {
			cur += s[i];
			cur += "#";
		}

		vector<int> p(cur.size(), 0);
		int id = 0, mx = 0;
		int resid = 0, reslen = 0;

		for (int i = 1; i < cur.size(); ++i)
		{
			if (mx > i)
			{
				int j = 2 * id - i;
				//p[i] = min(p[2 * id - i], mx - i);
				if (mx - i > p[j]) p[i] = p[j];
				else p[i] = mx - i;
			}
			else p[i] = 1;
			while (cur[p[i] + i] == cur[i - p[i]]) ++p[i];

			if (p[i] + i > mx)
			{
				mx = p[i] + i;
				id = i;
			}
			if (reslen < p[i])
			{
				reslen = p[i];
				resid = i;
			}
		}

		return s.substr((resid - reslen) / 2, reslen - 1);
	}
};


//int main()
//{
//	string s = "babad";
//	Solution n;
//	cout << n.longestPalindrome(s) << endl;
//	return 0;
//}




