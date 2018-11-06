#include<iostream>
#include<math.h>
using namespace std;

class Solution {
public:
	int uniquePaths(int m, int n) {
		//return (int)((fac(m + n - 2) / (fac(m - 1)*fac(n - 1))));
		return m > n ? (int)(fac2(m + n - 2, m) / fac2(n - 1, 1)) : (int)(fac2(m + n - 2, n) / fac2(m - 1, 1));

	}
	long double fac2(int n, int m)
	{
		long double i, f = 1;
		for (i = m; i <= n; ++i)
			f *= i;
		return f;
	}

	/*long double fac(int x)
	{
		long double i, f = 1; 
		for (i = 1; i <= x; i++)
			f *= i;
		return f;
	}*/
};

int main1716()
{
	Solution n;
	cout << n.uniquePaths(36, 7) << endl;
	return 0;
}