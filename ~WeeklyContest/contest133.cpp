#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <bitset>
#include <unordered_set>
#include <queue>
#include <string>

using namespace std;



class Solution1033 {
public:
	vector<int> numMovesStones(int a, int b, int c) {
		vector<int> v = { a,b,c };
		sort(v.begin(), v.end());

		int len1 = v[1] - v[0] - 1;
		int len2 = v[2] - v[1] - 1;

		if (len1 == 0 && len2 == 0)
			return { 0,0 };
		if (len1 == 0)
			return { 1,len2 };
		if (len2 == 0)
			return { 1,len1 };

		
		vector<int> res;
		helper(v, 0, res);
		int m = res[0];

		for (auto i : res)
		{
			m = min(m, i);
		}

		return { m,len1 + len2 };
	}

	int helper(vector<int> v, int level, vector<int>& res)
	{
		sort(v.begin(), v.end());

		int len1 = v[1] - v[0] - 1;
		int len2 = v[2] - v[1] - 1;

		if (len1 == 0 && len2 == 0)
		{
			res.push_back(level);
			return 0;
		}
		if (len1 == 0 || len2 == 0)
		{
			res.push_back(level + 1);
			return 1;
		}

		int cur = INT_MAX;
		int i,pre;
		

		if (len1 > len2)
		{
			pre = v[1] + 1;
			i = v[1] + 1;
			for (; i < v[2]; ++i)
			{
				if (i == v[1]) continue;
				v[0] = i;
				cur = 1 + min(cur, helper(v, level + 1, res));
				v[0] = pre;
			}
		}

		else
		{
			pre = v[1] - 1;
			i = v[1] - 1;
			for (; i > v[0]; --i)
			{
				if (i == v[1]) continue;
				v[2] = i;
				cur = 1 + min(cur, helper(v, level + 1, res));
				v[2] = pre;
			}
		}

		/*
		int pre = v[0];
		i = pre + 1;
		while (i < v[2])
		{
			if (i == v[1]) ++i;
			break;
		}
		for (; i < v[2]; ++i)
		{
			if (i == v[1]) continue;
			v[0] = i;
			cur = 1 + min(cur, helper(v, level + 1, res));
			v[0] = pre;
		}

		pre = v[2];
		i = pre - 1;
		while (i > v[0])
		{
			if (i == v[1]) --i;
			break;
		}
		for (; i > v[0]; --i)
		{
			if (i == v[1]) continue;
			v[2] = i;
			cur = 1 + min(cur, helper(v, level + 1, res));
			v[2] = pre;
		}
		*/


		return cur;
	}

};
