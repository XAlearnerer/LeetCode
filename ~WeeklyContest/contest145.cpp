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


class Solution1122 {
public:
	vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
		map<int, int> m;
		for (auto i : arr1) ++m[i];
		vector<int> res;
		for (auto i : arr2)
		{
			while (m[i] > 0) { --m[i]; res.push_back(i); }
		}

		for (auto i : m)
		{
			while (i.second > 0) { --i.second; res.push_back(i.first); }
		}

		return res;
	}
};





/////////////////////////////////////////////////////////////////////////////////////////


//886



struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution1123 {
public:
	TreeNode* lcaDeepestLeaves(TreeNode* root) {
		if (!root) return root;
		int l = depth(root->left);
		int r = depth(root->right);
		if (l == r) return root;
		else if (l > r) return lcaDeepestLeaves(root->left);
		else return lcaDeepestLeaves(root->right);
	}

	int depth(TreeNode* root)
	{
		if (!root) return 0;
		return 1 + max(depth(root->left), depth(root->right));
	}
};





/////////////////////////////////////////////////////////////////////////////////////////



//class Solution1124 {
//public:
//	int longestWPI(vector<int>& hours) {
//		if (hours.empty()) return 0;
//		int o = 0, z = 0;
//		int res = 0, cur = 0;
//
//		if (hours[0] > 8) ++o;
//		else ++z;
//
//		for (int i = 1; i < hours.size(); ++i)
//		{
//			if (hours[i] > 8)
//			{
//				if (o >= z)
//				{
//					++o;
//					if (o > z) res = max(res, o + z);
//					else res = max(res, 2 * o - 1);
//				}
//				else
//				{
//					if (hours[i - 1] > 8) ++o;
//					else o = 1;
//					if (o > z) res = max(res, o + z);
//					else res = max(res, 2 * o - 1);
//				}
//			}
//			else
//			{
//				if (o >= z)
//				{
//					++z;
//					if (o > z) res = max(res, o + z);
//					else res = max(res, 2 * o - 1);
//				}
//				else
//				{
//					if (hours[i - 1] <= 8) ++z;
//					else z = 1;
//					if (o > z) res = max(res, o + z);
//					else res = max(res, 2 * o - 1);
//				}
//			}
//
//		}
//
//		return res;
//	}
//};
//
//
//class Solution {
//public:
//	int longestWPI(vector<int>& hours) {
//		if (hours.empty()) return 0;
//		int o = 0, z = 0;
//		int res = 0;
//
//		if (hours[0] > 8) ++o;
//		else ++z;
//
//		for (int i = 1; i < hours.size(); ++i)
//		{
//			if (hours[i] > 8)
//			{
//				if (hours[i - 1] > 8) ++o;
//				else
//				{
//					if (o < z) o = 1;
//					else ++o;
//				}
//				
//				if (o > z) res = max(res, o + z);
//				else res = max(res, 2 * o - 1);
//			}
//			else
//			{
//				if (hours[i - 1] <= 8) ++z;
//				else
//				{
//					if (o < z) o = 0;
//					else ++z;
//				}
//				if (o > z) res = max(res, o + z);
//				else res = max(res, 2 * o - 1);
//			}
//		}
//
//		return res;
//	}
//};


//?    ?????????????????

class Solution {
public:
	int longestWPI(vector<int>& hours) {
		int n = hours.size();

		unordered_map<int, int> mp;
		int result = 0, sum = 0;
		for (int i = 0; i < n; i++) {
			if (hours[i] > 8) {
				sum++;
			}
			else {
				sum--;
			}

			if (sum > 0)   result = i + 1;
			else if (sum <= 0) {
				if (mp.find(sum - 1) != mp.end()) {
					result = max(result, i - mp[sum - 1]);
				}
			}
			if (mp.find(sum) == mp.end())
				mp[sum] = i;
		}
		return result;
	}



	int longestWPI_2(vector<int>& hours) {
		int res = 0, score = 0, n = hours.size();
		unordered_map<int, int> seen = { { 0, -1 } };
		for (int i = 0; i < n; ++i) {
			score += hours[i] > 8 ? 1 : -1;
			if (score > 0) {
				res = i + 1;
			}
			else {
				if (seen.find(score) == seen.end())
					seen[score] = i;
				if (seen.find(score - 1) != seen.end())
					res = max(res, i - seen[score - 1]);
			}
		}
		return res;
	}

};

int main()
{
	vector<int> v = { 8,10,6,16,5 };
	Solution n;
	cout << n.longestWPI(v) << endl;

	return 0;
}





/////////////////////////////////////////////////////////////////////////////////




class Solution1125 {
public:
	vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people) {



	}
};













