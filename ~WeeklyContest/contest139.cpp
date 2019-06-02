#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <bitset>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <string>
#include <set>
#include <map>

using namespace std;

class Solution {
public:
	string gcdOfStrings(string str1, string str2) {
		if (str1.empty() || str2.empty()) return "";

		string s, l;
		if (str1.size() < str2.size()) { s = str1; l = str2; }
		else { s = str2; l = str1; }

		if (search(l.begin(), l.end(), s.begin(), s.end()) == l.end()) return "";
		else
		{

		}

	//	vector<int> v(26, 0);
	//	for (auto i : s) ++v[i - 'A'];
	//	sort(v.begin(), v.end());
	//	if (v[0] == 1) return s;
	//	else
	//	{
	//		int times = v[0];
	//		if (s.size() % v[0] != 0) return s;
	//		else
	//		{
	//			int pos = 0;
	//			while (s.size() / v[0] + pos < s.size())
	//			{
	//				if (s[pos] == s[s.size() / v[0] + pos])
	//					++pos;
	//				else return s;
	//			}
	//			return s.substr
	//		}
	//	}


	}
};

int main()
{
	string s1 = "ABCABC";
	string s2 = "ABCABCABC";
	Solution n;
	cout << n.gcdOfStrings(s1, s2) << endl;
	return 0;
}
















