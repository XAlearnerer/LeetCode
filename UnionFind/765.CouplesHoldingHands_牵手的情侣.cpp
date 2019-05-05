#include<iostream>
#include<vector>

using namespace std;


////////// Greedy /////////

// 一个trick，一个数‘异或’上1就是其另一个位，
// 这个不难理解，如果是偶数的话，最后位是0，
// ‘异或’上1等于加了1，变成了可以的成对奇数。
// 
// 如果是奇数的话，最后位是1，‘异或’上1后变为了0，
// 变成了可以的成对偶数。



class Solution2 {
public:
	int minSwapsCouples(vector<int>& row) {
		int res = 0;
		int i = 0;
		while (i < row.size())
		{
			if (row[i + 1] == (row[i] ^ 1)) 
			{
				i += 2;
				continue;
			}
			for (int j = i + 2; j < row.size();++j)
			{
				if (row[j] == (row[i] ^ 1))
				{
					swap(row[i + 1], row[j]);
					break;
				}
			}
			++res;
			i += 2;
		}
		return res;
	}
};


//////////// unionfind ////////////////

class Solution {
public:
	int minSwapsCouples(vector<int>& row) {
		vector<int> root(row.size(), 0);
		int res = 0;
		for (int i = 0; i != row.size(); ++i) root[i] = i;
		for (int i = 0; i != row.size(); i += 2)
		{
			int m = find(root, row[i] / 2);
			int n = find(root, row[i + 1] / 2);
			if (m != n)
			{
				root[m] = n;
				++res;  //?  这里没想通
			}
		}
		return res;
	}
	int find(vector<int>& root, int i)
	{
		while (i != root[i])
		{
			root[i] = root[root[i]];
			i = root[i];
		}
		return i;
	}
};



int main()
{
	vector<int> r = { 0, 2, 1, 3 };
	Solution n;
	cout << n.minSwapsCouples(r) << endl;
	return 0;
}
