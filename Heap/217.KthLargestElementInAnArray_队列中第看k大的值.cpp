//
// Created by zhao on 19-4-8.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        make_heap(nums.begin(),nums.end());
        int t=0;
        for(int i=0;i!=k;++i) {
            pop_heap(nums.begin(), nums.end());
            t=nums.back();
            nums.pop_back();
//            for(auto a:nums)
//                cout<<a<<" ";
//            cout<<endl;
        }
        return t;
    }
};

//int main()
//{
//    vector<int> nums={3,2,3,1,2,4,5,5,6};
//    int k=4;
//    Solution n;
//    cout<<n.findKthLargest(nums,k);
//
//    return 0;
//}

