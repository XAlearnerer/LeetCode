#include<iostream>

using namespace std;

class Solution {
public:
	bool validPalindrome(string s) {
		int left = 0, right = s.length() - 1;

		while (left <= right)
		{
			if (s[left] != s[right])
			{
				return helper(s, left + 1, right) || helper(s, left, right - 1);
			}
			++left;
			--right;
		}
		return true;
	}
	
	bool helper(string s,int i,int j)
	{
		while (i <= j)
		{
			if (s[i] != s[j]) return false;
			++i;
			--j;
		}
		return true;
	}
};

