//
// Created by zhao on 18-10-17.
//
#include <iostream>
#include <string>
#include <vector>
using namespace std;

// 其实这里没有必要将所有数字均存储在一个　vector 中，而且没有必要全部排序
//　只需要排序一半，并且只记录最近的两个数即可

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.empty())
            return nums2.size()%2==1?(double)nums2[(nums2.size())/2]:((double)nums2[(nums2.size())/2] + (double)nums2[(nums2.size())/2 - 1])/2;

        if(nums2.empty())
            return nums1.size()%2==1?(double)nums1[(nums1.size())/2]:((double)nums1[(nums1.size())/2] + (double)nums1[(nums1.size())/2 - 1])/2;

        int i=0,j=0,k=0;
        vector<int> n(nums1.size()+nums2.size(),0);
        while(i<nums1.size() && j<nums2.size())
        {
            if(nums1[i]<nums2[j]) {
                n[k] = nums1[i];
                ++k;
                ++i;
            }
            else
            {
                n[k]=nums2[j];
                ++k;
                ++j;
            }
        }

        while(i<=nums1.size()-1)
        {
            n[k]=nums1[i];
            ++k;
            ++i;
        }

        while(j<=nums2.size()-1)
        {
            n[k]=nums2[j];
            ++k;
            ++j;
        }


        if( (nums1.size()+nums2.size())%2 == 1 )
            return (double)n[(nums1.size()+nums2.size())/2];
        else
            return ((double)n[(nums1.size()+nums2.size())/2] + (double)n[(nums1.size()+nums2.size())/2 - 1])/2;

    }

};

int main1034()
{
    vector<int> a={};
    vector<int> b={1};
    Solution n;
    cout<<n.findMedianSortedArrays(a,b)<<endl;


    return 0;
}