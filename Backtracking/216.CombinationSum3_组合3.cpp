//
// Created by zhao on 19-4-6.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        vector<int> com;
        backtracking2(res,com,k,n,1);
        return res;
    }

    void backtracking(vector<vector<int>>& res,vector<int>& com,int k,int n,int now)
    {
        if(n<0) return;
        if(n==0 && k==com.size()) {
            res.push_back(com);
            return;
        }
        for(int i=now;i<10;++i)
        {
            com.push_back(i);
            backtracking(res,com,k,n-i,i+1);
            com.pop_back();
        }
    }

    void backtracking2(vector<vector<int>>& res,vector<int>& com,int k,int n,int now)
    {
        if(n==0) {
            res.push_back(com);
            return;
        }
        for (int i = now; i < 10; ++i) {
            if(i>n ||k<=com.size() ) break;
            com.push_back(i);
            backtracking(res, com, k, n - i, i + 1);
            com.pop_back();
        }
    }

};






//void back(vector<vector<int>>& res,vector<int>& v,int t)
//{
//    if(t==v.size()-1)
//        res.push_back(v);
//    for(int i=t;i<v.size();++i)
//    {
//        swap(v[i],v[t]);
//        back(res,v,t+1);
//        swap(v[i],v[t]);
//    }
//}
//
//int main()
//{
//    vector<int> v = {1,2,3};
//    vector<vector<int>> res;
//    back(res,v,0);
//    for(auto a:res)
//    {
//        for(auto b:a)
//            cout<<b<<" ";
//        cout<<endl;
//    }
//}
