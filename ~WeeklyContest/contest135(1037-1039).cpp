#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <bitset>
#include <unordered_set>
#include <queue>
#include <string>
#include <set>

using namespace std;

/////////////////////////////////////////////////////////////////

class Solution1037 {
public:
	bool isBoomerang(vector<vector<int>>& points) {
		if (points[0][0] == points[1][0] && points[1][0] == points[2][0]) return false;
		if (points[0][1] == points[1][1] && points[1][1] == points[2][1]) return false;

		if (points[0][1] - points[0][0] == points[1][1] - points[1][0]
			&& points[2][1] - points[2][0] == points[1][1] - points[1][0]) return false;

		// [[0,0],[2,1],[2,1]] false
		if ((points[0][0] == points[1][0] && points[0][1] == points[1][1])
			|| (points[1][0] == points[2][0] && points[1][1] == points[2][1])
			|| (points[0][0] == points[2][0] && points[0][1] == points[2][1]))
			return false;

		return true;
	}
};




/////////////////////////////////////////////////////////////////


struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution1038 {
public:
	TreeNode* bstToGst(TreeNode* root) {
		if (root)
		{
			bstToGst(root->right);
			root->val += sum;
			sum = root->val;
			bstToGst(root->left);
		}
		return root;
	}

	int sum = 0;
};



/////////////////////////////////////////////////////////////////

// Like LeetCode 312
class Solution1039 {
public:
	int minScoreTriangulation(vector<int>& A) {
		int n = A.size();
		vector<vector<int>> dp(n, vector<int>(n, 0));
		for (int dis = 2; dis != n; ++dis)
		{
			for (int i = 0; i + dis != n; ++i)
			{
				int j = i + dis;
				dp[i][j] = INT_MAX;
				for (int k = i + 1; k != j; ++k)
				{
					dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j] + A[i] * A[j] * A[k]);
				}
			}
		}
		return dp[0][n - 1];
	}
};

/////////////////////////////////////////////////////////////////

//Sliding Window
class Solution {
public:
	vector<int> numMovesStonesII(vector<int>& stones) {

	}
};