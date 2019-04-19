#include<iostream>
#include<vector>
#include<string>

using namespace std;

class Solution {
public:
	vector<int> diffWaysToCompute(string input) {
		vector<int> res;
		for (int i = 0; i != input.length(); ++i)
		{
			if (input[i] == '+' || input[i] == '-' || input[i] == '*')
			{
				vector<int> lv = diffWaysToCompute(input.substr(0, i));
				vector<int> lr = diffWaysToCompute(input.substr(i + 1));
				for (int p = 0; p != lv.size(); ++p)
				{
					for (int q = 0; q != lr.size(); ++q)
					{
						if (input[i] == '+')
							res.push_back(lv[p] + lr[q]);
						else if (input[i] == '-')
							res.push_back(lv[p] - lr[q]);
						else
							res.push_back(lv[p] * lr[q]);
					}
				}
			}
		}
		if (res.empty()) res.push_back(stoi(input));
		return res;
	}
};
















