#include<iostream>
#include<vector>
#include<algorithm>
#include<xfunctional>

using namespace std;

class Solution {
public:
	int hIndex(vector<int>& citations) {
		int left = 0, right = citations.size() - 1;
		while (left <= right)
		{
			int mid = left + (right - left) / 2;
			if (citations[mid] == citations.size() - left) return citations.size() - mid;
			else if (citations[mid] < citations.size() - mid) left = mid + 1; 
			else right = mid - 1;

		}
		return citations.size() - left;
	}
};