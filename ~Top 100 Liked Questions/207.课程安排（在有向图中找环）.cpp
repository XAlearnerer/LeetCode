#include<iostream>
#include<vector>
#include<queue>

using namespace std;


/////////////// DFS /////////////////////

class Solution {
public:
	bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
		vector<vector<int>> g(numCourses, vector<int>(0));
		vector<int> vis(numCourses, 0);
		for (int i = 0; i < prerequisites.size(); ++i)
			g[prerequisites[i][1]].push_back(prerequisites[i][0]);

		for (int i = 0; i < numCourses; ++i)
		{
			if (!helper(g, vis, i)) return false;
		}
		return true;
	}

	bool helper(vector<vector<int>>& g, vector<int>& vis, int i)
	{
		if (vis[i] == -1) return false;
		if (vis[i] == 1) return true;

		vis[i] = -1;
		for (int j = 0; j != g[i].size(); ++j)
		{
			if (!helper(g, vis, g[i][j])) return false;
		}
		vis[i] = 1;

		return true;
	}
};


//////////////////////////////////////



//  1 -> 2 -> 3 -> 4 -> 2
//  初始找到结点1，NodeQueue = [1], 入度为[1:1, 2 : 2, 3 : 1, 4 : 1]
//  删除结点[1], 更新入度为[2:1, 3 : 1, 4 : 1]
//  由于环导致的额外的入度，导致没有入度为0的结点，使得BFS提前结束，没有能够遍历所有的节点


class Solution {
public:
	bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
		vector<vector<int>> g(numCourses, vector<int>(0));
		vector<int> in(numCourses, 0);
		for (int i = 0; i < prerequisites.size(); ++i)
		{
			g[prerequisites[i][1]].push_back(prerequisites[i][0]);
			++in[prerequisites[i][0]];
		}
		queue<int> q;
		for (int i = 0; i < in.size(); ++i)
		{
			if (in[i] == 0) q.push(i);
		}

		while (!q.empty())
		{
			int t = q.front();
			q.pop();
			for (auto i : g[t])
			{
				--in[i];
				if (in[i] == 0) q.push(i);
			}
		}

		for (auto i : in)
			if (i != 0) return false;
		return true;

	}
};

