//#include<iostream>
//#include<vector>
//
//using namespace std;
//
//
//
//
//int main()
//{
//	//vector<int> v1 = { 1,1,0,0 };
//	//vector<int> v2 = { 0,1,1,0 };
//
//	vector<int> v1 = { 1,1,1,1,0 };
//	vector<int> v2 = { 0,1,1,1,1 };
//
//
//	vector<int> cnt;
//	for (int i = 0; i < v1.size(); ++i)
//	{
//		if (v1[i] == 1 && v2[i] == 1)
//			cnt.push_back(3);
//		else if (v1[i] == 1) cnt.push_back(1);
//		else if (v2[i] == 1) cnt.push_back(2);
//		else cnt.push_back(0);
//	}
//
//	int res = 0;
//	int i = 0;
//	//for (int i = 0; i < cnt.size(); ++i)
//	while (i < cnt.size())
//	{
//		if (cnt[i] == 0)
//		{
//			++res;
//			++i;
//			continue;
//		}
//
//		else if (cnt[i] == 1)
//		{
//			if (i < cnt.size() - 1)
//			{
//				if (cnt[i + 1] == 1)
//				{
//					i += 2;
//					++res;
//				}
//				else if (cnt[i + 1] == 3)
//				{
//					cnt[i + 1] == 2;
//					++i;
//				}
//				else if (cnt[i + 1] == 2)
//				{
//					++i;
//				}
//				else 
//				{
//					++res;
//					i += 2;
//				}
//			}
//			else
//			{
//				++i;
//			}
//		}
//
//
//		else if (cnt[i] == 2)
//		{
//			if (i < cnt.size() - 1)
//			{
//				if (cnt[i + 1] == 2)
//				{
//					i += 2;
//					++res;
//				}
//				else if (cnt[i + 1] == 3)
//				{
//					cnt[i + 1] == 1;
//					++i;
//				}
//				else if (cnt[i + 1] == 1)
//				{
//					++i;
//				}
//				else
//				{
//					++res;
//					i += 2;
//				}
//			}
//			else
//			{
//				++i;
//			}
//		}
//
//		else
//		{
//			if (i < cnt.size() - 1)
//			{
//				if (cnt[i + 1] == 1 || cnt[i + 1] == 3|| cnt[i + 1] == 3)
//				{
//					++i;
//				}
//				else
//				{
//					++res;
//					i += 2;
//				}
//			}
//			else
//			{
//				++i;
//			}
//		}
//
//	}
//
//	cout << res << endl;
//
//	return 0;
//}
//
//
//
