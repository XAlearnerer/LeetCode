#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <bitset>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <string>
#include <set>
#include <map>

using namespace std;



class Solution1103 {
public:
	vector<int> distributeCandies(int candies, int num_people) {
		vector<int> res(num_people, 0);
		int pos = 1;
		while (candies > 0)
		{
			if (candies > pos)
			{
				res[(pos - 1) % num_people] += pos;
				candies -= pos;
			}
			else
			{
				res[(pos - 1) % num_people] += candies;
				break;
			}
			++pos;
		}
		return res;
	}
};


/////////////////////////////////////////////////////////////////////////////////////////


class Solution1104 {
public:
	vector<int> pathInZigZagTree(int label) {
		int level = log(label) / log(2);
		vector<int> res;
		while (label > 0)
		{
			res.push_back(label);
			label /= 2;
		}
		reverse(res.begin(), res.end());
		for (int i = 1; i < res.size() - 1; ++i)
		{
			if (level % 2 == 0)
			{
				if (i % 2 == 1)
				{
					res[i] = pow(2, i + 1) - 1 - (res[i] - pow(2, i));
				}
			}
			else
			{
				if (i % 2 == 0)
				{
					res[i] = pow(2, i + 1) - 1 - (res[i] - pow(2, i));
				}
			}
		}

		return res;
	}
};



/////////////////////////////////////////////////////////////////////////////////////////

//
//class Solution {
//public:
//	int minHeightShelves(vector<vector<int>>& books, int shelf_width) {
//		int len = books.size();
//		vector<vector<pair<int, int>>> dp(len, vector<pair<int, int>>(len, { INT_MAX,0 }));
//		for (int i = 0; i < len; ++i)
//		{
//			dp[i][i].first = books[i][1];  //height
//			dp[i][i].second = books[i][0];  //thickness 
//		}
//
//		for (int j = 1; j < len; ++j)
//		{
//			for (int i = j - 1; i >= 0; --i)
//			{
//				for (int k = i; k < j; ++k)
//				{
//					pair<int, int> m = { 0,0 };
//					if (dp[i][k].second + dp[k + 1][j].second > shelf_width)
//					{
//						m.first = dp[k + 1][j].first + dp[i][k].first;
//						m.second = dp[k + 1][j].second;
//					}
//					else
//					{
//						m.first = max(dp[k + 1][j].first, dp[i][k].first);
//						m.second = dp[k + 1][j].second + dp[i][k].second;
//					}
//
//					if (m.first < dp[i][j].first)
//						dp[i][j] = m;
//				}
//				
//			}
//		}
//
//		for (auto i : dp)
//		{
//			for (auto j : i)
//			{
//				if (j.first < 100)
//					cout << "(" << j.first << " , " << j.second << ")" << " ";
//				else
//					cout << "(0 , 0)" << " ";
//			}
//			cout << endl;
//		}
//
//		return dp[0][len - 1].first;
//
//	}
//};
//


//? 可惜了，没写出来

//思路：经典的动态规划题。
//定义dp[i]为前i本书能够到达的最小高度。
//则对于第i + 1本书，有若干选择。
//
//如自己单独一层，则状态转移为dp[i + 1] = dp[i] + h[i + 1]
//
//如果和前面的书放在一起，含义是前j本书组成若干层，第j + 1到第i + 1本书组成一层，
//则状态转移方程式dp[i + 1] = min(dp[j] + max[h[j + 1] ~h[i + 1])),
//其中需要满足sum(w[j + 1] ~w[i + 1]) <= shelf_width，。
//
//对于这些选择，取最小值。



class Solution {
public:
	int minHeightShelves(vector<vector<int>>& books, int shelf_width) {
		int len = books.size();
		vector<int> dp(len + 1, INT_MAX);
		dp[0] = 0;
		for (int i = 1; i <= len; ++i)
		{
			int h = books[i - 1][1];
			int w = books[i - 1][0];
			dp[i] = dp[i - 1] + h;
			for (int j = i - 1; j > 0; --j)
			{
				w += books[j - 1][0];
				h = max(h, books[j - 1][1]);
				if (w > shelf_width) break;
				dp[i] = min(dp[i], dp[j - 1] + h);
			}
		}

		return dp[len];
	}
};


//int main()
//{
//	Solution n;
//	vector<vector<int>> books = { { 1,1 },{ 2,3 },{ 2,3 },{ 1,1 },{ 1,1 },{ 1,1 },{ 1,2 } };
//	int shelf_width = 4;
//	cout << n.minHeightShelves(books, shelf_width);
//	cout << endl;
//
//	return 0;
//}


