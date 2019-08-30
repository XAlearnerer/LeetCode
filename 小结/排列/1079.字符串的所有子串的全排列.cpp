#include<iostream>
#include<string>
#include<set>
#include<vector>


using namespace std;

class Solution {
public:
	int numTilePossibilities(string tiles) {
		int res = 0;
		set<string> t;
		vector<int> v(tiles.size(), 0);
		helper(t, tiles, res, "", v);


		for (auto i : t)
			cout << i << " ";
		cout << endl;


		return res;
	}

	void helper(set<string>& t, string s, int& res, string cur, vector<int> v)
	{
		if (!cur.empty() && t.count(cur) == 0)
		{
			++res;
			t.insert(cur);
		}

		for (int i = 0; i < s.size(); ++i)
		{
			if (v[i] == 1) continue;
			v[i] = 1;
			helper(t, s, res, cur + string(1, s[i]), v);
			v[i] = 0;
		}
	}

};


//int main()
//{
//	string s = "ABC";
//	Solution n;
//	cout << n.numTilePossibilities(s) << endl;
//
//	return 0;
//}