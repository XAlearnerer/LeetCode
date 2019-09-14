#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


//链接：https://www.nowcoder.com/questionTerminal/a16b6679cc1841c3a20324279116d040
//来源：牛客网
//
//玥玥带乔乔一起逃亡，现在有许多的东西要放到乔乔的包里面，但是包的大小有限，
//所以我们只能够在里面放入非常重要的物品。现在给出该种物品的数量、体积、价值的数值，
//希望你能够算出怎样能使背包的价值最大的组合方式，并且输出这个数值，乔乔会非常感谢你。
//
//
//输入描述 :
//第1行有2个整数，物品种数n和背包装载体积v；
//
//第2行到i + 1行每行3个整数，为第i种物品的数量m、体积w、价值s。
//
//
//输出描述 :
//仅包含一个整数，即为能拿到的最大的物品价值总和。
//示例1
//输入
//2 10
//3 4 3
//2 2 5
//输出
//13
//说明
//选第一种一个，第二种两个，结果为3x1 + 5x2 = 13。

int main_duochong()
{
	int N, V;
	cin >> N >> V;
	vector<int> m(N);
	vector<int> w(N);
	vector<int> s(N);
	for (int i = 0; i < N; ++i)
		cin >> m[i] >> w[i] >> s[i];


	vector<int> dp(V + 1);


	for (int i = 0; i < N; ++i)
	{
		for (int j = V; j >= w[i]; --j)
		{
			for (int k = 0; k <= m[i]; ++k)
			{
				if (j >= k*w[i])
					dp[j] = max(dp[j], dp[j - k*w[i]] + k*s[i]);
			}
		}
	}

	cout << dp[V] << endl;

	return 0;
}
