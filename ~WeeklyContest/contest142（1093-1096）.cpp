#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <bitset>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <string>
#include <set>
#include <map>

using namespace std;

class Solution1093 {
public:
	vector<double> sampleStats(vector<int>& count) {

	}
};


////////////////////////////////////////////////////////////////////////////////////



class Solution1094 {
public:
	bool carPooling(vector<vector<int>>& trips, int capacity) {
		if (trips.empty()) return true;
		sort(trips.begin(), trips.end(), [](vector<int>a, vector<int>b)
		{
			if (a[1] == b[1]) return a[2] < b[2];
			else return a[1] < b[1];
		});

		int lon = 0;
		for (int i = 0; i < trips.size(); ++i)
			if (trips[i][2] > lon) lon = trips[i][2];

		vector<int> passer(lon, 0);
		for (int i = 0; i < trips.size(); ++i)
		{
			for (int j = trips[i][1]; j < trips[i][2]; ++j)
				passer[j] += trips[i][0];
		}

		for (int i = 0; i < passer.size(); ++i)
		{
			if (passer[i] > capacity) return false;
		}
		return true;
	}
};


////////////////////////////////////////////////////////////////////////////////////


class MountainArray {
public:
	int get(int index)
	{
		return v[index];
	}
	int length()
	{
		return v.size();
	}

	MountainArray(vector<int> v1) :v(v1) {}
	vector<int> v;
};

class Solution1095 {
public:
	int findInMountainArray(int target, MountainArray &mountainArr) {
		int len = mountainArr.length();
		return helper(target, mountainArr, 0, len - 1);
	}


	int helper(int target, MountainArray &mountainArr, int left, int right)
	{
		if (right - left == 2)
		{
			if (mountainArr.get(left) == target) return left;
			else if (mountainArr.get(left + 1) == target) return left + 1;
			else if (mountainArr.get(right) == target) return right;
			else return -1;
		}
		int mid = left + (right - left) / 2;
		if (mountainArr.get(mid) > mountainArr.get(mid - 1) && mountainArr.get(mid) > mountainArr.get(mid + 1))
		{
			int r1 = binarysearch1(target, mountainArr, 0, mid);
			if (r1 != -1) return r1;
			else
				return binarysearch2(target, mountainArr, mid, right);
		}
		else
		{
			if (mountainArr.get(mid) >= target)
			{
				if (mountainArr.get(mid) > mountainArr.get(mid - 1))
				{
					if (mountainArr.get(mid) == target) return mid;
					int r1 = binarysearch1(target, mountainArr, 0, mid);
					if (r1 != -1) return r1;
				}
				//if (mountainArr.get(mid) < mountainArr.get(mid - 1))
				else
				{
					int r0 = helper(target, mountainArr, left, mid);
					if (r0 != -1) return r0;
					else
					{
						if (mountainArr.get(mid) == target) return mid;
						int r1 = binarysearch2(target, mountainArr, mid, right);
						if (r1 != -1) return r1;
					}
				}
			}
			else
			{
				if (mountainArr.get(mid) > mountainArr.get(mid - 1))
					return helper(target, mountainArr, mid, right);
				else
					return helper(target, mountainArr, left, mid);
			}
		}

		return -1;
	}

	int binarysearch1(int target, MountainArray &mountainArr, int left, int right)
	{
		while (left < right)
		{
			int mid = left + (right - left) / 2;
			if (mountainArr.get(mid) == target) return mid;
			else
			{
				if (mountainArr.get(mid) < target) left = mid + 1;
				else right = mid;
			}
		}

		return -1;
	}

	int binarysearch2(int target, MountainArray &mountainArr, int left, int right)
	{
		while (left <= right)
		{
			int mid = left + (right - left) / 2;
			if (mountainArr.get(mid) == target) return mid;
			else
			{
				if (mountainArr.get(mid) < target) right = mid - 1;
				else left = mid + 1;
			}
		}

		return -1;
	}

};



//? Triple Binary Search

class Solution1095__2 {
public:
	int findInMountainArray(int target, MountainArray &mountainArr) {
		int len = mountainArr.length();
		int peak = 0, l = 0, r = len - 1;
		while (l < r)
		{
			int m = l + (r - l) / 2;
			if (mountainArr.get(m) < mountainArr.get(m + 1))
			{
				l = m + 1;
				peak = m + 1;
			}
			else
				r = m;
		}

		l = 0;
		r = peak;
		while (l <= r)
		{
			int m = l + (r - l) / 2;
			if (mountainArr.get(m) == target) return m;
			else if (mountainArr.get(m) > target) r = m - 1;
			else l = m + 1;
		}

		l = peak;
		r = len - 1;
		while (l <= r)
		{
			int m = l + (r - l) / 2;
			if (mountainArr.get(m) == target) return m;
			else if (mountainArr.get(m) < target) r = m - 1;
			else l = m + 1;
		}

		return -1;
	}
};



////////////////////////////////////////////////////////////////////////////////////
