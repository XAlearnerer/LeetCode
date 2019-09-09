#include<iostream>
#include<vector>

using namespace std;

//
//int main()
//{
//	int n = 7505;
//	vector<int> v;
//	while (n > 0)
//	{
//		v.push_back(n % 2);
//		n /= 2;
//	}
//	reverse(v.begin(), v.end());
//
//	for (auto i : v) cout << i << " ";
//	cout << endl;
//
//
//	int count = 0, first = -1;
//	for (int i = 0; i < v.size() - 2; ++i)
//	{
//		if (v[i] == 1 && v[i + 1] == 0 && v[i + 2] == 1)
//		{
//			if (first == -1) first = i;
//			++count;
//		}
//	}
//
//	cout << count << " --- " << first << endl;
//
//	return 0;
//}
//
//
