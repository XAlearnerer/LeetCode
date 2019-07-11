#include<iostream>
#include<unordered_map>
#include<list>

using namespace std;



//  ["LRUCache", "put", "put", "get", "put", "put", "get"]
//  [[2], [2, 1], [2, 2], [2], [1, 1], [4, 1], [2]]
//  
//  [null, null, null, 2, null, null, -1]
//  				注意这里是 2 而 不是 1



class LRUCache {
public:
	LRUCache(int capacity) {
		cap = capacity;
	}

	int get(int key) {
		auto it = m.find(key);
		if (it != m.end())
		{
			//list<pair<int, int>>::iterator vt = find(v.begin(), v.end(), it->second);
			//swap(v.begin(), vt);
			v.splice(v.begin(), v, it->second);
			return it->second->second;
		}
		else return -1;
	}

	void put(int key, int value) {
		auto it = m.find(key);
		if (it != m.end())
		{
			//list<pair<int, int>>::iterator vt = find(v.begin(), v.end(), it->second);
			v.splice(v.begin(), v, it->second);
			it->second->second = value;
			return;
		}

		if (v.size() == cap)
		{
			auto it = m.find(v.back().first);
			m.erase(it);
			v.pop_back();
		}
		v.push_front({ key,value });
		m.insert({ key,v.begin() });
	}

	int cap;
	//unordered_map<int, pair<int, int>> m;
	unordered_map<int, list<pair<int, int>>::iterator> m;
	list<pair<int, int>> v;
};


/**
* Your LRUCache object will be instantiated and called as such:
* LRUCache* obj = new LRUCache(capacity);
* int param_1 = obj->get(key);
* obj->put(key,value);
*/

