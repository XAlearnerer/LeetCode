////#include<iostream>
////#include<vector>
////#include<limits.h>
////#include<algorithm>
////
////using namespace std;
////
//////9
//////1 3 4 7 2 6 5 12 32
//////
//////int main()
//////{
//////	int n = 9;
//////	//cin >> n;
//////	vector<int> v = { 1 ,4, 3 ,7, 2, 6, 5, 12, 32 };
//////	/*for (int i = 0; i < n; ++i)
//////	{
//////		int t;
//////		cin >> t;
//////		v.push_back(t);
//////	}*/
//////	pair<int, int> p;
//////	int min = INT_MAX;
//////
//////	for (int i = 0; i < n - 2; ++i)
//////	{
//////		if (abs(v[i + 1] - v[i]) < min)
//////		{
//////			min = abs(v[i + 1] - v[i]);
//////			p = { i,i + 1 };
//////		}
//////	}
//////
//////	cout << v[p.first] << " " << v[p.second] << endl;
//////	return 0;
//////}
//////
////
////
////
////
//////
//////#include<iostream>
//////#include<vector>
//////#include<limits.h>
//////#include<algorithm>
//////
//////using namespace std;
//////int main()
//////{
//////	int n;
//////	cin >> n;
//////	vector<long> v;
//////	for (int i = 0; i < n; ++i)
//////	{
//////		int t;
//////		cin >> t;
//////		v.push_back(t);
//////	}
//////	pair<int, int> p;
//////	int min = INT_MAX;
//////
//////	for (int i = 0; i < n - 2; ++i)
//////	{
//////		if (abs(v[i + 1] - v[i]) < min)
//////		{
//////			min = abs(v[i + 1] - v[i]);
//////			p = { i,i + 1 };
//////		}
//////	}
//////
//////	cout << v[p.first] << " " << v[p.second] << endl;
//////	return 0;
//////}
////
////
////
////
//////int main()
//////{
//////	int n = 8;
//////	vector<int> v = { 5,1,6,8,2,4,5,10 };
//////	vector<int> dp;
//////	for (int i = 0; i < n; ++i)
//////	{
//////		int left = 0, right = dp.size();
//////		while (left < right)
//////		{
//////			int mid = left + (right - left) / 2;
//////			if (dp[mid] < v[i]) left = mid + 1;
//////			else right = mid;
//////		}
//////
//////		if (right >= dp.size()) dp.push_back(v[i]);
//////		else dp[right] = v[i];
//////	}
//////
//////	cout << dp.size() << endl;
//////
//////	return 0;
//////}
////
////
////
////#include<iostream>
////#include<vector>
////#include<algorithm>
////
////using namespace std;
////
////////////////////////////////////////////////////////////
////int main()
////{
////	int n = 9;
////	//cin >> n;
////	//vector<int> v = { 1,1,3,3,15,16,27,28,29 };
////	vector<int> v;
////	/*for (int i = 0; i < n; ++i)
////	{
////		int t;
////		cin >> t;
////		v.push_back(t);
////	}*/
////	sort(v.begin(), v.end());
////
////	int res = 0;
////	int pos = 1;
////	for (int i = 0; i < n; ++i)
////	{
////		for (int j = i+1; j < n; ++j)
////		{
////			if (v[i] >= 0.9*v[j])
////			{
////				++res;
////			}
////			else
////			{ 
////				break;
////			}
////		}
////
////	}
////	cout << res << endl;
////
////	return 0;
////}
////////////////////////////////////////////////////////////
////
//////
//////
//////int main()
//////{
//////	int n = 14;
//////	vector<int> v = { 1,1,3,3,15,16,27,28,29 ,110,112,113,100001,100003 };
//////	//for (int i = 0; i < n; ++i)
//////	//{
//////	//	int t;
//////	//	cin >> t;
//////	//	v.push_back(t);
//////	//}
//////	sort(v.begin(), v.end());
//////
//////	int res = 0;
//////	for (int i = 0; i < n; ++i)
//////	{
//////		for (int j = i + 1; j < n; ++j)
//////		{
//////			if (v[i] >= 0.9*v[j])
//////			{
//////				++res;
//////			}
//////			else
//////			{
//////				cout << i << " " << j << endl;
//////				break;
//////			}
//////		}
//////
//////	}
//////	cout << res << endl;
//////
//////	return 0;
//////}
////
////
//////
//////
//////#include<iostream>
//////#include<vector>
//////#include<algorithm>
//////
//////using namespace std;
//////
//////int main()
//////{
//////	int n = 14;
//////	//cin >> n;
//////	vector<int> v = { 1,1,3,3,15,16,27,28,29 ,110,112,113,100001,100003};
//////	//for (int i = 0; i < n; ++i)
//////	//{
//////	//	int t;
//////	//	cin >> t;
//////	//	v.push_back(t);
//////	//}
//////	sort(v.begin(), v.end());
//////
//////	int res = 0;
//////
//////	for (int i = 0; i < n; ++i)
//////	{
//////		int left = i, right = n - 1;
//////		int pos = i;
//////		while (left < right)
//////		{
//////			int mid = left + (right - left) / 2;
//////			if (v[i] < 0.9*v[mid])
//////			{
//////				pos = mid;
//////				right = mid;
//////			}
//////			else {
//////				left = mid + 1;
//////			}
//////		}
//////
//////		cout << i << " " << pos << endl;
//////
//////		if (pos != i)
//////			res += (pos - i - 1);
//////		else {
//////			res += (n - i - 1);
//////		}
//////
//////	}
//////	cout << res << endl;
//////
//////	return 0;
//////}
//////
//////
//////
////
////
////
////
////
////
////#include<iostream>
////#include<vector>
////#include<algorithm>
////
////using namespace std;
////
////int main()
////{
////	int n = 14;
////	//cin >> n;
////	vector<int> v = { 1,1,3,3,15,16,27,28,29 ,110,112,113,100001,100003};
////	//for (int i = 0; i < n; ++i)
////	//{
////	//	int t;
////	//	cin >> t;
////	//	v.push_back(t);
////	//}
////	sort(v.begin(), v.end());
////
////	int res = 0;
////
////	for (int i = 0; i < n; ++i)
////	{
////		int left = i, right = n - 1;
////		int mid = left + (right - left) / 2;
////		/*int pos = i;
////		while (left < right)
////		{
////			int mid = left + (right - left) / 2;
////			if (v[i] < 0.9*v[mid])
////			{
////				pos = mid;
////				right = mid;
////			}
////			else {
////				left = mid + 1;
////			}
////		}
////
////		cout << i << " " << pos << endl;
////
////		if (pos != i)
////			res += (pos - i - 1);
////		else {
////			res += (n - i - 1);
////		}*/
////
////		while (v[mid] * 0.9 > v[i] && mid != right)
////		{
////			right = mid - 1;
////			mid = (mid + left) / 2;
////		}
////		while (v[mid] * 0.9 <= v[i])
////		{
////			if (mid <= left)
////			{
////				if (v[right] * 0.9 <= v[i])
////				{
////					mid = right;
////					break;
////				}
////			}
////
////			left = mid + 1;
////			mid = (mid + right) / 2;
////
////		}
////		res += (mid - i);
////
////	}
////	cout << res << endl;
////
////	return 0;
////}
////
//
//
//
//
//#include<iostream>
//#include<vector>
//#include<algorithm>
//
//using namespace std;
//
//
//int main()
//{
//	int n = 9;
//	//cin >> n;
//	vector<int> v = { 1,1,3,3,15,16,27,28,29 };
//	//vector<int> v;
//	//for (int i = 0; i < n; ++i)
//	//{
//	//	int t;
//	//	cin >> t;
//	//	v.push_back(t);
//	//}
//	sort(v.begin(), v.end());
//
//	int res = 0;
//	int pos = 0;
//	int cur = 0;
//	bool flag = false;
//	for (int i = 0; i < n; ++i)
//	{
//		int tmp = 0;
//		for (int j = pos; j < n; ++j)
//		{
//			if (v[i] >= 0.9*v[j])
//			{
//				++tmp;
//			}
//			else
//			{
//				flag = true;
//				pos = j;
//				break;
//			}
//		}
//
//		if (!flag) 
//		{
//			pos = i + 1;
//			res += tmp;
//		}
//		else
//		{
//			res += cur + tmp - 1;
//			if (tmp == 0) cur = 0;
//			else cur = tmp - 1;
//		}
//
//		flag = false;
//
//	}
//	cout << res << endl;
//
//	return 0;
//}



//#include<iostream>
//#include<vector>
//#include<algorithm>
//
//using namespace std;
//
//int Count(vector<int> &v) {
//	std::sort(v.begin(), v.end());
//	int sum = 0;
//	for (int i = 0; i < v.size(); i++) {
//		int num = floor(v[i] / 0.9);
//		sum += upper_bound(v.begin() + i, v.end(), num) - v.begin() - i - 1;
//	}
//	return sum;
//}