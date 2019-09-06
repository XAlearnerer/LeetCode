//#include <iostream>
//#include <vector>
//#include <algorithm> 
//
//using namespace std;
//
//
//
//int w, h;
//class Getmid
//{
//public:
//	void helper(vector<vector<int>> &v,int i,int j)
//	{
//		vector<int> t;
//		pair<int, int> l = { 0,0 }, r = { 0,0 };
//		if (i >= 2) l.first = i - 2;
//		else l.first = 0;
//		if (j >= 2) l.second = i - 2;
//		else l.second = 0;
//
//		if (i + 2 < v.size()) r.first = i + 2;
//		else r.first = v.size() - 1;
//		if (j + 2 < v[0].size()) r.second = j + 2;
//		else r.second = v[0].size() - 1;
//
//		for (int x = l.first; x <= r.first; ++x)
//		{
//			for (int y = l.second; y <= r.second; ++y)
//			{
//				t.push_back(v[x][y]);
//			}
//		}
//
//		sort(t.begin(), t.end());
//		if (t.size() % 2 == 0)
//			v[i][j] = (t[t.size() / 2] + t[t.size() / 2 - 1]);
//		else v[i][j] = t[t.size() / 2];
//
//	}
//	void mid(vector<vector<int>> &v)
//	{
//		for (int i = 0; i < w; ++i)
//		{
//			for (int j = 0; j < h; ++j)
//				helper(v, i, j);
//		}
//	}
//};
//
//int main()
//{
//	vector<vector<int>> picture;
//	Getmid t;
//	t.mid(picture);
//
//	return 0;
//}
//
//
//
