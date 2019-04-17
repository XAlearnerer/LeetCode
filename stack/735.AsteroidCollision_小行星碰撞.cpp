#include<iostream>
#include<vector>
#include<stack>

using namespace std;


//////////  worng
//class Solution {  
//public:
//	vector<int> asteroidCollision(vector<int>& asteroids) {
//		if (asteroids.empty()) return {};
//		stack<int> s;
//		vector<int> res;
//		int n = asteroids.size();
//		s.push(asteroids[0]);
//		for (int i = 1; i != n; ++i)
//		{
//			if (isSameSymbol(s.top(), asteroids[i])) s.push(asteroids[i]);
//			else
//			{
//				int cur = s.top();
//				if (toPositive(cur) == toPositive(asteroids[i]))
//				{
//					s.pop();
//				}
//				else if (toPositive(cur) > toPositive(asteroids[i]))
//				{}
//				else
//				{
//					s.pop();
//					while (!s.empty())
//					{
//						cur = s.top();
//						if (toPositive(cur) < toPositive(asteroids[i]))
//							s.pop();
//						else
//							break;
//					}
//					if (s.empty())
//						s.push(asteroids[i]);
//				}
//
//			}
//		}
//
//		while (!s.empty())
//		{
//			res.push_back(s.top());
//			s.pop();
//		}
//
//		reverse(res.begin(), res.end());
//		return res;
//	}
//
//	bool isSameSymbol(int a, int b)
//	{
//		if ((a > 0 && b > 0) || (a < 0 && b < 0))return true;
//		else return false;
//	}
//
//	int toPositive(int a)
//	{
//		if (a > 0) return a;
//		else
//			return -a;
//	}
//};
//




class Solution {
public:
	vector<int> asteroidCollision(vector<int>& asteroids) {
		vector<int> res;
		for (int i = 0; i != asteroids.size(); ++i)
		{
			if (asteroids[i] > 0) res.push_back(asteroids[i]);
			else if (res.empty() || res.back() < 0) res.push_back(asteroids[i]);
			else 
			{
				if (-asteroids[i] < res.back())continue;
				else
				{
					if (-asteroids[i] > res.back()) --i;
					res.pop_back();
				}
			}
		}

		return res;
	}
};









