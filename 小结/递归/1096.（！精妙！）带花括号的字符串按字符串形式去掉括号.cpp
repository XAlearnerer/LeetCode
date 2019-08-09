//  
//
//  R("a") = { "a" }
//  R("w") = { "w" }
//  R("{a,b,c}") = { "a","b","c" }
//  R("{{a,b},{b,c}}") = { "a","b","c" } 
//  R("{a,b}{c,d}") = { "ac","ad","bc","bd" }
//  R("a{b,c}{d,e}f{g,h}") = { "abdfg", "abdfh", "abefg", "abefh", "acdfg", "acdfh",
//  "acefg", "acefh" }
//
//


#include<iostream>
#include<string>
#include<vector>
#include<set>

using namespace std;

class Solution {
public:
	vector<string> braceExpansionII(string expression) {
		set<string> res;
		int pos = 0;
		res = f2(expression, pos);
		return vector<string>(res.begin(), res.end());
	}

	//{a,b,c}
	set<string> f1(string& s, int& pos)
	{
		set<string> ans;
		++pos;
		ans = f2(s, pos);
		++pos;
		return ans;
	}

	//{a,b},{b,c}
	set<string> f2(string& s, int& pos)
	{
		set<string> ans;
		ans = f3(s, pos);
		while (pos < s.size())
		{
			if (s[pos] != ',') break;	//?  '}' break;
			++pos;
			set<string> cur = f3(s, pos);
			ans.insert(cur.begin(), cur.end());
		}
		return ans;
	}


	

	//a{b,c}{d,e}f{g,h}
	set<string> f3(string& s, int& pos)
	{
		set<string> ans;
		while (pos < s.size())
		{
			if (s[pos] == '}' || s[pos] == ',')
			{
				break;
			}
			if (s[pos] == '{')
			{
				set<string> cur = f1(s, pos);
				ans = merge(ans, cur);
			}
			else
			{
				string t;
				while (pos < s.size() && s[pos] <= 'z' && s[pos] >= 'a')
				{
					t += s[pos];
					++pos;
				}
				set<string> cur;
				cur.insert(t);
				ans = merge(ans, cur);
			}
		}

		return ans;
	}

	set<string> merge(set<string>& a, set<string>& b)
	{
		if (a.empty()) return b;
		if (b.empty()) return a;

		set<string> res;
		for (auto &i : a)
		{
			for (auto& j : b)
			{
				string t = i + j;
				res.insert(t);
			}
		}
		return res;
	}
};


//int main()
//{
//	string s = "a{b,c}q{d,e}";
//	Solution n;
//	for (auto i : n.braceExpansionII(s))
//		cout << i << " ";
//	cout << endl;
//	
//	return 0;
//}
//
//
//










