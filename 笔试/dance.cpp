//
#include<iostream>
#include<vector>

using namespace std;
//
//const int N = 110;
//int father[N];
//bool isRoot[N];
//
//int findFather(int x) {
//	if (x == father[x]) return x;
//	int fa = findFather(father[x]);
//	father[x] = fa;
//	return fa;
//}
//
//void Union(int x, int y) {
//
//	//cout << x << " " << y << endl;
//
//	int fax = findFather(x);
//	int fay = findFather(y);
//	if (fax != fay)
//		father[fax] = fay;
//}
//
//void init(int n) {
//	for (int i = 1; i <= n; i++) {
//		father[i] = i;
//		isRoot[i] = false;
//	}
//}
//
//int main(void) {
//	int n;
//	cin >> n;
//	init(n);
//	for (int i = 0; i < n; ++i)
//	{
//		for (int j = 0; j < n; ++j)
//		{
//			int t;
//			cin >> t;
//			if (j > i && t >= 3)
//			{
//				Union(i + 1, j + 1);
//			}
//		}
//	}
//
//	for (int i = 0; i < n; ++i) {
//		isRoot[findFather(i + 1)] = true;
//	}
//	int ans = 0;
//	for (int i = 0; i < n; ++i) {
//		ans += isRoot[i + 1];
//	}
//	printf("%d\n", ans);
//}
//





//
//
//int f(int n) {
//	int md = 1e9;
//	md += 7;
//
//	///////////  %1e9+7
//
//	vector<long long> v(1001, 0);
//	v[1] = 1;
//	v[2] = 2;
//	v[3] = 5;
//	if (n <= 3)
//		return v[n];
//	for (int i = 4; i <= n; ++i) {
//		v[i] = 2 * v[i - 1] + v[i - 3];
//		v[i] %= md;
//	}
//	return v[n];
//
//}
//
//int main()
//{
//	int n;
//	cin >> n;
//
//	cout << f(n / 2) << endl;
//
//	return 0;
//}


