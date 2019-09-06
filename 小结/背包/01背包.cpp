#include<iostream>
#include<vector>

using namespace std;




void FindMax()//动态规划
{
	int number;  //物品数量
	int capacity; // 背包容量

	vector<vector<int>> A;  //dp
	vector<int> w;  // 重量
	vector<int> v;  // 价值

	int i, j;
	//填表
	for (i = 1; i <= number; i++)
	{
		for (j = 1; j <= capacity; j++)
		{
			if (j < w[i])//包装不进 
				A[i][j] = A[i - 1][j];
			else//能装
			{
				if (A[i - 1][j] > A[i - 1][j - w[i]] + v[i])//不装价值大
					A[i][j] = A[i - 1][j];
				else//前i-1个物品的最优解与第i个物品的价值之和更大
					A[i][j] = A[i - 1][j - w[i]] + v[i];
			}
		}
	}
}


void FindMaxBetter()//优化空间后的动态规划
{

	int number;  //物品数量
	int capacity; // 背包容量

	vector<int> B;
	vector<int> w;
	vector<int> v;

	int i, j;
	for (i = 1; i <= number; i++)
	{
		for (j = capacity; j >= 0; j--)
		{
			if (B[j] <= B[j - w[i]] + v[i] && j - w[i] >= 0)//二维变一维
			{
				B[j] = B[j - w[i]] + v[i];
			}
		}
	}

}



//01背包问题
//容量为10的背包，有5种物品，每种物品只有一个，
//其重量分别为5，4，3，2，1，其价值分别为1，2，3，4，5。
//设计算法，实现背包内物品价值最大。
//代码如下（输出14）

#include <iostream>
#include<algorithm>

using namespace std;

int main_01()
{
	int total_weight = 10;
	int w[6] = { 0,5,4,3,2,1 };
	int v[6] = { 0,1,2,3,4,5 };
	int dp[11] = { 0 };

	for (int i = 1; i <= 5; i++)
		for (int j = 10; j >= w[i]; j--)
			dp[j] = max(dp[j], dp[j - w[i]] + v[i]);

	cout << "总的价值为: " << dp[10] << endl;
	return 0;
}
