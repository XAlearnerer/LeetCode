#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

class Solution2 {
public:
	vector<int> twoSum(vector<int>& numbers, int target) {
		int i = 0, j = numbers.size() - 1;
		while (i < j)
		{
			if (numbers[i] + numbers[j] == target) return { i + 1,j + 1 };
			if (target - numbers[i] > numbers[j])
				++i;
			else
				--j;
		}
		return {};
	}
};

class Solution {
public:
	vector<int> twoSum(vector<int>& numbers, int target) {
		unordered_map<int, int> m;
		for (int i = 0; i != numbers.size(); ++i)
			m[numbers[i]] = i;

		for (int i = 0; i != numbers.size(); ++i)
		{
			int j = target - numbers[i];
			if (m.count(j) != 0)
			{
				return { i + 1,m[j] + 1 };
			}
		}
		return {};
	}
};