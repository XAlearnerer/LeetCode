#include<iostream>
#include<vector>


using namespace std;



class Solution {
public:
	bool canPartition(vector<int>& nums) {
		int sum = 0;
		for (auto i : nums)
			sum += i;
		if (sum % 2 != 0) return false;
		int target = sum / 2;
		vector<bool> dp(target + 1, false);
		dp[0] = true;
		for (auto i : nums)
		{
			for (int j = target; j >= i; --j)
			{
				dp[j] = dp[j] || dp[j - i];
			}
		}
		return dp[target];
	}
};







//  ��̬�滮 Dynamic Programming �������ǵĲ���֮ѡ��
//  ���Ƕ���һ��һά��dp���飬����dp[i]��ʾԭ�����Ƿ����ȡ�����ɸ����֣����Ϊi��

//  ��ô�������ֻ��Ҫ����dp[target]�����ˡ���ʼ��dp[0]Ϊtrue��
//  ������Ŀ����������������Ϊ��������ô�Ͳ��õ��Ļ���ֺ�Ϊ0���߸����������
//  �ؼ��������Ҫ�ҳ�״̬ת�Ʒ����ˣ�������Ҫ����ԭ�����е����֣�
//  ���ڱ�������ÿ������nums[i]����Ҫ����dp���飬���ǵ�����Ŀ������֪��dp[target]��booleanֵ��
//  ��Ҫ��취�������е�����ȥ�ճ�target����Ϊ��������������ֻ��Խ��Խ��
//  ��ô����nums[i]���п��ܻ��������[nums[i], target] �е�ĳ��ֵ��
//  ��ô������������е�����һ������j����� dp[j - nums[i]] Ϊtrue�Ļ���
//  ˵�������Ѿ�������� j - nums[i] ��������ˣ��ټ���nums[i]���Ϳ����������j�ˣ�
//  ��ôdp[j]��һ��Ϊtrue�����֮ǰdp[j]�Ѿ�Ϊtrue�ˣ���Ȼ��Ҫ����true�����Ի�Ҫ����������
//  ����״̬ת�Ʒ������£�
//  
//  dp[j] = dp[j] || dp[j - nums[i]](nums[i] <= j <= target)
//  
//  ����״̬ת�Ʒ��̣���ô���ǾͿ���д�������ˣ�������Ҫ�ر�ע����ǣ�
//  �ڶ���forѭ��һ��Ҫ��target������nums[i]�������ܷ�����������Ϊʲô�أ�
//  ��Ϊ������Ǵ�nums[i]������target�Ļ�������nums[i] = 1�Ļ���
//  ��ô[1, target]�����е�dpֵ����true����Ϊdp[0]��true��dp[1]�����dp[0]��Ϊtrue��
//  dp[2]�����dp[1]��Ϊtrue���������ƣ���ȫʹ���ǵ�dp����ʧЧ�ˣ��μ��������£�
