#include<iostream>
#include<vector>
#include<string>

using namespace std;

class Solution {
public:
	vector<string> addOperators(string num, int target) {
		vector<string> res;
		helper(num, target, 0, 0, "", res);
		return res;
	}

	void helper(string num, int target, long diff, long curSum, string out, vector<string>& res)
	{
		if (target == curSum && num.size() == 0) {
			res.push_back(out);
			return;
		}

		//? for (int i = 1; i != num.size(); ++i)
		for (int i = 1; i <= num.size(); ++i)
		{
			string pre = num.substr(0, i);


			/*Wrong£º["0+0+0", "0+0-0", "0+0*0", "0-0+0", "0-0-0", "0-0*0", "0*0+0",
				"0*0-0", "0*0*0", "0+00", "0-00", "0*00", "00+0", "00-0", "00*0", "000"]
			Correct£º["0*0*0", "0*0+0", "0*0-0", "0+0*0", "0+0+0", "0+0-0", "0-0*0",
				"0-0+0", "0-0-0"]*/
			if (pre.size() > 1 && pre[0] == '0') return;


			string post = num.substr(i);
			if (out.size() == 0)
				helper(post, target, stol(pre), curSum + stol(pre), pre, res);
			else
			{
				helper(post, target, stol(pre), curSum + stol(pre), out + "+" + pre, res);
				helper(post, target, -stol(pre), curSum - stol(pre), out + "-" + pre, res);
				helper(post, target, stol(pre)*diff, (curSum - diff) + diff *stol(pre), out + "*" + pre, res);
			}
		}
	}
};






