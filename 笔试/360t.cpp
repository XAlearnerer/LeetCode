/*

//cin>>l>>r;
scanf("%d %d", &l, &r);

//cout<<ant[l-1][r-1]<<endl;
printf("%d\n", ant[l - 1][r - 1]);

*/


//
//#include<iostream>
//#include<vector>
//using namespace std;
//
//int main()
//{
//	int n, m;
//	int res = 0;
//	scanf("%d %d", &n, &m);
//	vector<vector<int>> v(n, vector<int>(m));
//	for (int i = 0; i < n; ++i)
//	{
//		for (int j = 0; j < m; ++j)
//		{
//			scanf("%d", &v[i][j]);
//			if (v[i][j] != 0) ++res;
//		}
//	}
//	vector<vector<int>> change = { {0,1},{-1,0},{0,-1},{1,0} };
//	for (int i = 0; i < n; ++i)
//	{
//		for (int j = 0; j < m; ++j)
//		{
//			if (v[i][j] != 0)
//			{
//				++res;
//				for (int k = 0; k < 4; ++k)
//				{
//					int a = i + change[k][0];
//					int b = j + change[k][1];
//					if (a < 0 || a >= n || b < 0 || b >= m)
//						res += v[i][j];
//					else
//					{
//						if(v[a][b]<v[i][j])
//							res += (v[i][j] - v[a][b]);
//					}
//				
//				}
//			}
//		}
//	}
//
//
//	printf("%d\n", res);
//	return 0;
//}

//5 5
//4 4 1 1 1
//4 3 0 1 2
//样例输出
//4 4 3 3 2
//
//提示
//4 4 1 1 1 →1 4 1 4 1
//4 3 0 1 2 →3 0 2 4 1

//
//
//#include<iostream>
//#include<vector>
//#include<set>
//#include<algorithm>
//#include<functional>
//
//using namespace std;
//
//int main()
//{
//	int n, m;
//	//scanf("%d %d", &n, &m);
//	n = 5, m = 5;
//	//vector<int> v1(n), v2(n);
//	//multiset<int> t1, t2;
//
//	vector<int> t1, t2;
//	t1 = { 4, 4 ,1 ,1 ,1 };
//	t2 = { 4, 3 ,0, 1, 2 };
//
//	vector<int> v1(n, 0), v2(n, 0);
//
//	/*for (int i = 0; i < n; ++i)
//	{
//		int a;
//		scanf("%d", &a);
//		t1.insert(a);
//	}
//
//	for (int i = 0; i < n; ++i)
//	{
//		int a;
//		scanf("%d", &a);
//		t2.insert(a);
//	}*/
//
//	vector<int> res;
//
//	for (int i = 0; i < n; ++i)
//	{
//		int cur = 0;
//		pair<int, int> curp;
//		for (int j = 0; j < n; ++j)
//		{
//			if (v2[j] == 1) continue;
//
//			if ((t1[i] + t2[j]) % m > cur)
//			{
//				cur = (t1[i] + t2[j]) % m;
//				curp = { i,j };
//			}
//		}
//
//		res.push_back(cur);
//		v1[curp.first] = 1;
//		v2[curp.second] = 1;
//	}
//	//for (auto i : t1)
//	//{
//	//	int cur = 0;
//	//	pair<int, int> curp;
//	//	for (auto j : t2)
//	//	{
//	//		if ((i + j) % 5 > cur)
//	//		{
//	//			cur = (i + j) % 5;
//	//			curp = { i,j };
//	//		}
//	//	}
//
//	//	res.push_back(cur);
//	//	t1.erase(find(t1.begin(), t1.end(), curp.first));
//	//	t2.erase(find(t2.begin(), t2.end(), curp.second));
//	//}
//
//	sort(res.begin(), res.end(), greater<int>());
//	for (auto i : res)
//	{
//		cout << i << " ";
//	}
//	cout << endl;
//
//	//for (int i = 0; i < n; ++i)
//	//{
//	//	int tmp = *t1.begin();
//	//	int k = m - 1;
//	//	//while (k >= 0)
//	//	//{
//	//	//	/*if (t2.count(k - tmp) != 0)
//	//	//	{
//	//	//		t1.erase(tmp);
//	//	//		t2.erase(k - tmp);
//	//	//		res.push_back(k);
//	//	//		break;
//	//	//	}
//	//	//	--k;*/
//	//	//}
//
//	//	int cur = 0;
//	//	for (auto j : t2)
//	//	{
//	//		if(j+tmp)
//	//	}
//
//	//}
//
//
//	return 0;
//}

