#include<iostream>
#include<vector>
#include<queue>
#include<unordered_set>

using namespace std;

class Solution {
public:
	vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
		if (n == 1) return { 0 };
		vector<unordered_set<int>> graph(n);
		queue<int> q;
		for (auto a : edges)
		{
			graph[a.first].insert(a.second);
			graph[a.second].insert(a.first);
		}

		for (int i = 0; i != graph.size(); ++i)
		{
			if (graph[i].size() == 1)
				q.push(i);
		}

		while (n > 2)
		{
			int size = q.size();
			n -= size;
			//n -= q.size();
			//for (int i = 0; i != q.size(); ++i)
			for (int i = 0; i != size; ++i)

			{
				int t = q.front();
				q.pop();
				for (auto a : graph[t])
				{
					graph[a].erase(t);
					if (graph[a].size() == 1) q.push(a);
				}
			}
		}

		vector<int> res;
		//for (int i = 0; i != q.size(); ++i)
		while(!q.empty())
		{
			res.push_back(q.front());
			q.pop();
		}
		return res;
	}
};

