
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;


//牛客
//https://www.nowcoder.com/practice/239d332c9eb741ae9e41d32b40684530?tpId=101&tqId=33193&rp=0&ru=&qru=/ta/programmer-code-interview-guide/question-ranking



//题目描述
//给定一个字符串str，再给定str的最长回文 "子序列" 字符串strlps, 请返回在添加字符最少的情况下，
//让str整体都是回文字符串的一种结果。进阶问题比原问题多了一个参数，请做到时间复杂度比原问题的实现低。
//
//输入描述 :
//输出包含两行，第一行包含一个字符串代表str
//第二行包含一个字符串，代表strips。
//
//输出描述 :
//输出一行，代表返回的值。
//
//示例1
//输入
//A1B21C
//121
//
//输出
//AC1B2B1CA
//
//说明
//str = "A1B21C"，strlps="121"，
//返回“AC1B2B1CA”或者“CA1B2B1AC”，总之，只要是添加的字符数最少，只返回其中一种结果即可。



string Getres(string& s1, string& s2)
{
	string res;
	int n = s1.length();
	int pos = 0;
	int i = 0;
	int j = n - 1;
	while (i <= j)
	{
		if (s1[i] != s2[pos])
		{
			res += s1[i];
			i++;
		}
		else if (s1[j] != s2[pos])
		{
			res += s1[j];
			j--;
		}
		else
		{
			res += s2[pos];
			pos++;
			i++;
			j--;
		}
	}

	cout << res << endl;

	string tmp = res;
	if (s2.length() % 2 != 0) res.pop_back();
	reverse(res.begin(), res.end());
	return tmp + res;
}



//int main()
//{
//	string s1, s2;
//	
//	//cin >> s1 >> s2;
//	s1 = "A1B21C";
//	s2 = "121";
//
//
//	cout << Getres(s1, s2) << endl;
//
//	return 0;
//}

