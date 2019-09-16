#include<iostream>
#include<vector>
#include<algorithm>


using namespace std;


//组成三角形本质上只用一个条件就好：即最短的两条边相加之和大于最大的一条边。
//所以我们只用遍历最长的一条边，然后找出能够和其组成三角形的两条短边的个数就好了。

class Solution {
public:
	int triangleNumber(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		int count = 0;
		for (int i = 2; i < nums.size(); i++) {
			int l = 0, r = i - 1;
			while (l < r) 
			{
				if (nums[l] + nums[r] > nums[i]) {
					count += r - l;
					r--;
				}
				else
					l++;
			}
		}
		return count;
	}
};

