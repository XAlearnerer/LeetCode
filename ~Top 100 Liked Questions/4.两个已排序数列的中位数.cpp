#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//class Solution {
//public:
//	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
//		if (nums1.empty() && nums2.empty()) return 0;
//		if (nums1.empty())
//		{
//			if (nums2.size() % 2)
//			{
//				return (double)((nums2[nums2.size() / 2] + nums2[nums2.size() / 2 - 1]) / 2);
//			}
//			else
//				return (double)(nums2[nums2.size() / 2]);
//		}
//
//		if (nums2.empty())
//		{
//			if (nums1.size() % 2)
//			{
//				return (double)((nums1[nums2.size() / 2] + nums1[nums2.size() / 2 - 1]) / 2);
//			}
//			else
//				return (double)(nums1[nums1.size() / 2]);
//		}
//
//		int len1 = nums1.size(), len2 = nums2.size();
//		int mid = (len1 + len2) / 2;
//		int count = 0;
//		int i = 0, j = 0;
//		int pre = 0, cur = 0;
//		if (nums1[i] > nums2[j]) { pre = nums2[j]; ++j; }
//		else { pre = nums1[i]; ++i; }
//
//		while (i < len1 && j < len2)
//		{
//			
//		}
//
//
//	}
//};



class Solution {
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		
		// 我们使用一个小 trick，分别找第(m + n + 1) / 2 个，和(m + n + 2) / 2 个，
		// 然后求其平均值即可，这对奇偶数均适用。若 m + n 为奇数的话，
		// 那么其实(m + n + 1) / 2 和(m + n + 2) / 2 的值相等，
		// 相当于两个相同的数字相加再除以2，还是其本身。


		if (nums1.empty())
			return nums2.size() % 2 == 1 ? (double)nums2[(nums2.size()) / 2] : ((double)nums2[(nums2.size()) / 2] + (double)nums2[(nums2.size()) / 2 - 1]) / 2;

		if (nums2.empty())
			return nums1.size() % 2 == 1 ? (double)nums1[(nums1.size()) / 2] : ((double)nums1[(nums1.size()) / 2] + (double)nums1[(nums1.size()) / 2 - 1]) / 2;

		int a = nums1.size(), b = nums2.size();
		int v1 = (a + b + 1) / 2, v2 = (a + b + 2) / 2;
		return (findKth(nums1, 0, nums2, 0, v1) + findKth(nums1, 0, nums2, 0, v2)) / 2.0;

	}

	int findKth(vector<int>& nums1, int i, vector<int>& nums2, int j, int k)
	{
		if (i >= nums1.size()) return nums2[j + k - 1];
		if (j >= nums2.size()) return nums1[i + k - 1];

		if (k == 1) return min(nums1[i], nums2[j]);

		int a = 0, b = 0;
		if (i + k / 2 - 1 < nums1.size()) a = nums1[i + k / 2 - 1];
		else a = INT_MAX;
		if (j + k / 2 - 1 < nums2.size()) b = nums2[j + k / 2 - 1];
		else b = INT_MAX;

		if (a < b)
			return findKth(nums1, i + k / 2 , nums2, j, k - k / 2);  //? 注意是 k - k / 2;
		else
			return findKth(nums1, i, nums2, j + k / 2 , k - k / 2);
	}

};
