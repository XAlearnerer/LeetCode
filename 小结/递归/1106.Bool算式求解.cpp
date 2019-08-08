#include<iostream>
#include<string>
#include<algorithm>

using namespace std;


class Solution {
public:
	bool parseBoolExpr(string expression) {
		int pos = 0;
		return helper(expression, pos);
	}

	bool helper(string& s, int& pos)
	{
		if (s[pos] == 't')
		{
			++pos;
			return true;
		}
		else if (s[pos] == 'f')
		{
			++pos;
			return false;
		}
		else if (s[pos] == '&') return fuand(s, pos);
		else if (s[pos] == '|') return fuor(s, pos);
		else return funot(s, pos);

	}

	bool fuand(string& s, int& pos)
	{
		pos += 2;
		bool t = true;
		t &= helper(s, pos);
		while (s[pos] != ')')
		{
			++pos;
			t &= helper(s, pos);
		}
		++pos;
		return t;
	}

	bool fuor (string& s, int &pos)
	{
		pos += 2;
		bool t = false;
		t |= helper(s, pos);
		while (s[pos] != ')')
		{
			++pos;
			t |= helper(s, pos);
		}
		++pos;
		return t;
	}

	bool funot(string& s, int& pos)
	{
		pos += 2;
		bool t = helper(s, pos);
		++pos;
		return !t;
	}


};


