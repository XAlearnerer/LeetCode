#include<iostream>
#include<string>
#include<stack>
#include<algorithm>

using namespace std;

class Solution {
public:
	string decodeAtIndex(string S, int K) {
		int pos = 0;
		string cur = "";
		string num = "";
		string res = "";
		while (pos < S.size())
		{
			while (pos < S.size() && !isdigit(S[pos]))
			{
				cur += S[pos];
				++pos;
			}

			while (pos < S.size() && isdigit(S[pos]))
			{
				num += S[pos];
				++pos;
			}

			int n = stoi(num);
			while (n--)
			{
				res += cur;
			}
			cur = res;
			num.clear();
			res.clear();
		}

		return cur.substr(K - 1, 1);
	}


	string decodeAtIndex2(string S, int K) {
		long N = 0, i;
		for (i = 0; N < K; ++i)
			N = isdigit(S[i]) ? N * (S[i] - '0') : N + 1;
		while (i--)
			if (isdigit(S[i]))
				N /= S[i] - '0', K %= N;
			else if (K % N-- == 0)
				return string(1, S[i]);
		return "lee215";
	}

};




