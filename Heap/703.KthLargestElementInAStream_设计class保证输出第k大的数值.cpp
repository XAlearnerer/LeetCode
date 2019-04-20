//
// Created by zhao on 19-4-12.
//

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
//#include<xfunctional>

using namespace std;

class KthLargest2 {
public:
    KthLargest2 (int k, vector<int>& nums) {  ////////Time Limit Exceeded
        _k=k;
        q.assign(nums.begin(),nums.end());
    }

    int add(int val) {
        q.push_back(val);
        sort(q.begin(),q.end(),[](int &a,int &b){ return a>b;});
        //sort(q.begin(),q.end(),greater<int>());
        return q[_k-1];
    }

    vector<int> q;
    int _k;
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */

class KthLargest {
public:
    KthLargest(int k, vector<int>& nums) {
        _k=k;
        for(int n:nums)
        {
            q.push(n);
            if(q.size()>k)
                q.pop();
        }
    }

    int add(int val) {
        //q.push(val);
        q.push(val);
        if(q.size()>_k)
            q.pop();
        return q.top();
    }

    priority_queue<int,vector<int>,greater<int>> q;
    int _k;
};
