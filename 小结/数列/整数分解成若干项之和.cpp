
// https://pintia.cn/problem-sets/14/problems/2990



//7 - 1 整数分解为若干项之和（20 分）
//将一个正整数N分解成几个正整数相加，可以有多种分解方法，例如7 = 6 + 1，
//7 = 5 + 2，7 = 5 + 1 + 1，…。编程求出正整数N的所有整数分解式子。
//
//输入格式：
//每个输入包含一个测试用例，即正整数N(0<N≤30)。
//
//输出格式：
//按递增顺序输出N的所有整数分解式子。递增顺序是指：对于两个分解序列N​1​​ = { n​1​​,n​2​​,⋯ }
//和N​2​​ = { m​1​​,m​2​​,⋯ }，若存在i使得n​1​​ = m​1​​, ⋯, n​i​​ = m​i​​，但是n​i + 1​​<m​i + 1​​, 
//则N​1​​序列必定在N​2​​序列之前输出。每个式子由小到大相加，式子间用分号隔开，且每输出4个式子后换行。
//
//输入样例：
//7
//输出样例：
//7 = 1 + 1 + 1 + 1 + 1 + 1 + 1; 7 = 1 + 1 + 1 + 1 + 1 + 2; 7 = 1 + 1 + 1 + 1 + 3; 7 = 1 + 1 + 1 + 2 + 2
//7 = 1 + 1 + 1 + 4; 7 = 1 + 1 + 2 + 3; 7 = 1 + 1 + 5; 7 = 1 + 2 + 2 + 2
//7 = 1 + 2 + 4; 7 = 1 + 3 + 3; 7 = 1 + 6; 7 = 2 + 2 + 3
//7 = 2 + 5; 7 = 3 + 4; 7 = 7




#include <iostream>

using namespace std;

const int maxn = 1010;
int num[maxn];
int sum = 0, n, ipos = 0;
int num_col = 0;

void dfs(int x)
{
	if (sum > n)
		return;
	else if (sum == n)
	{
		num_col++;
	/*	printf("%d=%d", n, num[0]);
		for (int i = 1; i < ipos; i++)
			printf("+%d", num[i]);
		if (num_col % 4 == 0 || ipos == 1)
			printf("\n");
		else printf(";");*/
	}
	else if (sum < n)
	{
		for (int i = x; i <= n; i++)
		{
			sum += i;
			num[ipos++] = i;
			dfs(i);
			sum -= i;
			ipos--;
		}
	}
}
int main_Nfenjie()
{
	scanf("%d", &n);
	dfs(1);
	cout << num_col << endl;
	return 0;
}

