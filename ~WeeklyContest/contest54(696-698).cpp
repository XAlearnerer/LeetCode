//
// Created by zhao on 19-5-20.
//
#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <bitset>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <string>
#include <set>
#include <limits.h>
#include <map>

using namespace std;

class Solution696 {
public:
    int findShortestSubArray(vector<int>& nums) {
        //vector<int> v(10,0);
        unordered_map<int,int> v;
        for(int i=0;i<nums.size();++i)
        {
            ++v[nums[i]];
        }
        vector<int> ma;
        int m=v[0];
        for(int i=0;i<v.size();++i)
        {
            m=max(m,v[i]);
        }
        for(int i=0;i<v.size();++i)
        {
            if(v[i]==m) {
                ma.push_back(i);
            }
        }

        int res=nums.size();
        for(int i=0;i<ma.size();++i)
        {
            res=min(res,fromlast(nums,ma[i])-fromfirst(nums,ma[i]));
        }
        return res + 1;
    }

    int fromfirst(vector<int>& nums,int t)
    {
        for(int i=0;i<nums.size();++i)
            if(nums[i]==t) return i;

        return -1;
    }
    int fromlast(vector<int>& nums,int t)
    {
        for(int i=nums.size()-1;i>=0;--i)
            if(nums[i]==t) return i;

        return -1;
    }

};

//////////////////////////////////////////////////////////////////////////


class Solution697 {
public:
    int countBinarySubstrings(string s) {
        int ones=0,zero=0;
        if(s[0]=='0') ++zero;
        else ++ones;

        int res=0;
        for(int i=1;i<s.size();++i)
        {
            if(s[i]=='0')
            {
                if(s[i-1]=='0') ++zero;
                else zero=1;
                if(ones>=zero) ++res;
            }
            else
            {
                if(s[i-1]=='1') ++ones;
                else ones=1;
                if(zero>=ones) ++res;
            }
        }

        return res;
    }
};



//////////////////////////////////////////////////////////////////////////




class Solution698 {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum=0;
        for(auto i:nums) sum+=i;
        if(sum%k!=0) return false;
        int tar=sum/k;
        //sort(nums.begin(),nums.end());
        vector<int> visited(nums.size(),0);
        return helper(nums,k,tar,0,visited,0);

    }

    bool helper(vector<int>& nums, int k,int tar,int cur,vector<int>& visited,int start)
    {
        if(k==1) return true;
        //if(cur>tar) return false;
        if(cur==tar) return helper(nums,k-1,tar,0,visited,0);

        for(int i=start;i<nums.size();++i)
        {
            if(visited[i]==1) continue;
            visited[i]=1;
            if(helper(nums,k,tar,cur+nums[i],visited,i)) return true;
            visited[i]=0;
        }
        return false;
    }

};

//////////////////////////////////////////////////////////////////////////









