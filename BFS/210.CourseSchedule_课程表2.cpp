#include<iostream>
#include<vector>
#include<queue>

using namespace std;

class Solution {
public:
	vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
		vector<vector<int> >graph(numCourses, vector<int>(0));
		vector<int> in(numCourses, 0);
		queue<int> q;
		vector<int> order;
		for (auto a : prerequisites)
		{
			graph[a.second].push_back(a.first);
			in[a.first]++;
		}
		for (int i = 0; i != in.size(); ++i)
		{
			if (in[i] == 0)
				q.push(i);
		}
		while (!q.empty())
		{
			int t = q.front();
			q.pop();
			order.push_back(t);
			for (auto a : graph[t])
			{
				--in[a];
				if (in[a] == 0)
					q.push(a);
			}
		}

		for (int i = 0; i != in.size(); ++i)
		{
			if (in[i] > 0)
				return vector<int>(0);
		}
		
		return order;
	}
};

