#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <bitset>
#include <unordered_set>
#include <queue>
#include <string>
#include <set>

using namespace std;

class Solution1046 {
public:
	int lastStoneWeight(vector<int>& stones) {
		if (stones.empty()) return 0;
		priority_queue<int> q(stones.begin(), stones.end());
		int t = 0; bool flag = false;
		while (!q.empty())
		{
			flag = false;
			t = q.top();
			q.pop();
			if (q.empty()) break;
			int t2 = q.top();
			q.pop();
			if (t - t2 > 0) q.push(t - t2);
			flag = true;
		}
		if (flag) return 0;
		return t;
	}
};

///////////////////////////////////////////////////////////////////

class Solution1047 {
public:
	string removeDuplicates(string S) {
		if (S.empty()) return "";
		if (S.length() == 1) return S;
		if (S.length() == 2)
		{
			if (S[0] == S[1]) return "";
			else return S;
		}
//? û�ҵ���������
		int l = 0, r = 1;
		while (r < S.size())
		{
			if (S[l] == S[r]) { S.erase(l, 2); continue;  }
			if (r < S.size() && S[r] == S[r + 1]) S.erase(r, 2);
			else { ++l, ++r; }
		}
		l = 0, r = 1;
		while (r < S.size())
		{
			if (S[l] == S[r]) { S.erase(l, 2); continue; }
			if (r < S.size() && S[r] == S[r + 1]) S.erase(r, 2);
			else { ++l, ++r; }
		}
		l = 0, r = 1;
		while (r < S.size())
		{
			if (S[l] == S[r]) { S.erase(l, 2); continue; }
			if (r < S.size() && S[r] == S[r + 1]) S.erase(r, 2);
			else { ++l, ++r; }
		}

		return S;
	}
};


class Solution1047_2 {
public:
	string removeDuplicates(string S) {
		if (S.empty()) return "";
		if (S.length() == 1) return S;
		if (S.length() == 2)
		{
			if (S[0] == S[1]) return "";
			else return S;
		}
		stack<char> sta;
		sta.push(S[0]);
		int pos = 1;
		while (pos < S.length())
		{
			if (sta.empty())
			{
				sta.push(S[pos]);
				++pos;
				continue;
			}
			if (sta.top() == S[pos])
			{
				sta.pop();
			}
			else
				sta.push(S[pos]);
			++pos;
		}
		string res;
		while (!sta.empty())
		{
			int t = sta.top();
			res += t;
			sta.pop();
		}
		reverse(res.begin(), res.end());
		return res;
	}
};



///////////////////////////////////////////////////////////////////


class Solution1048 {
public:
	int longestStrChain(vector<string>& words) {
		if (words.empty()) return 0;
		sort(words.begin(), words.end(), [](string s1, string s2) {return s1.length() < s2.length(); });

		vector<int> dp(words.size(), 1);
		int res = 0;
		for (int i = 1; i < words.size(); ++i)
		{
			for (int j = i - 1; j >= 0; --j)
			{
				if (check(words[j], words[i]))
				//if(isProd(words[j], words[i]))
				{
					dp[i] = max(dp[i], dp[j] + 1);
				}
			}
			res = max(dp[i], res);
		}
		return res;
	}

	//word1 is a predecessor of word2 if and only if we can add exactly 
	//! /// one letter　　只有一个字符
	//anywhere in word1 to make it equal to word2
	
	bool check(string s1, string s2)
	{
		//if (s1 == s2) return false;
		if (s2.length() != s1.length() + 1) return false;
		int len1 = s1.length(), len2 = s2.length();
		int i = 0, j = 0;
		int dif = 0;
		while (j < len2 && i < len1)
		{
			if (s1[i] == s2[j]) { ++i, ++j; }
			//else ++j;
			//if (i >= len1) return true;
			else
			{
				++j;
				++dif;
				if (dif > 1) return false;
			}
		}
		return true;
	}
};


///////////////////////////////////////////////////////////////////





