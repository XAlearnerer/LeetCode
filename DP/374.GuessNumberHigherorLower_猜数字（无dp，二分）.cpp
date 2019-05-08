#include<iostream>
#include<vector>
using namespace std;

// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num);

class Solution_worng { //TLE
public:
	int guessNumber(int n) {
		while (1)
		{
			if (guess(n) == 0)
				return n;
			else if (guess(n) == 1)
				++n;
			else
				--n;
		}

	}
};

class Solution {
public:
	int guessNumber(int n) {
		int left = 1, right = n;
		while (1)
		{
			//int mid = (left + right) / 2;
			int mid= (right - left) / 2 + left;
			if (guess(mid) == 0) return mid;
			else if (guess(mid) == 1) left = mid + 1;
			else right = mid - 1;
		}
	}
};