#include<iostream>
#include<string>
#include<stack>
#include<algorithm>

using namespace std;

class Solution2 {
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

			int n = stoi(num);    //? Worng  S = "a2345678999999999999999", K = 1 
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


	string decodeAtIndex3(string &S, int K, long long len = 0) {
		for (auto i = 0; i < S.size(); ++i) {
			if (isalpha(S[i])) {
				if (++len == K) return string(1, S[i]);
			}
			else {
				if (len * (S[i] - '0') >= K) return decodeAtIndex3(S, K % len == 0 ? len : K % len);
				len *= S[i] - '0';
			}
		}
	}

	string decodeAtIndex4(string S, int K)
	{
		long len = 0, i;

		for (i = 0; len < K; i++) {
			if (S[i] >= 'a' && S[i] <= 'z') len++;
			else len *= (S[i] - '0');
		}

		do {
			i--;
			if (S[i] >= '0' && S[i] <= '9') {
				len /= (S[i] - '0');
				K %= len;
			}
			else {
				if (!(K%len)) return string(1, S[i]);
				len--;
			}
		} while (i);
	}


};




class Solution {
public:
	string decodeAtIndex(string S, int K) {

	}
};