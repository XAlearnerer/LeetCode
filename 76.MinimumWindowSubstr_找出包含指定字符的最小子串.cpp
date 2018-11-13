//
// Created by zhao on 18-11-13.
//

#include <iostream>
#include <string>
#include<unordered_map>
#include<Windows.h>
using  namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
		string res = "";
		unordered_map<char, int> letterCnt;
		int left = 0, cnt = 0, minLen = INT_MAX;
		for (char c : t) ++letterCnt[c];

		for (int i = 0; i < s.size(); ++i) {
			if (--letterCnt[s[i]] >= 0) ++cnt;
			while (cnt == t.size()) {
				if (minLen > i - left + 1) {
					minLen = i - left + 1;
					res = s.substr(left, minLen);
				}
				if (++letterCnt[s[left]] > 0) --cnt;
				++left;
			}
		}
		return res;
    }
};

class Solution2 {
public:
	string minWindow(string s, string t)
	{
		int letter[256];
		for (int i = 0; i != 256; ++i)
			letter[i] = 0;
		for (int i = 0; i != t.length(); ++i)
			++letter[t[i]];

		int left = 0, minlen = INT_MAX, cnt = 0;
		string res = "";
		for (int i = 0; i != s.length(); ++i)
		{
			if (--letter[s[i]] >= 0) 
				++cnt;
			while (cnt == t.length())
			{
				if (minlen > i - left + 1) {
					minlen = i - left + 1;
					res = s.substr(left, minlen);
				}

				if (++letter[s[left]] > 0)--cnt;
				++left;
			}
		}
		return res;
	}
};

int main2013()
{
	string s = "QADOBECODEBANC";
	string t = "ABC";
	Solution2 n;
	cout << n.minWindow(s, t) << endl;
	return 0;
}