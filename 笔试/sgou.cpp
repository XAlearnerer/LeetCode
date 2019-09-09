//#include<iostream>
//#include<unordered_map>
//#include<list>
//#include<string>
//#include<algorithm>
//
//using namespace std;
//
//class LRU {
//public:
//	LRU(int capacity) {
//		cap = capacity;
//	}
//
//	void insert(string key, unsigned int value) {
//		auto it = m.find(key);
//		if (it != m.end())
//		{
//			if (it->second->second < value)
//			{
//				v.splice(v.begin(), v, it->second);
//				it->second->second = value;
//			}
//
//			return;
//		}
//
//		if (v.size() == cap)
//		{
//			auto it = m.find(v.back().first);
//			
//			cout << it->first << " " << it->second->second << endl;
//			
//			m.erase(it);
//			v.pop_back();
//		}
//		v.push_front({ key,value });
//		m.insert({ key,v.begin() });
//	}
//
//	int cap;
//	unordered_map<string, list<pair<string, unsigned int>>::iterator> m;
//	list<pair<string, unsigned int>> v;
//};
//
//
//int main()
//{
//	int n;
//	cin >> n;
//	LRU lru(n);
//	string s;
//	unsigned int a;
//	cin >> s >> a;
//	lru.insert(s, a);
//	while (cin >> s >> a)
//	{
//		lru.insert(s, a);
//	}
//	return 0;
//}
//
//
//
//
