#include<iostream>
#include<string>

using namespace std;


   
// Loop char c in the string S :
// if (c == '('), we increment right,
// if (c == ')'), we decrement right.
// When right is already 0, we increment left
// Return left + right in the end
   


class Solution {
public:
	int minAddToMakeValid(string s) {
		if (s.empty()) return 0;
		int l = 0, r = 0;
		for (auto i : s)
		{
			if (i == '(') ++r;
			else if (r > 0) --r;
			else ++l;
		}
		return l + r;
	}
};




