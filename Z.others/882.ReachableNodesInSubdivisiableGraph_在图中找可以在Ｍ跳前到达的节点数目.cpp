//
// Created by zhao on 19-5-22.
//
#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

class Solution {
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


int main()
{
    vector<vector<int>> edges ={{0,1,10},{0,2,1},{1,2,2}};
    int M=6, N=3;
    Solution n;
    cout<<n.reachableNodes(edges,M,N)<<endl;

    return 0;
}

