#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


//����f[i]��ʾ������[0, i]��Χ�ڲ���һ������nums[i]���ֵ����������˻���
//g[i]��ʾ������[0, i]��Χ�ڲ���һ������nums[i]���ֵ���С������˻���
//��ʼ��ʱf[0]��g[0]����ʼ��Ϊnums[0]�����඼��ʼ��Ϊ0��
//��ô������ĵڶ������ֿ�ʼ��������ô��ʱ�����ֵ����Сֵֻ��������������֮�������
//��f[i - 1] * nums[i]��g[i - 1] * nums[i]����nums[i]�����������������е����ֵ������f[i]��
//����Сֵ������g[i]��Ȼ����f[i]�����½��res���ɣ��������յĽ����һ�������nums[n - 1]������֣�
//����f[n - 1]��һ�������ս⣬���ϸ��µĽ��res���ǣ�


class Solution {
public:
	int maxProduct(vector<int>& nums) {
		if (nums.empty()) return 0;
		int n = nums.size();
		vector<int> f(n, 0);
		vector<int> g(n, 0);
		f[0] = g[0] = nums[0];
		int res = nums[0];
		for (int i = 1; i != nums.size(); ++i)
		{
			f[i] = max(f[i - 1] * nums[i], max(g[i - 1] * nums[i], nums[i]));
			g[i] = min(f[i - 1] * nums[i], min(g[i - 1] * nums[i], nums[i]));
			if (f[i] > res)
				res = f[i];
		}
		return res;
	}
};