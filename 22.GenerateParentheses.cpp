#include<iostream>
using namespace std;
#include<vector>
#include<stack>
#include<set>

//class Solution {
//public:
//	vector<string> generateParenthesis(int n) {
//		set<string> t;
//		if (n == 0) t.insert("");
//		else {
//			vector<string> pre = generateParenthesis(n - 1);
//			for (auto a : pre) {
//				for (int i = 0; i < a.size(); ++i) {
//					if (a[i] == '(') {
//						a.insert(a.begin() + i + 1, '(');
//						a.insert(a.begin() + i + 2, ')');
//						t.insert(a);
//						a.erase(a.begin() + i + 1, a.begin() + i + 3);
//					}
//				}
//				t.insert("()" + a);
//			}
//		}
//		return vector<string>(t.begin(), t.end());
//	}
//};



class Solution {
public:
	vector<string> generateParenthesis(int n) {
		vector<string> res;
		generateParenthesisDFS(n, n, "", res);
		return res;
	}
	void generateParenthesisDFS(int left, int right, string out, vector<string> &res) {
		if (left > right) return;
		if (left == 0 && right == 0) res.push_back(out);
		else {
			if (left > 0) generateParenthesisDFS(left - 1, right, out + '(', res);
			if (right > 0) generateParenthesisDFS(left, right - 1, out + ')', res);
		}
	}
};








