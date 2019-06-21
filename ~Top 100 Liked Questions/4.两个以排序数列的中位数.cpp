#include<iostream>
#include<vector>
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





