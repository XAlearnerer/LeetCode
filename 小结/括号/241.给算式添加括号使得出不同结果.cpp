#include<iostream>
#include<vector>
#include<string>

using namespace std;

class Solution {
public:
	vector<int> diffWaysToCompute(string input) {
		if (input.empty()) return {};
		vector<int> res;
		for (int i = 0; i < input.size(); ++i)
		{
			if (input[i] == '+' || input[i] == '-' || input[i] == '*')
			{
				vector<int> l = diffWaysToCompute(input.substr(0, i));
				vector<int> r = diffWaysToCompute(input.substr(i + 1));

				for (int j = 0; j < l.size(); ++j)
				{
					for (int k = 0; k < r.size(); ++k)
					{
						if (input[i] == '+') res.push_back(l[j] + r[k]);
						else if (input[i] == '-') res.push_back(l[j] - r[k]);
						else res.push_back(l[j] * r[k]);
					}
				}
			}
		}
		// 终止条件：
		if (res.empty()) res.push_back(stoi(input));


		return res;
	}
};


