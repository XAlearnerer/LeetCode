#include<iostream>
#include<string>

using namespace std;

class Solution {
public:
	string removeKdigits(string num, int k) {
		if (k == num.size()) return "0";
		int n = num.length();
		string res = "";
		int reslen = n - k;
		for (char c : num)
		{
			while (k && c < res.back() && res.size() > 0)
			{
				res.pop_back();
				--k;
			}
			res.push_back(c);
		}

		res.resize(reslen);
		while (!res.empty() && res[0] == '0') res.erase(res.begin());
		if (res.empty()) return "0";
		return res;
	}
};







//
//这道题让我们将给定的数字去掉k位，要使得留下来的数字最小，
//这题跟LeetCode上之前那道Create Maximum Number有些类似，
//可以借鉴其中的思路，如果n是num的长度，我们要去除k个，那么需要剩下n - k个，
//我们开始遍历给定数字num的每一位，对于当前遍历到的数字c，
//进行如下while循环，如果res不为空，且k大于0，且res的最后一位大于c，
//那么我们应该将res的最后一位移去，且k自减1。当跳出while循环后，我们将c加入res中，
//最后我们将res的大小重设为n - k。根据题目中的描述，可能会出现"0200"这样不符合要求的情况，
//所以我们用一个while循环来去掉前面的所有0，然后返回时判断是否为空，为空则返回“0”
