#include<iostream>
#include<string>
#include<algorithm>
#include<unordered_map>

using namespace std;


class Solution {
public:
	int characterReplacement(string s, int k) {
		unordered_map<char, int> m;
		int left = 0, right = 0;
		int cur = 0, res = 0;
		for (; right < s.size(); ++right)
		{
			cur = max(cur, ++m[s[right]]);

			//for (auto i : m)
			//	cout << i.first << " -- " << i.second << endl;
			//cout << endl;

			while (right - left + 1 - cur > k)
			{
				--m[s[left]];
				++left;
			}
			res = max(res, right - left + 1);
		}

		return res;
	}
};










//我们首先来想，如果没有k的限制，
//让我们求把字符串变成只有一个字符重复的字符串需要的最小置换次数，
//那么就是字符串的总长度减去出现次数最多的字符的个数。
//
//如果加上k的限制，我们其实就是求满足
//(子字符串的长度减去出现次数最多的字符个数) <= k 的最大子字符串长度即可，
//搞清了这一点，我们也就应该知道怎么用滑动窗口来解了吧
//我们用一个变量start记录滑动窗口左边界，初始化为0，然后我们遍历字符串，
//每次累加出现字符的个数，然后更新出现最多字符的个数，
//然后我们判断当前滑动窗口是否满足之前说的那个条件，
//如果不满足，我们就把滑动窗口左边界向右移动一个，并注意去掉的字符要在counts里减一，
//直到满足条件，我们更新结果res即可