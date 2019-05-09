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

class Solution836 {
public:
	bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
		if (rec1[0] > rec2[0]) {
			using std::swap;
			swap(rec1, rec2);
		}

		if ((rec2[0] == rec1[0] || rec2[0] < rec1[2]) && ((rec2[1] < rec1[3] && rec2[1] > rec1[1]) ||
			(rec2[3]<rec1[3] && rec2[3]>rec1[1]))) return true;

		if ((rec2[0] == rec1[0] || rec2[0] < rec1[2]) && ((rec2[1] == rec1[1] && rec2[3]>rec1[1]) ||
			(rec2[3] == rec1[3] && rec2[1]<rec1[3]))) return true;
		
		if ((rec2[0] == rec1[0] || rec2[0] < rec1[2]) && (rec2[1] < rec1[1] && rec2[3] > rec1[3])) return true;
		

		return false;
	}
};



class Solution837 {
public:
	string pushDominoes(string dominoes) {
		string d = 'L' + dominoes + 'R';
		string res;
		int left = 0, right = 1;
		for (;right < d.size(); ++right)
		{
			if (d[right] == '.') continue;
			if (d[left] == d[right])
			{
				//res += d.substr(left, right - left);
				res += string(right - left, d[left]);
				left = right;
			}
			else if (d[left] == 'L' && d[right] == 'R')
			{
				res += d.substr(left, right - left);
				left = right;
			}
			else
			{
				int mid = right - left - 1;
				if (mid % 2 == 0)
				{
					res += string(mid / 2 + 1, 'R');
					res += string(mid / 2, 'L');
				}
				else
				{
					res+= string(mid / 2 + 1, 'R');
					res += '.';
					res += string(mid / 2, 'L');
				}
				left = right;
			}
			cout << res << endl;
		}

		res.erase(res.begin());
		return res;
	}
};

