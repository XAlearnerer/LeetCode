//#include<iostream>
//#include<vector>
//
//using namespace std;
//
//
//#include<iostream>
//#include<vector>
//#include<algorithm>
//
//using namespace std;
//
////int main()
////{
////	int n, s;
////	//cin >> n >> s;
////	//cin>>l>>r;
////	//scanf("%d %d", &l, &r);
////
////	//cout<<ant[l-1][r-1]<<endl;
////
////	n = 5, s = 10;
////	//vector<int> v = { 3, 9, 5, 7, 6 };
////	vector<int> v;
////	for (int i = 0; i<n; ++i)
////	{
////		cin >> v[i];
////	}
////	sort(v.begin(), v.end());
////	vector<int> t(n);
////	t[0] = v[0];
////	for (int i = 1; i < n; ++i)
////		t[i] = t[i - 1] + v[i];
////
////	for (auto i : t)
////		cout << i << " ";
////	cout << endl;
////
////
////	/*int l = 0, r = n - 1;
////	int m = 0;
////	while (l < r)
////	{
////		m = l + (r - l) / 2;
////		if (t[m] < s) l = m + 1;
////		else r = m;
////	}*/
////
////	auto r = lower_bound(t.begin(), t.end(), s);
////	//cout << r-t.begin() << endl;
////	printf("%d\n", r - t.begin());
////	return 0;
////}
//
//
////int main()
////{
////	//int n, s;
////	long long n, s;
////	//cin >> n >> s;
////
////	scanf("%d %d", &n, &s);
////	vector<long long> v(n);
////	for (int i = 0; i<n; ++i)
////	{
////		cin >> v[i];
////		//scanf("%d", &v[i]);
////	}
////	sort(v.begin(), v.end());
////	vector<long long> t(n);
////	t[0] = v[0];
////	for (int i = 1; i<n; ++i)
////		t[i] = t[i - 1] + v[i];
////
////	auto r = lower_bound(t.begin(), t.end(), s);
////	//cout << r-t.begin() << endl;
////	printf("%d\n", r - t.begin());
////	return 0;
////}
//
//
//#include<iostream>
//#include<string>
//
//using namespace std;
////
////bool isallsame(string s)
////{
////	char c = s[0];
////	for (int i = 1; i < s.size(); ++i)
////		if (c != s[i])
////			return false;
////	return true;
////}
////
////int hw(string s)
////{
////	int l = 0, r = s.size() - 1;
////	int k = 0;
////	char c = s[0];
////	while (l < r && s[l] == s[r] && s[l] == c)
////	{
////		++k;
////		++l;
////		--r;
////	}
////	return k;
////}
////
////int main()
////{
////	//int n, k;
////	//cin >> n >> k;
////	//string s;
////	//cin >> s;
////
////	int n = 3;
////	int	k = 2;
////	string s = "aba";
////
////	if (isallsame(s))
////	{
////		char c = s[0];
////		for (int i = 1; i < k; ++i)
////		{
////			s += c;
////		}
////		cout << s << endl;
////	}
////	else
////	{
////		int h = hw(s);
////		string t = s.substr(h);
////		for (int i = 1; i < k; ++i)
////		{
////			s += t;
////		}
////		cout << s << endl;
////	}
////
////
////	return 0;
////}
//
//
//
//string f(int n, int k, string s)
//{
//	vector<int> next(n);
//	int j = 0;
//	for (int i = 1; i < n; ++i)
//	{
//		if (s[i] == s[j])
//		{
//			++j;
//			next[i] = j - 1;
//		}
//		else
//		{
//			next[i] = j;
//			j = 0;
//		}
//	}
//
//	if (next[n - 1] == 0 && s[0] != s[n - 1] || s[next[n-1]]!=s[n-1] )
//	{
//		/*string res = s;
//		for (int i = 1; i < k; ++i) res += s;
//		return res;*/
//		string res = s;
//		if (next[n - 1] == 0 && s[0] != s[n - 1])
//		{
//			for (int i = 1; i < k; ++i) res += s;
//		}
//		else
//		{
//			for (int i = 1; i < k; ++i) res += s.substr(1);
//		}
//		return res;
//
//	}
//	else
//	{
//		string res = s.substr(0, next[n - 1] + 1);
//		for (int i = 0; i < k; ++i)
//			res += s.substr(next[n - 1] + 1);
//		return res;
//	}
//}
//
//
//int main()
//{
//	int n = 1;
//	int	k = 2;
//	string s = "aba";
//	cout << f(s.size(), k, s) << endl;
//	
//	//int n, k;
//	//cin >> n >> k;
//	//string s;
//	//cin >> s;
//	//cout << f(n, k, s) << endl;
//
//	return 0;
//}
