
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<int> nums(n);
	for (int i = 0; i < n; ++i)
		cin >> nums[i];

	int dp0 = 0, dp1 = nums[0] == 0 ? 1 : 0;
	int pre = nums[0];

	for (int i = 1; i < nums.size(); ++i)
	{
		if (nums[i] == 0)
		{
			int old_dp0 = dp0;
			dp0 = max(dp0, dp1);
			if (pre == 0) dp1 = old_dp0 + 1;
		}
		else
		{
			dp1 = dp0;
		}
		pre = nums[i];
	}

	cout << max(dp1, dp0);

	return 0;
}

