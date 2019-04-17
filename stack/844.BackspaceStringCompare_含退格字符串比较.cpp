#include<iostream>
#include<string>
#include<stack>

using namespace std;

class Solution {
public:
	bool backspaceCompare(string S, string T) {
		stack<char> s,t;
		helper(s, S);
		helper(t, T);

		while (!s.empty() && !t.empty())
		{
			char c1 = s.top();
			s.pop();
			char c2 = t.top();
			t.pop();
			if (c1 != c2) return false;
		}

		if (!s.empty() || !t.empty()) return false;
		return true;

	}

	void helper(stack<char>& t,string s)
	{
		for (int i = 0; i != s.size(); ++i)
		{
			if (s[i] >= 'a' && s[i] <= 'z')
			{
				t.push(s[i]);
			}
			else
			{
				if (!t.empty())
					t.pop();
			}
		}
	}
};


//int main()
//{
//	string s = "bxj##tw";
//	string t = "bxj###tw";
//	Solution n;
//	cout << n.backspaceCompare(s, t) << endl;;
//	return 0;
//}