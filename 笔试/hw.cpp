//#include<iostream>
//#include<string>
//#include<algorithm>
//#include<vector>
//using namespace std;
//////
////
////void getbinary(int n, string& bin)
////{
////	while (n != 0)
////	{
////		bin += (n % 2) + '0';
////		n /= 2;
////	}
////}
////
////void helper(string& strBase, string strSrc,int& res,int& fir)
////{
////	string::size_type pos = 0;
////	string::size_type srclen = strSrc.size();
////	pos = strBase.find(strSrc, pos);
////	while (pos != string::npos)
////	{
////		++res;
////		if (res == 1) fir = pos;
////		pos = strBase.find(strSrc, pos + 2);
////	}
////
////}
////
////int main()
////{
////	int n;
////	cin >> n;
////	string bin;
////	getbinary(n, bin);
////	//cout << bin << endl;
////	int res = 0;
////	int fir = -1;
////	helper(bin, "101", res, fir);
////	if (res == 0)
////		cout << 0 << " " << -1 << endl;
////	else 
////		cout << res << " " << fir << endl;
////
////	return 0;
////}
//
//
////#include<iostream>
////#include<string>
////#include<vector>
////
////using namespace std;
////
////void helper(string& s, int& pos, int& cnt, vector<string>& v)
////{
////	string cur;
////	//while(s[pos]>='a' && s[pos]<=='z')
////
////	if (s[pos] == ',')
////	{
////		v.push_back("--");
////		++cnt;
////		++pos;
////		helper(s, pos, cnt, v);
////		return;
////	}
////
////	while (s[pos] != ',')
////	{
////		if (s[pos] == '"')
////		{
////			if (pos + 1<s.size() && s[pos + 1] == '"')
////			{
////				cur += '"';
////			}
////			else break;
////		}
////
////		cur += s[pos];
////		++pos;
////	}
////	v.push_back(cur);
////	++cnt;
////
////	if (s[pos] == ',')
////	{
////		++pos;
////		helper(s, pos, cnt, v);
////	}
////
////	if (s[pos] == '"')
////	{
////
////
////	}
////
////}
////
////
////int main()
////{
////	string s;
////	cin >> s;
////	cout << "ERROR" << endl;
////
////	return 0;
////}
////
////
////#include<iostream>
////#include<string>
////#include<vector>
////
////using namespace std;
////
////void helper(string& s, int& pos, int& cnt, vector<string>& v)
////{
////	string cur;
////	//while(s[pos]>='a' && s[pos]<=='z')
////
////	if (s[pos] == ',')
////	{
////		v.push_back("--");
////		++cnt;
////		++pos;
////		helper(s, pos, cnt, v);
////		return;
////	}
////
////	while (s[pos] != ',')
////	{
////		if (s[pos] == '"')
////		{
////			if (pos<s.size() - 1 && s[pos + 1] == '"')
////			{
////				cur += '"';
////				pos += 2;
////				continue;
////			}
////			else
////			{
////				break;
////			}
////		}
////
////		cur += s[pos];
////		++pos;
////	}
////	if (s[pos] != '"')
////	{
////		v.push_back(cur);
////		++cnt;
////	}
////	else
////	{
////		++cnt;
////		while (s[pos] != ',')
////		{
////			if (s[pos] == '"')
////			{
////				if (pos<s.size() - 1 && s[pos + 1] == '"')
////				{
////					cur += '"';
////					pos += 2;
////					continue;
////				}
////				else
////				{
////					break;
////				}
////			}
////
////			cur += s[pos];
////			++pos;
////		}
////	}
////
////	if (s[pos] == ',')
////	{
////		++pos;
////		helper(s, pos, cnt, v);
////	}
////
////
////
////}
//
//
////a,,1,"b,""
//
//
//void helper(string& s, int& pos, vector<string>& res)
//{
//	if (s[pos] == ',')
//	{
//		++pos;
//		res.push_back("--");
//		helper(s, pos, res);
//		return;
//	}
//
//	if (s[pos] == '"')
//	{
//		string cur;
//		++pos;
//		while (s[pos] != ',')
//		{
//			cur += s[pos];
//			if (s[pos] == '"')
//			{
//				if (pos<s.size() - 1 && s[pos + 1] == '"')
//				{
//					cur += '"';
//					pos += 2;
//					continue;
//				}
//				else
//				{
//					break;
//				}
//			}
//		}
//	}
//
//	while (s[pos] != ',')
//	{
//
//	}
//
//
//}
//
//int main()
//{
//	string s;
//	cin >> s;
//	//cout << "ERROR" << endl;
//
//	
//	return 0;
//}
//
//
//
//
