#include<iostream>
#include<string>
#include<stack>
#include<vector>

using namespace std;

class Solution {
public:
	/*bool find132pattern(vector<int>& nums) {
		if (nums.size() < 3) return false;
		stack<int> s;
		s.push(nums[0]);
		bool up = false;
		bool down = false;
		
		for (int i = 1; i != nums.size(); ++i)
		{
			if (s.top() < nums[i])
			{
				s.push(nums[i]);
				up = true;
			}
			else if (s.top() > nums[i])
			{
				if (up == true) return true;
				s.pop();
				s.push(nums[i]);
			}
			else
				continue;
		}
		return false;
	}*/

	bool find132pattern(vector<int>& nums) {
		stack<int> s;
		int cur = INT_MIN;
		for (int i = nums.size() - 1; i >= 0; --i)
		{
			if (nums[i] < cur) return true;
			else
			{
				while (!s.empty() && nums[i] > s.top())
				{
					cur = s.top();
					s.pop();
				}
			}
			s.push(nums[i]);
		}
		return false;
	}


};












