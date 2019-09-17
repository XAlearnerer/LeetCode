#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;


//牛客网
//https://www.nowcoder.com/practice/a5849b7e3bc940ff8c97b47d3f76199b?tpId=101&tqId=33192&rp=0&ru=&qru=/ta/programmer-code-interview-guide/question-ranking

//题目描述
//给定一个字符串str，如果可以在str的任意位置添加字符，请返回在添加字符最少的情况下，
//让str整体都是回文字符串的一种结果。
//
//输入描述 :
//输入包含一行字符串，代表str
//
//输出描述 :
//输出一行，代表返回的字符串。
//
//示例1
//输入
//ABA
//
//输出
//ABA


void Getdp(string s, vector<vector<int>>& dp)
{
	int n = dp.size();
	for (int i = 0; i < n - 1; ++i)
	{
		if (s[i] == s[i + 1]) dp[i][i + 1] = 0;
		else dp[i][i + 1] = 1;
	}
	for (int i = n - 3; i >= 0; --i)
	{
		for (int j = i + 2; j < n; ++j)
		{
			if (s[i] == s[j]) dp[i][j] = dp[i + 1][j - 1];
			else dp[i][j] = min(dp[i + 1][j], dp[i][j - 1]) + 1;
		}
	}
}


string Getres(string s, vector<vector<int>>& dp)
{
	int n = dp.size();
	int len = n + dp[0][n - 1];
	string res(len, '0');
	int resleft = 0, resright = len - 1;
	int i = 0, j = n - 1;
	while (i <= j)
	{
		if (s[i] == s[j])
		{
			res[resleft] = s[i];
			res[resright] = s[j];
			++resleft;	++i;
			--resright;  --j;
		}
		else
		{
			if (dp[i + 1][j] > dp[i][j - 1])
			{
				res[resleft] = s[j];
				++resleft;
				res[resright] = s[j];
				--resright;  --j;
			}
			else
			{
				res[resright] = s[i];
				--resright;
				res[resleft] = s[i];
				++resleft;  ++i;
			}
		}
	}
	return res;
}

//
//int main()
//{
//	string s;
//	cin >> s;
//	//s = "ABC";
//	int n = s.size();
//	vector<vector<int>> dp(n, vector<int>(n, 0));
//	Getdp(s, dp);
//	cout << Getres(s, dp) << endl;
//
//
//	return 0;
//}
//

