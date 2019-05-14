//
// Created by zhao on 19-5-14.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> v1={1,2,2,1};
        vector<int> v2={2,2};
        sort(v1.begin(),v1.end());
        sort(v2.begin(),v2.end());
        vector<int> res;
        set_intersection(v1.begin(),v1.end(),v2.begin(),v2.end(),res.begin());
        for(auto i:res)
            cout<<i<<" ";
        return res;
    }
};

int main()
{
//    std::vector<int> v1{1,2,3,4,5,6,7,8};
//    std::vector<int> v2{5,7,9,10};
//    std::sort(v1.begin(), v1.end());
//    std::sort(v2.begin(), v2.end());
//
//    std::vector<int> v_intersection;
//
//    std::set_intersection(v1.begin(), v1.end(),
//                          v2.begin(), v2.end(),
//                          std::back_inserter(v_intersection));
//    for(int n : v_intersection)
//        std::cout << n << ' ';
//    cout<<endl;


    vector<int> v1={1,2,4,3};
    vector<int> v2={2,1};
    sort(v1.begin(),v1.end());
    sort(v2.begin(),v2.end());
    vector<int> res;
    auto m=res.begin();
    set_intersection(v1.begin(),v1.end(),v2.begin(),v2.end(),m);

    for(auto i:res)
        cout<<i<<" ";

//    Solution n;
//    for(auto i:n.intersection(v1,v2))
//        cout<<i<<" ";
    return 0;
}