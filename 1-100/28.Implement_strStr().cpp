#include<iostream>
using namespace std;
#include<string>

//Part of the comment  ---  Time Limit Exceeded
// still don't known why
class Solution {
public:
	int strStr(string haystack, string needle) {
		if (needle.empty()) return 0;
		if (haystack.length() < needle.length()) return -1;
		int nlength = needle.length();
		int i = 0;
		while (i + nlength <= haystack.length())
		{
			//if (haystack[i] == needle[0])
			//{
			//	int j = 1;
			//	while (j != nlength)
			//	{
			//		if (haystack[i + j] != needle[j]) break;
			//		++j;
			//	}
			//	if (j == nlength) return i;
			//}

			int j = 0;
			for (j = 0; j < nlength; ++j) {
				if (haystack[i + j] != needle[j]) break;
			}
			if (j == nlength) return i;
			//else ++i;
			++i;
		}
		return -1;

	}
};


class Solution2 {
public:
	int strStr(string haystack, string needle) {
		if (needle.empty()) return 0;
		int m = haystack.size(), n = needle.size();
		if (m < n) return -1;
		for (int i = 0; i <= m - n; ++i) {
			int j = 0;
			for (j = 0; j < n; ++j) {
				if (haystack[i + j] != needle[j]) break;
			}
			if (j == n) return i;
		}
		return -1;
	}
};


int main1022()
{
	string s1 = "a";
	string s2 = "a";
	Solution n;
	cout << n.strStr(s1, s2) << endl;
	return 0;
}