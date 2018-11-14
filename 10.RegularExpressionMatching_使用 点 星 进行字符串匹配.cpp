#include<iostream>
#include<string>

using namespace std;

class Solution2 {
public:
	bool isMatch(string s, string p) {
		if (p.empty()) return s.empty();
		if (p.size() == 1) {
			return (s.size() == 1 && (s[0] == p[0] || p[0] == '.'));
		}
		if (p[1] != '*') {
			if (s.empty()) return false;
			return (s[0] == p[0] || p[0] == '.') && isMatch(s.substr(1), p.substr(1));
		}
		while (!s.empty() && (s[0] == p[0] || p[0] == '.')) {
			if (isMatch(s, p.substr(2))) return true;
			s = s.substr(1);
		}
		return isMatch(s, p.substr(2));
	}
};


class Solution3 {
public:
	bool isMatch(string s, string p) {
		if (p.empty())
			return s.empty();
		if (p.length() == 1)
			return (s.length() == 1 && (p[0] == s[0] || p[0] == '.'));
		if (p[1] == '*')
		{
			while (!s.empty() && (p[0] == s[0] || p[0] == '.'))
			{
				if (isMatch(s, p.substr(2))) return true;
				s = s.substr(1);
			}
			return isMatch(s, p.substr(2));
		}
		else
		{
			if (!s.empty() && (p[0] == s[0] || p[0] == '.'))
				return isMatch(s.substr(1), p.substr(1));
			else
				return false;
		}
	}
};

class Solution {
public:
	bool isMatch(string s, string p) {

	}
};


int main()
{
	string s = "aa";
	string p = "a*";
	Solution n;
	cout << n.isMatch(s, p) << endl;
	return 0;
}
