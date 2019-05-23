//
// Created by zhao on 19-5-22.
//
#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;


/////　 Dijkstra + Priority Queue　/////


class Solution_Lee215 {
public:
    int reachableNodes(vector<vector<int>> edges, int M, int N) {
        unordered_map<int, unordered_map<int, int>> e;
        for (auto v : edges) e[v[0]][v[1]] = e[v[1]][v[0]] = v[2];
        priority_queue<pair<int, int>> pq;
        pq.push({M, 0});
        unordered_map<int, int> seen;
        while (pq.size()) {
            int moves = pq.top().first, i = pq.top().second;
            pq.pop();
            if (!seen.count(i)) {
                seen[i] = moves;
                for (auto j : e[i]) {
                    int moves2 = moves - j.second - 1;
                    if (!seen.count(j.first) && moves2 >= 0)
                        pq.push({ moves2, j.first});
                }
            }
        }
        int res = seen.size();
        for (auto v : edges) {
            int a = seen.find(v[0]) == seen.end() ? 0 : seen[v[0]];
            int b = seen.find(v[1]) == seen.end() ? 0 : seen[v[1]];
            res += min(a + b, v[2]);
        }
        return res;
    }
};



class Solution {
public:
    struct node
    {
        int src;
        int move;
        node(int s,int m):src(s),move(m){}
    };

    struct MyCmp {
    public:
        bool operator() (const node& l, const node& r) {
            return l.move > r.move;
        }
    };

    int reachableNodes(vector<vector<int>>& edges, int M, int N) {
        unordered_map<int,unordered_map<int,int>> graph;
        unordered_map<int,int> visited;

//        auto cmp=[](node a,node b){ return a.move>b.move;};
//        priority_queue<node,vector<node>,decltype(cmp)> q;
        priority_queue<node,vector<node>,MyCmp> q;

        for(auto i:edges)
        {
            graph[i[0]][i[1]]=i[2];
            graph[i[1]][i[0]]=i[2];
        }

        int res=0;
        node n(0,0);
        q.push(n);

        while(!q.empty())
        {
            node cur=q.top();
            q.pop();
            int src=cur.src;
            int move=cur.move;
            if(move>M) break;

            if(visited[src]) continue;
            visited[src]=1;
            ++res;

            for(auto &it:graph[src])
            {
                int dst=it.first;
                int weight=it.second;

                if(visited[dst]) {
                    res += min(M - move, graph[src][dst]);
                }
                else
                {
                    int nextweight=move+weight+1;
                    if(nextweight>M)
                    {
                        res+=M-move;
                        //graph[dst][src]-=weight-M;
                        graph[dst][src] -= M-move;
                    }
                    else
                    {
                        //graph[src][dst]=0;
                        graph[dst][src]=0;
                        res+=weight;
                        node nextnode(dst,nextweight);
                        q.push(nextnode);
                    }
                }
            }
        }


        return res;
    }
};


//
//int main()
//{
//    vector<vector<int>> edges = {{0,2,3},{0,4,4},{2,3,8},{1,3,5},{0,3,9},{3,4,6},{0,1,5},{2,4,6},{1,2,3},{1,4,1}};
//    int M=8, N=5;
//    Solution n;
//    cout<<n.reachableNodes(edges,M,N)<<endl;
//
//    return 0;
//}
//
