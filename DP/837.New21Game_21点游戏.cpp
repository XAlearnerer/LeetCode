#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
	double new21Game(int N, int K, int W) {
		if (K == 0 || N >= K + W) return 1.0;
		vector<double> dp (N + 1, 0);
		dp[0] = 1;
		double res = 0.0;
		double sum = 1.0;
		for (int i = 1; i <= N; ++i)
		{
			dp[i] = sum / W;
			if (i < K) sum += dp[i];
			else res += dp[i];
			if (i >= W) sum -= dp[i - W];
		}
		return res;
	}
};





// 这道题的条件概率和联合概率是相等的，
// 所以只要求出P(<= N && >= K)，即 dp[N] - dp[K - 1]，
// 而这题不是更新完整个dp数组后再求联合概率，
// 而是在更新的过程中就累加到了结果res
