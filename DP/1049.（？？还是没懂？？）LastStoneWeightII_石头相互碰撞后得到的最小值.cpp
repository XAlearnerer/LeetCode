#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


//  Note:
//  1 <= stones.length <= 30
//  1 <= stones[i] <= 100


class Solution {
public:
	int lastStoneWeightII(vector<int>& stones) {
		return helper(stones, 0, 0);
	}

	short dp[30][6000] = {};
	int helper(vector<int>& A, int s, int i) 
	{
		if (i == A.size()) return s < 0 ? 100 : s;
		if (dp[i][s + 3000] == 0) dp[i][s + 3000] = 1 + min(
			helper(A, s + A[i], i + 1), helper(A, s - A[i], i + 1));
		return dp[i][s + 3000] - 1;
	}

};



//  You can merge stones into 2 giant ones, and do the epic smash.
//  
//  In other words, you can split all stones into two groups
//  by applying either plus or minus sign to each stone's value.
//  
//  Solution
//  Run DFS tracking the running sum, and try adding and subtracting the current stone.
//  In the end, return the result if it's not negative.
//  
//  Use memoization for the current stone[1, 30] and running sum[-3000, 3000].
//  
//  This can be futher optimized, but the runtime of this solution is already 4 ms.

