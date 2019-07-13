#include<iostream>
#include<vector>

using namespace std;

   
// 我们也就只能考虑用二分搜索法了，我们在区间[1, n] 中搜索，
// 首先求出中点 mid，然后遍历整个数组，统计所有小于等于 mid 的数的个数，
// 如果个数小于等于 mid，则说明重复值在[mid + 1, n] 之间，
// 反之，重复值应在[1, mid - 1] 之间，然后依次类推，
// 直到搜索完成，此时的 low 就是我们要求的重复值
   


class Solution {
public:
	int findDuplicate(vector<int>& nums) {


	}
};

