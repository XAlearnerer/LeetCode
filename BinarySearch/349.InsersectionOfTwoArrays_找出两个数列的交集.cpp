//
// Created by zhao on 19-5-14.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <iterator>

using namespace std;

class Solution2 { /// Time Limit Exceeded
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.empty() || nums2.empty())
            return {};

        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        vector<int> res;
        set_intersection(nums1.begin(),nums1.end(),nums2.begin(),nums2.end(),back_inserter(res));

        if(res.empty()) return {};

        int i=0;
        while(i<res.size()-1)
        {
            if(res[i]==res[i+1]) {
                int j=i;
                while (res[j] == res[i + 1]) {
                    res.erase(res.begin() + i + 1);
                    ++i;
                }
            }
        }
        return res;
    }
};


class Solution {  /// use set to remove same numbers ...
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int> s1(nums1.begin(), nums1.end()), s2(nums2.begin(), nums2.end()), res;
        set_intersection(s1.begin(), s1.end(), s2.begin(), s2.end(), inserter(res, res.begin()));
        return vector<int>(res.begin(), res.end());
    }
};


//int main()
//{
////    std::vector<int> v1{1,2,3,4,5,6,7,8};
////    std::vector<int> v2{5,7,9,10};
////    std::sort(v1.begin(), v1.end());
////    std::sort(v2.begin(), v2.end());
////
////    std::vector<int> v_intersection;
////
////    std::set_intersection(v1.begin(), v1.end(),
////                          v2.begin(), v2.end(),
////                          std::back_inserter(v_intersection));
////    for(int n : v_intersection)
////        std::cout << n << ' ';
////    cout<<endl;
//
//    //vector<int> v1={21,47,80,4,3,24,87,12,22,11,48,6,89,80,74,71,74,55,58,56,4,98,40,66,49,53,62,27,3,66,78,24,48,69,88,12,80,63,98,65,46,35,72,5,64,72,7,29,37,3,2,75,44,93,79,78,13,39,85,26,15,41,87,47,29,93,41,74,6,48,17,89,27,61,2,68,99,57,45,73,25,33,38,32,58};
//    //vector<int> v2={1,39,6,81,85,10,38,22,0,89,57,93,58,69,65,80,84,24,27,54,37,36,26,88,2,7,24,36,51,5,74,57,45,56,55,67,25,33,78,49,16,79,74,80,36,27,89,49,64,73,96,60,92,31,98,72,22,31,0,93,70,87,80,66,75,69,81,52,94,90,51,90,74,36,58,38,50,9,64,55,4,21,49,60,65,47,67,8,38,83};
//
//    vector<int> v1={1,2,2,1};
//    vector<int> v2={2,2};
//
//    //    sort(v1.begin(),v1.end());
////    sort(v2.begin(),v2.end());
//
////    vector<int> res;
////    set_intersection(v1.begin(),v1.end(),v2.begin(),v2.end(),m);
//
////    for(auto i:res)
////        cout<<i<<" ";
//
//    Solution n;
//    for(auto i:n.intersection(v1,v2))
//        cout<<i<<" ";
//    return 0;
//}
