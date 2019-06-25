#include<iostream>
#include<algorithm>
#include<string>
using namespace std;


class Solution {
public:
	bool isPalindrome(int x) {
		if (x < 0) return false;
		if (x != 0 && x % 10 == 0) return false;
		
		string s = to_string(x);
		int i = 0;
		int j = s.size() - 1;
		while (i <= j)
		{
			if (s[i] != s[j]) return false;
			++i;
			--j;
		}
		return true;
			 
	}
};



