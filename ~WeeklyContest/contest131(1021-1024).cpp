//
// Created by zhao on 19-4-7.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include<bitset>
using namespace std;

//5016. Remove Outermost Parentheses

class Solution1021 {
public:
    string removeOuterParentheses(string S) {
        stack<char> t;
        if(S.empty()) return "";
        string res,cur;
        for(int i=0;i!=S.size();++i)
        {
            if(S[i]=='(')
            {
                t.push(S[i]);
                if(t.size()>1)
                {
                    cur+='(';
                }
            }
            else
            {
                if(t.size()==1)
                {
                    res+=cur;
                    cur="";
                }
                else
                {
                    cur+=')';
                }
                t.pop();
            }
        }
        return  res;
    }
};




struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

//class Solution {
//public:
//    int sumRootToLeaf(TreeNode* root) {
//        if(!root) return 0;
//        string cur="";
//        vector<string> v;
//        helper(root,cur,v);
//
//        int res=0;
//        for(auto a:v)
//            res+=bitset<8>(a).to_ulong();
//        return res;
//    }
//
//    void helper(TreeNode* root,string& cur,vector<string>& v)
//    {
//        if(!root) return ;
//        cur+=to_string(root->val);
//        if(!root->right && !root->left)
//        {
//            v.push_back(cur);
//        }
//
//        if(root->right)
//        {
//            int len=cur.size();
//            helper(root->right, cur,v);
//            cur.erase(len);
//        }
//
//        if(root->left)
//        {
//            int len=cur.size();
//            helper(root->left, cur,v);
//            cur.erase(len);
//        }
//    }
//};

class Solution1022 {
public:
    int res;
    int sumRootToLeaf(TreeNode* root) {
        res=0;
        if(!root) return 0;
        helper(root,0);
        return res;
    }

    void helper(TreeNode* root,int sum)
    {
        sum=sum*2+root->val;
        if(!root->left && !root->right) res+=sum;
        if(root->right) helper(root->right,sum);
        if(root->left) helper(root->left,sum);
    }
};



class Solution1023 {
public:
    vector<bool> camelMatch(vector<string>& queries, string pattern) {
        vector<bool> v;
        for(auto a:queries)
            v.push_back(check(a,pattern));
        return v;
    }

    bool check(string s,string pattern)
    {
        int i=0;
        for(char c:s)
        {
            if(c<='Z')
            {
                if(i<=pattern.length()) {
                    if (c == pattern[i])
                        ++i;
                    else
                        return false;
                }
                else
                    return false;
            }

            else
            {
                if(c==pattern[i])
                    ++i;
            }
        }
        if(i!=pattern.length())
            return false;

        return true;
    }
};


class Solution1024 {
public:
    int videoStitching(vector<vector<int>>& clips, int T) {
        //vector<vector<int>> res;
        int res=0;
        int level=0;
        sort(clips.begin(),clips.end(),[](vector<int>a,vector<int>b){ return a[0]<b[0];});
        int cur=0;
        int lolen=0;
        while(cur<clips.size())
        {
            if(clips[cur][0]==0)
            {
                if(clips[cur][1]>lolen)
                    lolen=clips[cur][1];
                ++cur;
            }
            else
                break;
        }

        //res.push_back({0,lolen});
        res=lolen;
        ++level;
        if(lolen>=T) return level;

        vector<vector<int>> v2;
        while(cur<clips.size())
        {
            if(clips[cur][0] <= /*res.back()[1]*/ res)
            {
                v2.push_back(clips[cur]);
            }

            else
            {
                if(v2.empty())
                {
                    if(res>=T)
                        return level;
                    else
                        return -1;
                }

                sort(v2.begin(),v2.end(),[](vector<int>a,vector<int>b){ return a[1]<b[1];});
                ++level;
                if(v2.back()[1]>=T)
                    return level;
                //res.push_back({v2.back()[0],v2.back()[1]});
                res=v2.back()[1];
                v2.clear();
            }
            ++cur;
        }

        if(!v2.empty())
        {
            sort(v2.begin(),v2.end(),[](vector<int>a,vector<int>b){ return a[1]<b[1];});
            ++level;
            if(v2.back()[1]>=T)
                return level;
        }

        return -1;
    }
};
