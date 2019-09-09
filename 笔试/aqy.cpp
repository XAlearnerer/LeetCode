////#include<iostream>
////#include<vector>
////
////using namespace std;
////
////
////
////void helper(vector<int>& nums, vector<vector<int>>& res, int t)
////{
////	if (t >= nums.size()) res.push_back(nums);
////	else
////	{
////		for (int i = t; i < nums.size(); ++i)
////		{
////			swap(nums[i], nums[t]);
////			helper(nums, res, t + 1);
////			swap(nums[i], nums[t]);
////		}
////	}
////}
////bool check(vector<int>& v, vector<int> t)
////{
////	for (int i = 0; i < t.size() - 1; ++i)
////	{
////		if (v[i] == 1)
////		{
////			if (t[i] < t[i + 1]) return false;
////		}
////		else if (t[i] > t[i + 1]) return false;
////	}
////	return true;
////}
////
////
////int main()
////{
////	int n;
////	cin >> n;
////	vector<int> v;
////	for (int i = 0; i < n - 1; ++i)
////	{
////		int t;
////		cin >> t;
////		v.push_back(t);
////	}
////
////	vector<vector<int>> res;
////	vector<int> nums;
////	for (int i = 1; i <= n; ++i)
////		nums.push_back(i);
////
////	helper(nums, res, 0);
////
////
////	int count = 0;
////	for (auto i : res)
////	{
////		if (check(v, i)) ++count;
////	}
////
////	cout << count << endl;
////
////	return 0;
////}
////
////
////
//
//#include<iostream>
//#include<vector>
//
//using namespace std;
//
//void helper(vector<int> v) {
//	int n = v.size(), mod = (int)1e9 + 7;
//	vector<vector<int>> dp = vector<vector<int>>(n + 1, vector<int>(n + 1, 0));
//	for (int j = 0; j <= n; j++) dp[0][j] = 1;
//	for (int i = 0; i < n; i++)
//		if (v[i] == 0)
//			for (int j = 0, cur = 0; j < n - i; j++)
//				dp[i + 1][j] = cur = (cur + dp[i][j]) % mod;
//		else
//			for (int j = n - i - 1, cur = 0; j >= 0; j--)
//				dp[i + 1][j] = cur = (cur + dp[i][j + 1]) % mod;
//	cout << dp[n][0];
//}
//
//int main() {
//	int n;
//	cin >> n;
//	vector<int> v;
//	for (int i = 0; i < n - 1; ++i)
//	{
//		int t;
//		cin >> t;
//		v.push_back(t);
//	}
//	helper(v);
//
//	return 0;
//}
//
//
