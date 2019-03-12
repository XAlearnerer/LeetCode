#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Solution2 {
public:
	bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
		vector<vector<int> > graph(numCourses, vector<int>(0));
		vector<int> in(numCourses, 0);
		for (int i=0;i!=prerequisites.size();++i)
		{
			graph[prerequisites[i].second].push_back(prerequisites[i].first);
			in[prerequisites[i].first]++;
		}
		queue<int> q;
		for (int i = 0; i != in.size(); ++i)
		{
			if (in[i] == 0) q.push(i);
		}
		while (!q.empty())
		{
			int n = q.front();
			q.pop();
			for (auto a : graph[n])
			{
				--in[a];
				if (in[a] == 0) q.push(a);
			}
		}
		for (int i = 0; i != numCourses; ++i)
		{
			if (in[i] != 0) return false;
		}
		return true;
	}
};


//================= DFS ========================


class Solution {
public:
	bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
		vector<vector<int> > graph(numCourses, vector<int>(0));
		vector<int> visit(numCourses, 0);
		for (int i = 0; i != prerequisites.size(); ++i)
		{
			graph[prerequisites[i].second].push_back(prerequisites[i].first);
		}
		for (int i = 0; i < numCourses; ++i)
		{
			//if (!dfs(graph, visit, i))
			if (!canFinishDFS(graph, visit, i))
				return false;
		}
		return true;
	}

	//? visit[i] 0未访问，-1正在访问，1访问过了。
	//? 在一个点开始dfs时如果有 -1 则说明有环。
	//? 如果在dfs时遇到 1，则停止dfs即可。

	bool dfs(vector<vector<int> >& graph, vector<int>& visit,int i)
	{
		if (visit[i] == -1) return false;
		if (visit[i] == 1) return true;
		visit[i] = -1;
		for (int j = 0; j != graph[i].size(); ++j)
		{
			if (!dfs(graph, visit, j))
				return false;
		}
		visit[i] = 1;
		return true;
	}
	bool canFinishDFS(vector<vector<int> > &graph, vector<int> &visit, int i) {
		if (visit[i] == -1) return false;
		if (visit[i] == 1) return true;
		visit[i] = -1;
		//for (auto a : graph[i]) {
		//	if (!canFinishDFS(graph, visit, a)) return false;
		//}
	//? ???
		//for (int j = 0; j < graph[i].size(); ++j)
		for (auto j : graph[i])
		{
			if (!canFinishDFS(graph, visit, j)) return false;
		}
		visit[i] = 1;
		return true;
	}
};

class Solution {
public:
	bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
		vector<vector<int> > graph(numCourses, vector<int>(0));
		vector<int> visit(numCourses, 0);
		for (int i = 0; i != prerequisites.size(); ++i)
		{
			graph[prerequisites[i].second].push_back(prerequisites[i].first);
		}
		for (int i = 0; i < numCourses; ++i) {
			if (!canFinishDFS(graph, visit, i)) return false;
		}
		return true;
	}
	bool canFinishDFS(vector<vector<int> > &graph, vector<int> &visit, int i) {
		if (visit[i] == -1) return false;
		if (visit[i] == 1) return true;
		visit[i] = -1;
		for (auto a : graph[i]) {
			if (!canFinishDFS(graph, visit, a)) return false;
		}
		visit[i] = 1;
		return true;
	}
};