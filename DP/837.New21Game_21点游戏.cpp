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





// �������������ʺ����ϸ�������ȵģ�
// ����ֻҪ���P(<= N && >= K)���� dp[N] - dp[K - 1]��
// �����ⲻ�Ǹ���������dp������������ϸ��ʣ�
// �����ڸ��µĹ����о��ۼӵ��˽��res
