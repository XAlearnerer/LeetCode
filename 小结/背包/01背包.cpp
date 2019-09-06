#include<iostream>
#include<vector>

using namespace std;




void FindMax()//��̬�滮
{
	int number;  //��Ʒ����
	int capacity; // ��������

	vector<vector<int>> A;  //dp
	vector<int> w;  // ����
	vector<int> v;  // ��ֵ

	int i, j;
	//���
	for (i = 1; i <= number; i++)
	{
		for (j = 1; j <= capacity; j++)
		{
			if (j < w[i])//��װ���� 
				A[i][j] = A[i - 1][j];
			else//��װ
			{
				if (A[i - 1][j] > A[i - 1][j - w[i]] + v[i])//��װ��ֵ��
					A[i][j] = A[i - 1][j];
				else//ǰi-1����Ʒ�����Ž����i����Ʒ�ļ�ֵ֮�͸���
					A[i][j] = A[i - 1][j - w[i]] + v[i];
			}
		}
	}
}


void FindMaxBetter()//�Ż��ռ��Ķ�̬�滮
{

	int number;  //��Ʒ����
	int capacity; // ��������

	vector<int> B;
	vector<int> w;
	vector<int> v;

	int i, j;
	for (i = 1; i <= number; i++)
	{
		for (j = capacity; j >= 0; j--)
		{
			if (B[j] <= B[j - w[i]] + v[i] && j - w[i] >= 0)//��ά��һά
			{
				B[j] = B[j - w[i]] + v[i];
			}
		}
	}

}



//01��������
//����Ϊ10�ı�������5����Ʒ��ÿ����Ʒֻ��һ����
//�������ֱ�Ϊ5��4��3��2��1�����ֵ�ֱ�Ϊ1��2��3��4��5��
//����㷨��ʵ�ֱ�������Ʒ��ֵ���
//�������£����14��

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

	cout << "�ܵļ�ֵΪ: " << dp[10] << endl;
	return 0;
}
