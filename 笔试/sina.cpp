//#include<iostream>
//#include<vector>
//#include<algorithm>
//
//using namespace std;
//
//
////int main()
////{
////	/*4 5
////	77 65 67  87*/
////	int n, k;
////	//cin >> n >> k;
////	n = 4, k = 5;
////
////	vector<int> v = { 77, 65, 67, 87 };
////	//vector<int> v(n);
////	//for (int i = 0; i<n; ++i)
////	//	cin >> v[i];
////
////	sort(v.begin(), v.end());
////	int res = 0;
////
////	vector<int> f(n, 0);
////	for (int i = 0; i < n  - 1; ++i)
////	{
////		if (v[i] == 1) continue;
////		for (int j = i + 1; j < n; ++j)
////		{
////			if (v[j] == 1) continue;
////			if (v[j] - v[i] <= k)
////			{
////				f[i] = 1;
////				f[j] = 1;
////				++res;
////			}
////		}
////	}
////	//for (int i = 0; i < n - 1; ++i)
////	//{
////	//	auto it = lower_bound(v.begin(), v.end(), v[i] + k);
////	//	//cout << *it << endl;
////	//	//cout << " -- " << (it - v.begin()) - i + 1 << endl;
////	//	int cur = (it - v.begin()) - i - 1;
////	//	if (cur < 0) cur = 0;
////	//	res += cur;
////	//
////	//}
////
////
////	cout << res << endl;
////
////	return 0;
////}
//
//
//#include<iostream>
//#include<vector>
//#include<algorithm>
//#include<functional> 
//
//using namespace std;
//
//
//
//int main()
//{
//	int n, m, k;
//
//	n = 6, m = 2, k = 2;
//	vector<int> v = { 4, 1 ,2 ,3, 1, 2 };
//	//cin >> n >> m >> k;
//	//vector<int> v(n);
//	//for (int i = 0; i<n; ++i)
//	//	cin >> v[i];
//
//	int res = 0;
//	for (int i = 0; i < n; ++i)
//	{
//		vector<int> cur;
//		int l = i, r = i;
//		while (l > 0 && i - l < k) --l;
//		while (r < n - 1 && r - i < k) ++r;
//		for (int j = l; j <= r; ++j)
//		{
//			if (j == i) continue;
//			cur.push_back(v[j]);
//		}
//		sort(cur.begin(), cur.end(), greater<int>());
//		int cnt = 0;
//		for (int k = 0; k < m - 1; ++k)
//			cnt += cur[k];
//		cnt += v[i];
//		res = max(res, cnt);
//
//	}
//
//	cout << res << endl;
//	return 0;
//
//}
