#include<iostream>
#include<string>
using namespace std;

class Solution2 {
public:
	bool isMatch(string s, string p) {
		if (p.empty()) return s.empty();
		if (p.length() == 1)
		{
			if (p[0] == '*')return true;
			else
				return(s.size() == 1 && (s[0] == p[0] || p[0] == '?'));
		}
		// worng
	}
};
class Solution {
public:
	bool isMatch(string s, string p) {
		string::iterator scur = s.begin(), pcur = p.begin(), sstar = p.end(), pstar = p.end();
		while (*scur) {
			if (*scur == *pcur || *pcur == '?') {
				++scur;
				++pcur;
			}
			else if (*pcur == '*') {
				pstar = pcur++;
				sstar = scur;
			}
			else if (pstar != p.end()) {
				pcur = pstar + 1;
				scur = ++sstar;
			}
			else return false;
		}
		while (*pcur == '*') ++pcur;
		return !*pcur;
	}
};

