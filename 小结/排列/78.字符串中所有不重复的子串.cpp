#include<iostream>
#include<string>
#include<vector>
#include<set>

using namespace std;
   
   
// Input: nums = [1, 2, 3]
// Output :
// [
// 	 [3],
// 	 [1],
// 	 [2],
// 	 [1, 2, 3],
// 	 [1, 3],
// 	 [2, 3],
// 	 [1, 2],
// 	 []
// ]
   
class Solution {
public:
	vector<vector<int>> subsets(vector<int>& nums) {
		//set<vector<int>> s;
		vector<vector<int>> res;
		vector<int> n;
		helper(res, nums, n, 0);
		//vector<vector<int>> res(s.begin(),s.end());
		return res;
	}

	//void helper(set<vector<int>>& res, vector<int>& nums, vector<int>& cur, int pos)
	void helper(vector<vector<int>>& res, vector<int>& nums, vector<int>& cur, int pos)
	{
		//res.insert(cur);
		res.push_back(cur);
		for (int i = pos; i < nums.size(); ++i)
		{
			cur.push_back(nums[i]);


		/////////////////////////////////////
			helper(res, nums, cur, i + 1);
		/////////////////////////////////////


			cur.pop_back();
		}
	}

};
