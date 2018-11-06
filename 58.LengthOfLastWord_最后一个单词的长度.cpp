#include<iostream>
using namespace std;


class Solution2 {
public:
	int lengthOfLastWord(string s) {
		auto j = s.find_last_not_of(' ');
		int i = j;
		for(; i >= 0; --i)
		{
			if (s[i] == ' ') break;
		}
		return j - i;
	}
};

class Solution {
public:
	int lengthOfLastWord(string s) {
		if (s.length() == 0) {
			return 0;
		}
		int flag = 0;
		int output = 0;
		for (int i = s.length() - 1; i >= 0; --i) {
			if (s[i] == ' ') {
				if (flag == 0) {
					continue;
				}
				else {
					break;
				}
			}
			output++;
			flag = 1;
		}
		return output;
	}
};
int main1105()
{
	string s = "a";
	Solution n;
	cout << n.lengthOfLastWord(s) << endl;

	Solution n2;
	cout << n2.lengthOfLastWord(s) << endl;
	return 0;
}