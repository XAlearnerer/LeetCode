#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


// Input: A = [[0, 2], [5, 10], [13, 23], [24, 25]], B = [[1, 5], [8, 12], [15, 24],
// 	 [25, 26]]
// Output : [[1, 2], [5, 5], [8, 10], [15, 23], [24, 24], [25, 25]]


//归并排序


class Solution {
public:
	vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
		vector<vector<int>> res;
		int i = 0, j = 0;
		while (i < A.size() && j < B.size())
		{
			if (A[i][1] < B[j][0])
				++i;
			else if (B[j][1] < A[i][0])
				++j;
			else
			{
				res.push_back({ max(A[i][0],B[j][0]),min(A[i][1],B[j][1]) });
				if (A[i][1] < B[j][1]) ++i;
				else ++j;
			}
		}
		return res;
	}
};




