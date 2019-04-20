#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

class Solution {
public:
	bool isPalindrome(string s) {
		if (s.empty()) return true;
		for (auto& i : s)
			i = tolower(i);
		cout << s << endl;
		int i = 0, j = s.size() - 1;
		while (i < j)
		{
			while (!isalnum(s[i]) && i < j) ++i;
			while (!isalnum(s[j]) && i < j) --j;
			if (s[i] != s[j])
			{
				return false;
			}
			++i;
			--j;
		}
		return true;
	}
};
