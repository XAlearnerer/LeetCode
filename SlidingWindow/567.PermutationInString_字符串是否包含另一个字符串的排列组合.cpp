#include<iostream>
#include<string>
#include<algorithm>
#include<vector>

using namespace std;

class Solution_worng { //? Time Limit Exceeded
public:
	bool checkInclusion(string s1, string s2) {
		sort(s1.begin(), s1.end());
		for (int i = 0, j = i + s1.size() - 1; j < s2.size(); ++i, ++j)
		{
			string cur = s2.substr(i, s1.size());
			sort(cur.begin(), cur.end());
			if (s1 == cur) return true;
		}
		return false;
	}
};

////////// SlidingWindow //////////////

class Solution {
public:
	bool checkInclusion(string s1, string s2) {
		int left = 0, right = 0, cnt = s1.size();
		vector<int> hash(26, 0);
		for (auto i : s1) ++hash[i - 'a'];
		for (int right = 0; right < s2.size(); ++right) 
		{
			if (hash[s2[right] - 'a'] > 0)
			{
				--cnt;
			}
			--hash[s2[right] - 'a'];

			while (cnt == 0)
			{
				if (right - left + 1 == s1.size()) return true;
				if (++hash[s2[left] - 'a'] > 0)
				{
					++cnt;
				}
				left++;
			}

		}
		return false;
	}
};






