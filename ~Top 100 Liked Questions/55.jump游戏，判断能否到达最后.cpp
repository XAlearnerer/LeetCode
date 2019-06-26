#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


class Solution {
public:
	bool canJump(vector<int>& nums) {
		int reach = 0;
		for (int i = 0; i < nums.size(); ++i)
		{
			if (reach >= nums.size() - 1 || reach < i) break;
			reach = max(reach, i + nums[i]);
		}

		return reach >= nums.size() - 1;
	}
};


