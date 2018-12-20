#include<iostream>
using namespace std;
#include<vector>
#include<string>


class Solution2 {
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


class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> factorial(n,1);
        string nums(n,'a');
        string res="";

        for(int i=1;i!=n;++i)
            factorial[i]=factorial[i-1]*i;
        for(int i=0;i!=n;++i)
            nums[i]=i+1+'0';
        int a;
        --k;

        while(n>=1)
        {
            a=k/factorial[n-1];
            res+=nums[a];
            k%=factorial[n-1];
            nums.erase(a,1);
            --n;
        }

        return res;
    }
};



int main2205()
{
	Solution n;
	cout << n.getPermutation(4, 17) << endl;
	return 0;
}
