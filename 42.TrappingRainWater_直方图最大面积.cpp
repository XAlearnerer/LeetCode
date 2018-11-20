//
// Created by zhao on 18-11-14.
//
#include <vector>
#include <iostream>
using namespace std;

#include <stack>
#include <limits.h>
#include<Windows.h>

//单调栈

//class Solution2 {
//public:
//    int trap(vector<int>& height) {
//        stack<int> s;
//        int i=0;
//        int top=-1,maxwater=0,curwater=0;
//        while(i!=height.size())
//        {
//            if(s.empty() || height[s.top()]>height[i])
//                s.push(i++);
//            else
//            {
//                int minline=INT_MAX;
//                int minheight=INT_MAX;
//                while(!s.empty())
//                {
//                    top=s.top();
//                    if(height[top]<minline) minline=height[top];
//                    if(height[top]>height[i]) break;
//                    s.pop();
//                    if(height[top]==height[i]) break;
//                }
//                if(s.empty()) minheight=height[top];
//                else minheight=height[i];
//
//                curwater=(minheight-minline)*(i-top-1);
//                maxwater+=curwater;
//            }
//        }
//        return maxwater;
//    }
//};



class Solution2 {
public:
    int trap(vector<int>& height) {
        stack<int> st;
        int i = 0, res = 0, n = height.size();
        while (i < n) {
            if (st.empty() || height[i] <= height[st.top()]) {
                st.push(i++);
            } else {
                int t = st.top();
                st.pop();
                if (st.empty()) continue;
                res += (min(height[i], height[st.top()]) - height[t]) * (i - st.top() - 1);
            }
        }
        return res;
    }
};

class Solution {
public:
    int trap(vector<int>& height) {
        stack<int> s;
        int i=0,maxwater=0;
        while(i<height.size())
        {
            if(s.empty() || height[s.top()]>=height[i])
                s.push(i++);
            else
            {
                int top=s.top();
                s.pop();
                if(s.empty()) continue;
                maxwater+=(min(height[i],height[s.top()])-height[top])*(i-1-s.top());
            }
        }
        return maxwater;
    }
};


int main1035()
{
    vector<int> v={0,1,0,2,1,0,1,3,2,1,2,1};
    //vector<int> v={4,2,3};
    //vector<int> v={2,1,0,2};
    Solution n;
    cout<<n.trap(v)<<endl;

    return 0;
}