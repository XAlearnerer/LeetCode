#include<iostream>
#include<algorithm>
#include<string>

using namespace std;

//
//
//bool helper(string& src, string& dst)
//{
//	string t = src;
//	for (int i = 0; i < src.size(); ++i)
//	{
//		char f = t[0];
//		t += f;
//		//t = t.substr(1);
//		t.erase(t.begin());
//
//		if (t.find(dst) != string::npos) return true;
//
//		/////////////////////////////////////////////////
//		if (t.find(src) != string::npos) return false;
//		/////////////////////////////////////////////////
//
//	}
//	return src == t ? true : false;
//}
//
//string s1, s2;
//int main()
//{
//	//string s1, s2;
//	//while (cin >> s1 >> s2)
//	//for (int i = 0; i < 3; ++i)
//	cin >> s1 >> s2;
//	{
//		if (s1.empty()) return false;
//		if (s2.empty()) return true;
//	
//		if (helper(s1, s2)) cout << 1;
//		else cout << 0;
//	}
//	return 0;
//}




//
//int main()
//{
//	double D;
//	cin >> D;
//	int middle = 0;
//	int res_M = 0;
//	int res_N = 0;
//	double precision = 0;
//	double min_precision = D;
//
//	for (int i = 1; i <= 10000; i++)
//	{
//		middle = (int)((double)i*D);
//		precision = abs(D - (double)middle / (double)i);
//
//		if (precision > abs(D - (double)(int)((double)i*D + 1) / (double)i))
//		{
//			precision = abs(D - (double)(int)((double)i*D + 1) / (double)i);
//			middle = middle + 1;
//		}
//		if (min_precision > precision)
//		{
//			min_precision = precision;
//			res_M = middle;
//			res_N = i;
//		}
//	}
//	cout << res_M << " " << res_N << endl;
//
//	return 0;
//}
//



