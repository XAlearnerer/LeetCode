//#include<iostream>
//#include<vector>
//#include<algorithm>
//
//using namespace std;
//
//int helper(vector<int> &v) {
//	int n = v.size();
//
//	int sum = 0;
//	for (auto i : v) sum += i;
//
//	bool flag = (sum & 1);
//	sum /= 2;
//	vector<int> dp(sum + 1, false);
//
//	dp[0] = true;
//	for (int i = 0; i < n; ++i)
//		for (int j = sum; j >= v[i]; --j)
//			dp[j] = dp[j] || dp[j - v[i]];
//
//	int result = 0;
//	for (int i = sum; i > 0; --i)
//	{
//		if (dp[i])
//		{
//			result = (sum - int(i)) << 1;
//			break;
//		}
//	}
//
//	if (flag) return result + 1;
//	else return result;
//}
//
//
//
//int main()
//{
//	int N;
//	cin >> N;
//	vector<int> v(N);
//	for (int i = 0; i < N; ++i)
//		cin >> v[i];
//	cout << helper(v);
//
//	return 0;
//}