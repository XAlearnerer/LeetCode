#include<iostream>
#include<vector>

using namespace std;



//链接：https://www.nowcoder.com/questionTerminal/708f0442863a46279cce582c4f508658?questionTypes=000100&page=1&onlyReference=false
//来源：牛客网
//
//现有一个容量大小为V的背包和N件物品，每件物品有两个属性，体积和价值，请问这个背包最多能装价值为多少的物品？
//
//输入描述 :
//第一行两个整数V和n。
//接下来n行，每行两个整数体积和价值。1≤N≤1000, 1≤V≤20000。
//每件物品的体积和价值范围在[1, 500]。
//
//
//输出描述 :
//输出背包最多能装的物品价值。
//示例1
//输入
//6 3
//3 5
//2 4
//4 2
//输出
//9


#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


int main_01_package()
{
	int V, N;
	cin >> V >> N;
	vector<int> w(N);
	vector<int> v(N);

	vector<int> dp(V + 1, 0);

	for (int i = 0; i < N; ++i)
	{
		cin >> w[i] >> v[i];
	}

	for (int i = 0; i < N; ++i)
	{
		for (int j = V; j >= w[i]; --j)
		{
			dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
		}
	}

	cout << dp[V] << endl;

	return 0;
}



//dp[i][v] = max{ dp[i - 1][v] , dp[i - 1][v - c[i]] + w[i] }。
//好了，现在思考如何将数组压缩，对于这两种情况下dp[i][v]值的改变，
//要么是dp[i][v] = dp[i - 1][v], 要么是dp[i][v] = dp[i - 1][v - c[i]] + w[i]。
//假设下面是就是二维数组dp的一部分,
//
//a　　　　b　　　　dp[i - 1][v]　　　　d　　　　e
//
//f　　　　g　　　 　dp[i][v]  　　　　 h        k
//
//我们可以发现：如果dp[i][v] = dp[i - 1][v], 那么相当于直接复制dp[i][v]上面的元素dp[i - 1][v]值。
//而如果dp[i][v] = dp[i - 1][v - c[i]] + w[i]，注意到，v - c[i] <= v，
//所以，dp[i][v]的值是由上面红色的元素加上w[i]得到，也就是说，我们每次想要更新dp[i][v], 
//可能会用到的值只有上面红色的部分，所以，我们就能把二维数组压缩为一维数组，
//只需要每次从后往前更新dp[i][v]的值。这样就用dp[v]来表示容量为v的情况下，背包内物品的价值，
//状态转移方程也就成了：
//
//dp[v] = max{ dp[v] , dp[v - c[i]] + w[i] }



/////////////////////////////////////////////////////////////////////////////////////////////////////



//对于完全背包，一件物品可以取多次，我们仍然使用0 / 1背包的思想:
//这件物品，取还是不取。唯一的变化是，取了这件物品，还可以取。
//所以，如果取，仍然是i件物品的问题(dp[i][v - c[i]] + w[i]); 
//如果不取，dp[i][v]还是dp[i - 1][v]都一样(第一次不取，以后也不会取，相当于转化成i - 1件物品的问题，
//为了和取的情况保持一致，采用dp[i][v])。
//所以状态转移方程变为了dp[i][v] = max{ dp[i][v] , dp[i][v - c[i]] + w[i] }, 那么在数组里，
//
//a　　　　b　　　　m　　　　　　　　d　　　　e
//
//f　　　　g　　　 　dp[i][v]  　　　　 h          k
//
//同样注意到，v - c[i] <= v, 所以，每次更新dp[i][v], 可能用到的值是红色部分，所以也可以压缩为一维，
//这里要注意了，数组中的f、g，是i下的情况，并不是i - 1的情况，dp[i][v]的值取决取i下，而不是i - 1,
//所以此时应该从前往后更新dp的值，这样才能保证取第i件物品时，dp[i][v]是由dp[i][v - c[i]] + w[i]推得，
//所以尽管状态转移方程仍然为dp[v] = max{ dp[v] , dp[v - c[i]] + w[i] }，v的循环顺序却应该是从小到大。



/////////////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////////////










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





