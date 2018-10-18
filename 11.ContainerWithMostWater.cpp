//
// Created by zhao on 18-10-18.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int left=0,right=height.size()-1;
        int max=0;
        int cur=0;
        while(left<right)
        {
            cur=(right-left)*findmin(height[left],height[right]);
            if(cur>max) max=cur;
            if(height[left]<height[right]) ++left;
            else --right;

        }
        return max;
    }

    inline int findmin(int a,int b)
    {
        return a<b?a:b;
    }
};



int main()
{
    vector<int> a={1,8,6,2,5,4,8,3,7};
    Solution n;
    cout<<n.maxArea(a)<<endl;


    return 0;
}


