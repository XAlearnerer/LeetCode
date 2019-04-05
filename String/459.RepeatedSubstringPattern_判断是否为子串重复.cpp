//
// Created by zhao on 19-4-4.
//

#include <iostream>
#include<string>
using namespace std;


class Solution {
public:
    bool repeatedSubstringPattern(string s) {
		for (int i = 1; i <= s.length() / 2; ++i)
		{
			if (s.length() % i == 0)
			{
				int sublen = s.length() / i;
				string ts = "";
				for (int j = 0; j < sublen; ++j)
				{
					ts += s.substr(0, i);
				}
				if (s == ts) return true;
			}
		}
		return false;
    }
};




