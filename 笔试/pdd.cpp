//#include<iostream>
//#include<string>
//#include<vector>
//#include<set>
//
//using namespace std;
//
//void helper(string a, string& b, string cur, set<string>& res, string cl, int pos, int S)
//{
//	if (pos > S) return;
//	if (cur == b && pos == S)
//	{
//		res.insert(cl);
//		return;
//	}
//	
//	if (a.empty()) return;
//
//	char c = a[0];
//	string t = a.erase(0, 1);
//	helper(t, b, cur, res, cl + "d ", pos + 1, S);
//	helper(t, b, cur + c, res, cl + "r ", pos + 1, S);
//	helper(t, b, c + cur, res, cl + "l ", pos + 1, S);
//}
//
//
//int main()
//{
//	int S;
//	cin >> S;
//	for (int turn = 0; turn < S; ++turn)
//	{
//		string a, b;
//		cin >> a >> b;
//
//		set<string> res;
//		string cur = "";
//		helper(a, b, cur, res, "", 0, a.size());
//
//		cout << "{" << endl;
//		for (auto i : res)
//		{
//			cout << i << endl;
//		}
//		cout << "}" << endl;
//	}
//
//	//string a = "123";
//	//string b = "321";
//	//int S = 3;
//	//set<string> res;
//	//string cur = "";
//	//helper(a, b, cur, res, "", 0, a.size());
//	//
//	//cout << "{" << endl;
//	//for (auto i : res)
//	//{
//	//	cout << i << endl;
//	//}	
//	//cout << "}" << endl;
//
//	return 0;
//}
//
//

//
//
//
//#include<iostream>
//#include<vector>
//#include<queue>
//#include<functional>
//
//using namespace std;
//
//int main()
//{
//	int n, m, k;
//	cin >> n >> m >> k;
//	//vector<vector<int>> v(n + 1, vector<int>(m + 1, 0));
//	//for (int i = 0; i <= n; ++i)
//	//{
//	//	for (int j = 0; j <= m; ++j)
//	//		v[i][j] = i*j;
//	//}
//	vector<vector<int>> v(n, vector<int>(m, 0));
//	//vector<int> res;
//	priority_queue<int,vector<int>,greater<int>> q;
//	for (int i = 0; i < n; ++i)
//	{
//		for (int j = 0; j < m; ++j)
//		{
//			v[i][j] = (i + 1)*(j + 1);
//			if (q.size() <= k)
//				q.push(v[i][j]);
//			else
//			{
//				if (v[i][j] > q.top())
//				{
//					q.pop();
//					q.push(v[i][j]);
//				}
//			}
//		}
//	}
//
//	cout << q.top() << endl;
//	return 0;
//}


//#include<iostream>
//#include<vector>
//#include<functional>
//#include<algorithm>
//#include<queue>
//#include<set>
//using namespace std;
//
//long long helper(multiset<int> t)
//{
//	long long res;
//	for (auto i : t)
//	{
//		res *= i;
//	}
//	return res;
//}
//
//int main()
//{
//	int n;
//	cin >> n;
//	//vector<int> v(n);
//	//for (int i = 0; i < n; ++i)
//	//	cin >> v[i];
//	priority_queue<int> q;
//	multiset<int> t;
//	long long total = 1;
//	for (int i = 0; i < n; ++i)
//	{
//		int p;
//		cin >> p;
//		total *= p;
//		q.push(p);
//		t.insert(p);
//	}
//
//	long long res = 1;
//	while (q.empty())
//	{
//		int m = q.top();
//		q.pop();
//		t.erase(m);
//		res += m*helper(t);
//
//		if (m > 1)
//		{
//			q.push(m - 1);
//			t.insert(m - 1);
//		}
//	}
//	cout << res << " " << total << endl;
//	printf("%.2f\n", (float)res / total);
//
//	return 0;
//}
