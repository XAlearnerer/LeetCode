//
//#include<iostream>
//#include<vector>
//#include<algorithm>
//
//using namespace std;
//
//
////第一题是，01数组，将0调整成1，但是调整后1的两侧必须是0，返回可以调整多少个0到1。
//
//
//int main_01xulie01()
//{
//	int n;
//	cin >> n;
//	vector<int> nums(n);
//	for (int i = 0; i < n; ++i)
//		cin >> nums[i];
//	int dp0 = 0, dp1 = nums[0] == 0 ? 1 : 0;
//	int pre = nums[0];
//	for (int i = 1; i < nums.size(); ++i)
//	{
//		if (nums[i] == 0)
//		{
//			int old_dp0 = dp0;
//			dp0 = max(dp0, dp1);
//			if (pre == 0) dp1 = old_dp0 + 1;
//		}
//		else
//		{
//			dp1 = dp0;
//		}
//		pre = nums[i];
//	}
//	cout << max(dp1, dp0);
//	return 0;
//}
//
//
//
///////////////////////////////////////////////////////////////////////////////////////////
//
//
//
//#include<iostream>
//#include<vector>
//
//using namespace std;
//
//int main_01xulie02()
//{
//	int n = 0;
//	cin >> n;
//	vector<int> a(n + 2, 0);
//	for (int i = 1; i < n + 1; i++) cin >> a[i];
//	int res = 0;
//	for (int i = 1; i < n + 1; i++)
//	{
//		if (a[i] == 0 && a[i - 1] == 0 && a[i + 1] == 0)
//		{
//			res++;
//			a[i] = 1;
//		}
//	}
//	cout << res << endl;
//	return 0;
//}
//
//
//
