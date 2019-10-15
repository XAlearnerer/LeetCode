////#include<iostream>
////#include<vector>
////#include<string>
////
////using namespace std;
////
////
////int main()
////{
////	int t;
////	//cin >> t;
////	t = 1;
////	for (int i = 0; i < t; ++i)
////	{
////		int len;
////		string s;
////		//cin >> len >> s;
////		s = "111888888888";
////		len = s.size();
////		cout << len << endl;
////		if (len < 11)
////		{
////			cout << "NO" << endl;
////			continue;
////		}
////		if (s[0] == '8')
////		{
////			cout << "YES" << endl;
////			continue;
////		}
////		while (s.size() >= 11)
////		{
////			if (s[0] == '8')
////			{
////				cout << "YES" << endl;
////				break;
////			}
////			else
////			{
////				s.erase(0, 1);
////			}
////		}
////		cout << "NO" << endl;
////
////	}
////
////
////	return 0;
////}
////
//
////#include<iostream>
////#include<vector>
////#include<algorithm>
////
////using namespace std;
////
////int main()
////{
////	int T;
////	cin >> T;
////	for (int i = 0; i < T; ++i)
////	{
////		int n;
////		cin >> n;
////		vector<int> v(n);
////		for (int k = 0; k < n; ++k)
////		{
////			cin >> v[k];
////		}
////		int sum = 0;
////		for (int i = 0; i < n; ++i) {
////			sum += v[i];
////		}
////
////
////		vector<vector<int>> dp;
////		for (int i = 0; i <= n; i++) {
////			vector<int>tmp;
////			for (int j = 0; j <= sum / 2; ++j) {
////				tmp.push_back(0);
////			}
////			dp.push_back(tmp);
////		}
////
////		for (int i = 1; i <= n; ++i) {
////			for (int j = 1; j <= sum / 2; ++j) {
////				if (j >= v[i - 1])dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - v[i - 1]] + v[i - 1]);
////				else dp[i][j] = dp[i - 1][j];
////			}
////		}
////
////		cout << dp[n][sum / 2] << " " << dp[n][sum / 2] + 1 << endl;
////	}
////
////	return 0;
////}
////
////
//
//
////
////#include<iostream>
////#include<vector>
////#include<queue>
////#include<functional>
////
////using namespace std;
////
////int main()
////{
////	int n, k;
////	cin >> n >> k;
////	//vector<int> v(n);
////	priority_queue<long long, vector<long long>, greater<long long>> p;
////	for (int i = 0; i < n; ++i)
////	{
////		long long t; cin >> t;
////		p.push(t);
////	}
////	for (int ki = 0; ki < k; ++ki)
////	{
////		if (p.empty())
////		{
////			cout << 0 << endl;
////		}
////		else
////		{
////			cout << p.top() << endl;
////			long long cur = p.top();
////			priority_queue<long long, vector<long long>, greater<long long>> p2;
////			while (!p.empty())
////			{
////				long long t = p.top() - cur;
////				p.pop();
////				if (t != 0)
////					p2.push(t);
////			}
////			p = p2;
////		}
////	}
////
////
////	return 0;
////}
//
//
//
//#include<iostream>
//#include<vector>
//
//using namespace std;
//
//#include<iostream>
//#include<vector>
//
//using namespace std;
//
//int main()
//{
//	int n;
//	vector<int> a(n), b(n);
//	for (int i = 0; i<n; ++i)
//		cin >> a[i];
//	for (int j = 0; j<n; ++j)
//		cin >> b[j];
//
//	int res = a[0] + b[0];
//	for (int i = 0; i<n; ++i)
//	{
//		for (int j = 0; j<n; ++j)
//		{
//			if (i == 0 && j == 0) continue;
//			res ^= (a[i] + b[j]);
//		}
//
//	}
//
//	cout << res << endl;
//	return 0;
//}
//
//
//
//
//
