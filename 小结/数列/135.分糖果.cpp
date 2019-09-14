#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


// Each child must have at least one candy.
// Children with a higher rating get more candies than their neighbors.


// Input: [1, 0, 2]
// Output : 5
// Explanation : You can allocate to the first, second and third child with 2, 1, 2 candies respectively.


// Input : [1, 2, 2]
// Output : 4
// Explanation : You can allocate to the first, second and third child with 1, 2, 1 candies respectively.
// The third child gets 1 candy because it satisfies the above two conditions.



class Solution {
public:
	int candy(vector<int>& ratings) {
		if (ratings.empty()) return 0;
		int n = ratings.size();
		vector<int> nums(n, 1);
		for (int i = 0; i < n - 1; ++i)
		{
			if (ratings[i] < ratings[i + 1])
				nums[i + 1] = nums[i] + 1;
		}

		for (int i = n - 1; i > 0; --i)
		{
			if (ratings[i] < ratings[i - 1])
				nums[i - 1] = max(nums[i] + 1, nums[i - 1]);
		}

		int res = 0;
		for (auto i : nums)
			res += i;
		return res;		
	}
};



