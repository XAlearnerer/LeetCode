//#include<iostream>
//#include<vector>
//#include<algorithm>
//#include<unordered_set>
//#include<queue>
//#include<set>
//
//using namespace std;
//
//
//bool equal(pair<int, int> a, pair<int, int> b)
//{
//	if (a.first == b.first && a.second == b.second)
//		return true;
//	else return false;
//}
//
//
//int main()
//{
//	int x, y, n;
//	cin >> x >> y >> n;
//	//unordered_set<pair<int, int>> block;
//	set<pair<int, int>> block;
//	int xl = 0, xr = 0, yl = 0, yr = 0;
//	for (int i = 0; i < n; ++i)
//	{
//		int a, b;
//		cin >> a >> b;
//		xl = min(xl, a);
//		xr = max(xr, a);
//		yl = min(yl, b);
//		yr = min(yr, b);
//		block.insert({ a,b });
//	}
//
//	int xleft = min(0, min(x, xl)) - 1;
//	int xright = max(0, max(x, xr)) + 1;
//	int yleft = min(min(0, y), yl) - 1;
//	int yright = max(max(0, y), yr) + 1;
//
//	queue<pair<int, int>> q;
//	//unordered_set<pair<int, int>> v;
//	set<pair<int, int>> v;
//
//	pair<int, int> end = { x,y };
//	q.push({ 0,0 });
//	int path = 0;
//	while (!q.empty()) {
//		int size = q.size();
//		while (size > 0) {
//			auto p = q.front();
//			q.pop();
//			if (equal(p, end)) {
//				cout << path << endl;
//				return 0;
//			}
//			size--;
//			int a = p.first, b = p.second;
//			pair<int, int> left = { a - 1,b };
//			if (block.find(left) != block.end() && v.find(left) != v.end()) {
//				q.push(left);
//			}
//			pair<int, int> right = { a + 1,b };
//			if (block.find(right) != block.end() && v.find(right) != v.end()) {
//				q.push(right);
//			}
//			pair<int, int> up = { a,b + 1 };
//			if (block.find(up) != block.end() && v.find(up) != v.end()) {
//				q.push(up);
//			}
//			pair<int, int> down = { a,b - 1 };
//			if (block.find(down) != block.end() && v.find(down) != v.end()) {
//				q.push(down);
//			}
//			v.insert(p);
//		}
//		path++;
//	}
//
//
//	return 0;
//}
