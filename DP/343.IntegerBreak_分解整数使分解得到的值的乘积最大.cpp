#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

//class Solution {
//public:
//	int integerBreak(int n) {
//		vector<int> dp(n + 1, 0);
//		dp[2] = 1;
//		for (int i = 3; i <= n; ++i)
//		{
//			
//		}
//	}
//};


class Solution {
public:
	int integerBreak(int n) {
		if (n == 2 || n == 3) return n - 1;
		int res = 1;
		while (n > 4) {
			res *= 3;
			n -= 3;
		}
		return res * n;
	}
};


class Solution2 {
public:
	int integerBreak(int n) {
		vector<int> dp{ 0, 0, 1, 2, 4, 6, 9 };
		for (int i = 7; i <= n; ++i) {
			dp.push_back(3 * dp[i - 3]);
		}
		return dp[n];
	}
};


//��������1��ʼ������1���ܲ�ֳ�����������֮�ͣ����Բ��ܵ������
//��ô2ֻ�ܲ��1 + 1�����Գ˻�ҲΪ1��
//����3���Բ�ֳ�2 + 1��1 + 1 + 1����Ȼ��һ�ֲ�ַ����˻���Ϊ2��
//����4���2 + 2���˻����Ϊ4��
//����5���3 + 2���˻����Ϊ6��
//����6���3 + 3���˻����Ϊ9��
//����7��Ϊ3 + 4���˻����Ϊ12��
//����8��Ϊ3 + 3 + 2���˻����Ϊ18��
//����9��Ϊ3 + 3 + 3���˻����Ϊ27��
//����10��Ϊ3 + 3 + 4���˻����Ϊ36��

