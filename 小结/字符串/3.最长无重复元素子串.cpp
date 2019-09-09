#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

//Input: "pwwkew"
//Output : 3
//Explanation : The answer is "wke", with the length of 3.
//Note that the answer must be a substring,
//"pwke" is a subsequence and not a substring.


class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		vector<int> v(128, -1);
		int left = -1, res = 0;
		for (int i = 0; i < s.size(); ++i)
		{
			left = max(left, v[s[i]]);
			v[s[i]] = i;
			res = max(res, i - left);

		}
		return res;
	}
};


// 我们可以建立一个 256 位大小的整型数组来代替 HashMap，
// 这样做的原因是 ASCII 表共能表示 256 个字符，
// 但是由于键盘只能表示 128 个字符，所以用 128 也行
