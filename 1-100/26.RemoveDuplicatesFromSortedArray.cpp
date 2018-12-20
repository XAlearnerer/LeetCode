#include<iostream>
using namespace std;
#include<vector>


//class Solution1 {
//public:
//	int removeDuplicates(vector<int>& nums) {
//		if (nums.empty())
//			return 0;
//		int n = 0;
//		for (int i = 1; i != nums.size(); ++i)
//		{
//			if (nums[i] == nums[i - 1])
//				++n;
//		}
//		return n;
//	
//	}
//};

//? 需要修改nums的内容

class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		if (nums.empty()) return 0;
		int i = 0, j = 1;
		while (j < nums.size())
		{
			if (nums[i] == nums[j]) ++j;
			else
			{
				++i;
				nums[i] = nums[j];
				++j;
			}
		}
		return i + 1;
	}
};

int main1645()
{
	Solution n;
	vector<int> v = { 0,0,1,1,1,2,2,3,3,4 };
	//cout << n.removeDuplicates(v) << endl;
	int m = n.removeDuplicates(v);
	for (int i=0;i!=m;++i)
		cout << v[i] << endl;
	return 0;
}


