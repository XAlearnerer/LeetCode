//
// Created by Administrator on 2019/4/14.
//
#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include<bitset>
#include <unordered_map>

using namespace std;

class Solution1025_1 {
public:
    bool divisorGame(int N) {
        return N%2==0;
    }
};

class Solution1025_2 {
public:
    bool divisorGame(int N) {
        vector<bool> dp(N+1);
        dp[0]=false,dp[1]=false;
        if (N == 1)
            return false;
        for(int i = 2; i<=N; ++i)
        {
            dp[i]=false;
            for (int j = i - 1; j >= 1; j--) {
                if (dp[i - j] == false && i % j == 0)
                    dp[i] = true;
            }
        }
        return dp[N];
    }

};


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution1026 {
public:
    int maxAncestorDiff(TreeNode* root) {
        if(!root)
            return 0;
        vector<int> v;
        dfs(root,v);
        int m=0;
        for(auto a:v)
        {
            m=max(a,m);
        }
        return m;
    }
    //max,min
    pair<int,int> dfs(TreeNode*root,vector<int>& v)
    {
        if (!root->left && !root->right)
        {
            return {root->val,root->val};
        }
        else if(!root->left && root->right)
        {
            pair<int,int> p=dfs(root->right,v);
            v.push_back(minu(p.first,root->val));
            v.push_back(minu(p.second,root->val));
            return  {max(p.first,root->val),min(p.second,root->val)};
        }
        else if(!root->right && root->left)
        {
            pair<int,int> p=dfs(root->left,v);
            v.push_back(minu(p.first,root->val));
            v.push_back(minu(p.second,root->val));
            return  {max(p.first,root->val),min(p.second,root->val)};
        }
        else
        {
            pair<int,int> p1 =dfs(root->left,v);
            pair<int,int> p2 =dfs(root->right,v);
            int x=max(p1.first,p2.first);
            int n=min(p1.second,p2.second);
            v.push_back(minu(x,root->val));
            v.push_back(minu(n,root->val));
            return {max(x,root->val),min(n,root->val)};
        }
    }

    int minu(int a,int b)
    {
        if(a>b) return a-b;
        else
            return b-a;
    }
};



class Solution1027 {
public:
    int longestArithSeqLength(vector<int>& A) {
        vector<unordered_map<int, int>> vmap(A.size());
        int ans = 0;
        for (int i = 0; i < A.size(); i++) {
            for (int j = i+1; j < A.size(); j++) {
                int d = A[i] - A[j];
                vmap[j][d] = vmap[i][d]+1;
                ans = max(ans, vmap[j][d]);
            }
        }
        return ans + 1;
    }
};


