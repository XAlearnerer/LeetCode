//#include<iostream>
//#include<vector>
//#include<algorithm>
//
//using namespace std;

//int FindEndtime(int n, vector<int> time, vector<int> files, int& largestfile)
//{
//	int curfile = files[0];
//	for (int i = 1; i < n; ++i)
//	{
//		int timegap = time[i] - time[i - 1];
//		curfile = files[i] + (curfile - timegap);
//		largestfile = max(largestfile, curfile);
//	}
//	return time[n - 1] + curfile;
//}
//
//int main()
//{
//	vector<int> time = { 1,2,3 };
//	vector<int> files = { 3,3,3 };
//	int n = 3;
//	int lar = 0;
//	cout << FindEndtime(n, time, files, lar) << " ";
//	cout << lar << endl;
//
//	return 0;
//}
//


//
//
//int helper(vector<int>& nums) {
//	if (nums.size() == 1) return true;
//	int n = nums.size();
//	vector<vector<int>> f(n, vector<int>(n, 0));
//	vector<vector<int>> g(n, vector<int>(n, 0));
//	for (int i = 0; i < n; ++i)
//	{
//		f[i][i] = nums[i];
//		for (int j = i - 1; j >= 0; --j)
//		{
//			f[j][i] = max(nums[i] + g[j][i - 1], nums[j] + g[j + 1][i]);
//			g[j][i] = min(f[j + 1][i], f[j][i - 1]);
//		}
//	}
//
//
//	for (auto i : f)
//	{
//		for (auto j : i)
//			cout << j << " ";
//		cout << endl;
//	}
//
//	return f[0][n - 1];
//}
//
//int p1(vector<int>& nums, int i, int j);
//int p2(vector<int>& nums, int i, int j);
//int PredictTheWinner(vector<int>& nums) {
//	if (nums.size() == 1) return true;
//	return p1(nums, 0, nums.size() - 1);
//}
//
//int p1(vector<int>& nums, int i, int j)
//{
//	if (i == j) return nums[i];
//	return max(nums[i] + p2(nums, i + 1, j), nums[j] + p2(nums, i, j - 1));
//}
//
//int p2(vector<int>& nums, int i, int j)
//{
//	if (i == j) return 0;
//	return min(p1(nums, i + 1, j), p1(nums, i, j - 1));
//}
//
//
//
//int main()
//{
//	vector<int> v = { 1,1,1 };
//	cout << helper(v) << endl;
//	cout << PredictTheWinner(v) << endl;
//	return 0;
//}
//
//
//

