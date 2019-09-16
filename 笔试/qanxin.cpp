////#include <iostream>
////#include <vector>
////#include <numeric>
////#include <limits>
////#include <algorithm>
////
////using namespace std;
////
////
/////*请完成下面这个函数，实现题目要求的功能
////当然，你也可以不按照下面这个模板来作答，完全按照自己的想法来 ^-^
////******************************开始写代码******************************/
////int smallestRange(vector<int> v, int k) {
////	sort(v.begin(), v.end());
////	int n = v.size();
////	int mx = v[n - 1], mn = v[0];
////	int res = mx - mn;
////
////	for (int i = 0; i<n - 1; ++i)
////	{
////		mx = max(mx, v[i] + 2 * k);
////		mn = min(v[i + 1], v[0] + 2 * k);
////		res = min(res, mx - mn);
////
////	}
////	return res;
////}
////
/////******************************结束写代码******************************/
////
////
////int main() {
////	int res;
////	int k;
////	cin >> k;
////	vector<int> v;
////	int t;
////	cin >> t;
////	v.push_back(t);
////	while (cin >> t)
////		v.push_back(t);
////
////
////	res = smallestRange(v, k);
////	cout << res << endl;
////
////	return 0;
////
////}
//
//
//
//#include <iostream>
//#include <vector>
//#include <numeric>
//#include <limits>
//#include <algorithm>
//
//using namespace std;
//
//
///*请完成下面这个函数，实现题目要求的功能
//当然，你也可以不按照下面这个模板来作答，完全按照自己的想法来 ^-^
//******************************开始写代码******************************/
//int smallestRange(vector<long long >& v, long long  k) {
//	sort(v.begin(), v.end());
//	int n = v.size();
//	long long mx = v[n - 1], mn = v[0];
//	long long  res = mx - mn;
//
//	for (int i = 0; i < n - 1; ++i)
//	{
//		mx = max(mx, v[i] + 2 * k);
//		mn = min(v[i + 1], v[0] + 2 * k);
//		res = min(res, mx - mn);
//
//	}
//	return res;
//}
//
///******************************结束写代码******************************/
//
//
//int main() {
//	int res;
//	int k;
//	cin >> k;
//	vector<long long > v;
//	int t;
//	cin >> t;
//	v.push_back(t);
//	while (cin >> t)
//		v.push_back(t);
//
//
//	res = smallestRange(v, k);
//	cout << res << endl;
//
//	return 0;
//
//}
