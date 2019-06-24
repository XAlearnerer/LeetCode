#include<iostream>
#include<algorithm>

using namespace std;

class Solution {
public:
	int reverse(int x) {
		long res = 0;
		while (x != 0)
		{
			res = res * 10 + x % 10;
			x /= 10;
		}
		if (res > INT_MAX || res < INT_MIN) return 0;
		return res;
	}

};


int main()
{
	int a = -123;
	Solution n;
	cout << n.reverse(a) << endl;

	return 0;
}