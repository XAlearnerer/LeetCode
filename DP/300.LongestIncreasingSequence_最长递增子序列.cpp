#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


///////////// dp /////////////////

class Solution2 {
public:
	int lengthOfLIS(vector<int>& nums) {
		if (nums.empty()) return 0;
		int res = 0;
		vector<int> dp(nums.size(), 1);
		for (int i = 0; i != nums.size(); ++i)
		{
			for (int j = 0; j != i; ++j)
			{
				if (nums[i] > nums[j])
				{
					dp[i] = max(dp[i], dp[j] + 1);
				}
			}

			res = max(res, dp[i]);
		}

		//for (auto i : dp)
		//	cout << i << " ";
		//cout << endl;

		return res;
	}
};



/////////////// STL /////////////////////

//lower_bound���������е�һ����С��ָ��ֵ��Ԫ�أ���������㷨���ƣ�
//���ǻ���Ҫһ��һά����v��Ȼ����ڱ�������nums��ÿһ��Ԫ�أ�
//����lower_bound�����û��lower_bound��˵����Ԫ�ر�һά�����βԪ�ػ�Ҫ��
//ֱ����ӵ�����v�У����ⷨ����˼·��ͬ�ˡ������lower_bound��
//˵����Ԫ�ز������ģ�����lower_bound�滻Ϊ��Ԫ�أ�
//������̸��㷨���Ķ��ֲ��ҷ��Ĳ���ʵ����ͬ���ܣ�
//���Ҳ�Ƿ�������v�ĳ���


class Solution {
public:
	int lengthOfLIS(vector<int>& nums) {
		if (nums.empty()) return 0;
		vector<int> res;
		for (int i = 0; i != nums.size(); ++i)
		{
			auto it = lower_bound(res.begin(), res.end(), nums[i]);
			if (it == res.end()) res.push_back(nums[i]);
			else *it = nums[i];
		}

		return res.size();
	}
};


