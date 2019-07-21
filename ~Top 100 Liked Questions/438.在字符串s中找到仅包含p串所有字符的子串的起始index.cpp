#include<iostream>
#include<vector>

using namespace std;


class Solution {
public:
	vector<int> findAnagrams(string s, string p) {
		if (s.empty()) return {};
		vector<int> v(26, 0);
		int plen = p.size();
		for (auto i : p) ++v[i - 'a'];
		int pos = 0;
		vector<int> res;
		while (pos < s.size())
		{
			vector<int> t = v;
			int tlen = plen;
			int tpos = pos;
			while (--t[s[tpos] - 'a'] >= 0)
			{
				--tlen;
				++tpos;
				if (tpos >= s.size()) break;
			}
			if (tlen == 0) res.push_back(pos);
			++pos;
		}

		return res;
	}

};

//
//int main()
//{
//	Solution n;
//	string s = "abab";
//	string p = "ab";
//	for (auto i : n.findAnagrams(s, p)) cout << i << " ";
//	cout << endl;
//
//	return 0;
//}
//
//
