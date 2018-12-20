#include<iostream>
#include<vector>
using namespace std;

class Solution2 {
public:
	int removeDuplicates(int A[], int n) {
		if (n <= 2) return n;
		int pre = 0, cur = 1, count = 1;

		while (cur < n) {
			if (A[pre] == A[cur] && count == 0) ++cur;
			else {
				if (A[pre] == A[cur]) --count;
				else count = 1;
				A[++pre] = A[cur++];
			}
		}

		for (int i = 0; i != pre + 1; ++i)
		{
			cout << A[i] << " ";
		}
		cout << endl;

		return pre + 1;
	}
};


class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		if (nums.size() < 3) return nums.size();
		int pre = 0, cur = 1, count = 1;
		while (cur < nums.size()) {
			if (nums[pre] == nums[cur] && count == 0) ++cur;
			else {
				if (nums[pre] == nums[cur]) --count;
				else count = 1;
				nums[++pre] = nums[cur++];
			}
		}

		return pre + 1;
	}
};

int main1031()
{
	vector<int> v = { 1,1,1,2,2,3 };
	Solution n;
	int len = n.removeDuplicates(v);
	for (int i = 0; i != len; ++i)
	{
		cout << v[i] << " ";
	}

	cout << "\n=======" << endl;
	int a[9] = { 0,0,1,1,1,1,2,3,3 };
	Solution2 n2;
	n2.removeDuplicates(a, 9);
	
	return 0;
}



