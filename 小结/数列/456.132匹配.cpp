#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>

using namespace std;


//Given a sequence of n integers a1, a2, ..., an, a 132 pattern is a subsequence ai, aj, ak 
//such that i < j < k and ai < ak < aj.Design an algorithm that takes a list of n numbers as input 
//and checks whether there is a 132 pattern in the list.
//
//Note: n will be less than 15, 000.
//
//Example 1 :
//Input : [1, 2, 3, 4]
//
//Output : False
//
//Explanation : There is no 132 pattern in the sequence.
//Example 2 :
//Input : [3, 1, 4, 2]
//
//Output : True
//
//Explanation : There is a 132 pattern in the sequence : [1, 4, 2].
//Example 3 :
//Input : [-1, 3, 2, 0]
//
//Output : True
//Explanation : There are three 132 patterns in the sequence : [-1, 3, 2], [-1, 3, 0] and [-1, 2, 0].



class Solution_01 {
public:
	bool find132pattern(vector<int>& nums) {
		int n = nums.size(), tmp = INT_MAX;
		for (int i = 0; i < n; ++i)
		{
			tmp = min(tmp, nums[i]);        // find 1
			if (tmp == nums[i]) continue;
			for (int k = n - 1; k > i; --k)
			{
				if (tmp < nums[k] && nums[k] < nums[i]) return true;  //search 2 and 3
			}
		}

		return false;
	}
};



/////////////////////////////////////////////////////////////////////////////////////////////////


//思路是我们维护一个栈和一个变量 third，其中 third 就是第三个数字，
//也是 pattern 132 中的2，初始化为整型最小值，栈里面按顺序放所有大于 third 的数字，
//也是 pattern 132 中的3，那么我们在遍历的时候，如果当前数字小于 third，即 pattern 132 中的1找到了，
//我们直接返回 true 即可，因为已经找到了，注意我们应该从后往前遍历数组。

//如果当前数字大于栈顶元素，那么我们将栈顶数字取出，赋值给 third，然后将该数字压入栈，
//这样保证了栈里的元素仍然都是大于 third 的，

class Solution {
public:
	bool find132pattern(vector<int>& nums) {
		int th = INT_MIN;
		stack<int> t;
		for (int i = nums.size() - 1; i >= 0; --i)
		{
			if (nums[i] < th) return true;
			while (!t.empty() && t.top() < nums[i])
			{
				th = t.top(); t.pop();
			}
			t.push(nums[i]);
		}
		return false;
	}
};

