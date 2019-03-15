//
// Created by zhao on 19-1-12.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
		int sum = 0;
		int start = 0, end = 1;
		while (end < prices.size())
        {
			if (prices[end] > prices[start])
            {
				sum += prices[end] - prices[start];
            }
			start = end;
			end = start + 1;
        }
        return sum;
    }
};
