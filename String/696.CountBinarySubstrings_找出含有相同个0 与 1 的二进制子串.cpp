#include<iostream>
#include<stack>

using namespace std;


// all the 0's and all the 1's in these substrings are grouped consecutively
// 且0和1各自都群组在一起 (即0和1不能交替出现)



class Solution {
public:
	//int countBinarySubstrings(string s) {
	//	deque<int> de;
	//	int res = 0;
	//	int pos = 1;
	//	de.push_back(s[0]);
	//	int pren = 1, postn = 0, ca = 1;
	//	while (pos < s.length())
	//	{
	//		if (s[pos] == de.back()) ++pren;


	//	}
	//}

	int countBinarySubstrings(string s) {
		int ones = 0, zeros = 0, res = 0;
		if (s[0] == '0') ++zeros;
		else ++ones;
		for (int i = 1; i != s.length(); ++i)
		{
			if (s[i] == '0')
			{
				if (s[i - 1] == '0') ++zeros;
				else zeros = 1;
				if (ones >= zeros) ++res;
				
			}
			else
			{
				if (s[i - 1] == '1') ++ones;
				else ones = 1;
				if (zeros >= ones) ++res;
			}
		}


		return res;
	}
};







