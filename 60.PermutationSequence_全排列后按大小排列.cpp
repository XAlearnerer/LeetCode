#include<iostream>
using namespace std;
#include<vector>
#include<string>

class Solution {
public:
	string getPermutation(int n, int k) {
		int ki = 1;
		string solu(n, ' ');
		for (int i = 1; i <= n; ++i)
			solu[i - 1] = i + '0';
		string ss = " ";
		getK(solu, 0, ki, k, ss);
		return ss;

	}
	void getK(string& solu, int begin, int& ki, int k,string& ss)
	{
		if (ss != " ") return;
		if (begin == solu.size())
		{
			if (ki == k)
			{
				ss = solu;
				return;
			}
			ki++;
		}
		for (int i = begin; i != solu.size(); ++i)
		{
			swap(solu[begin], solu[i]);
			getK(solu, begin + 1, ki, k,ss);
			swap(solu[begin], solu[i]);
		}
	
	}
};

int main1807()
{
	Solution n;
	cout << n.getPermutation(3, 3) << endl;
	return 0;
}