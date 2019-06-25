#include<iostream>
#include<algorithm>

using namespace std;


class Solution {
public:
	bool isMatch(string s, string p) {
		if (p.empty()) return s.empty();
		if (p.size() == 1)
		{
			if (s.size() == 1 && (s[0] == p[0] || p[0] == '.')) return true;
			else return false;
		}

		if (p[1] != '*')
		{
			if (s.empty()) return false;
			if (s[0] == p[0] || p[0] == '.') return isMatch(s.substr(1), p.substr(1));
			else return false;
		}
		while (!s.empty() && (s[0] == p[0] || p[0] == '.'))
		{
			if (isMatch(s, p.substr(2))) return true;
			s = s.substr(1);
		}
		return isMatch(s, p.substr(2));
	}
};





