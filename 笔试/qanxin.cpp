////#include <iostream>
////#include <vector>
////#include <numeric>
////#include <limits>
////#include <algorithm>
////
////using namespace std;
////
////
/////*������������������ʵ����ĿҪ��Ĺ���
////��Ȼ����Ҳ���Բ������������ģ����������ȫ�����Լ����뷨�� ^-^
////******************************��ʼд����******************************/
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
/////******************************����д����******************************/
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
///*������������������ʵ����ĿҪ��Ĺ���
//��Ȼ����Ҳ���Բ������������ģ����������ȫ�����Լ����뷨�� ^-^
//******************************��ʼд����******************************/
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
///******************************����д����******************************/
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
