#include<iostream>
using namespace std;

class Solution {
public:
	double myPow(double x, int n) {
		if (n == 0) return 1;
		double m = myPow(x, n / 2);
		if (n % 2 == 0) return m*m;
		else if (n > 0)return m*m*x;
		else return m*m / x;

	}
};

class Solution2 {
public:
	double myPow(double x, int n) {
		double res = 1.0;
		for (int i = n; i != 0; i /= 2) {
			if (i % 2 != 0) res *= x;
			x *= x;
		}
		return n < 0 ? 1 / res : res;
	}
};

