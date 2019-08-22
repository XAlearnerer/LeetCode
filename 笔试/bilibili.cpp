//#include<iostream>
//
//using namespace std;
//
//#include<iostream>
//#include<string>
//
//using namespace std;
//
//class Solution
//{
//public:
//	string reverseword(string& s)
//	{
//		if (s.empty()) return s;
//		int pos = 0;
//		rev(s, 0, s.size() - 1);
//		while (pos < s.size())
//		{
//			if (pos < s.size() && s[pos] == ' ') ++pos;
//			int left = pos, right = pos;
//			while (pos < s.size() && s[pos] != ' ')
//			{
//				++pos;
//				++right;
//			}
//			rev(s, left, right - 1);
//
//		}
//		return s;
//	}
//
//	void rev(string& s, int b, int e)
//	{
//		while (b < e)
//		{
//			swap(s[b], s[e]);
//			++b;
//			--e;
//		}
//	}
//};
//
//
//int main()
//{
//	string s;
//	getline(cin, s);
//
//	cout << s << endl;
//
//	Solution n;
//	cout << n.reverseword(t) << endl;
//
//
//	return 0;
//}
