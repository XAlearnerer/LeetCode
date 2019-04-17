#include<iostream>
#include<string>
#include<stack>
#include<vector>
#include<algorithm>

using namespace std;

class Solution2 {
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



class Solution3 {
public:
	bool find132pattern(vector<int>& nums) {
		int i = INT_MAX;
		for (int j = 0; j != nums.size(); ++j)
		{
			i = min(i, nums[j]);
			if (i == nums[j]) continue;
			for (int k = nums.size() - 1; k > j; --k)
			{
				if (nums[j] > nums[k] && nums[k] > i)
					return true;
			}
		}
		return false;
	}
};

//思路是我们维护一个栈和一个变量third，其中third就是第三个数字，
//也是pattern 132中的2，栈里面按顺序放所有大于third的数字，
//也是pattern 132中的3，那么我们在遍历的时候，如果当前数字小于third，
//即pattern 132中的1找到了，我们直接返回true即可，因为已经找到了，
//注意我们应该从后往前遍历数组。如果当前数字大于栈顶元素，
//那么我们按顺序将栈顶数字取出，赋值给third，然后将该数字压入栈，
//这样保证了栈里的元素仍然都是大于third的，我们想要的顺序依旧存在，
//进一步来说，栈里存放的都是可以维持second > third的second值，
//其中的任何一个值都是大于当前的third值，如果有更大的值进来，
//那就等于形成了一个更优的second > third的这样一个组合，
//并且这时弹出的third值比以前的third值更大，为什么要保证third值更大，
//因为这样才可以更容易的满足当前的值first比third值小这个条件，

class Solution {
public:
	bool find132pattern(vector<int>& nums) {
		stack<int> s;
		int third = INT_MIN;
		for (int i = nums.size() - 1; i >= 0; --i)
		{
			if (nums[i] < third)
				return true;
			else
			{
				while (!s.empty() && s.top() < nums[i])
				{
					third = s.top();
					s.pop();
				}
			}
			s.push(nums[i]);
		}

		return false;
	}
};










