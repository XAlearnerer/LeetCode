#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;


// ˼·���Ƚ���һ���յ� dp ���飬Ȼ��ʼ����ԭ���飬
// ����ÿһ�������������֣��ö��ֲ��ҷ��� dp �����ҵ�һ����С���������֣�
// ���������ֲ����ڣ���ôֱ���� dp ���������ϱ����������֣�
// ������ڣ���������ָ���Ϊ��ǰ�����������֣���󷵻� dp ����ĳ��ȼ��ɣ�
// ע����ǣ�������ķ���һ����
// �ر�ע����� dp �����ֵ���ܲ���һ����ʵ�� LIS��
// �μ��������£�


class Solution {
public:
	int lengthOfLIS(vector<int>& nums) {
		vector<int> dp;
		for (int i = 0; i < nums.size(); ++i) {
			int left = 0, right = dp.size();
			while (left < right) {
				int mid = left + (right - left) / 2;
				if (dp[mid] < nums[i]) left = mid + 1;
				else right = mid;
			}
			if (right >= dp.size()) dp.push_back(nums[i]);
			else dp[right] = nums[i];
		}


		for (auto i : dp)
			cout << i << " ";
		cout << endl;

		return dp.size();
	}
};


int main_LIS()
{
	vector<int> v = { 10,9,2,5,3,7,101,18 };
	Solution n;
	cout << n.lengthOfLIS(v) << endl;

	return 0;
}

