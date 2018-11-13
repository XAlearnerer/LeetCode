//
// Created by zhao on 18-11-11.
//
#include <iostream>
#include <vector>
using namespace std;



class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> v(m+n);
        int i=0,j=0,k=0;
        while(i<m && j<n)
        {
            if(nums1[i]<nums2[j])
            {
                v[k]=nums1[i];
                ++k;
                ++i;
            }
            else
            {
                v[k]=nums2[j];
                ++k;
                ++j;
            }
        }

        while(i<m)
        {
            v[k]=nums1[i];
            ++k;
            ++i;
        }
        while(j<n)
        {
            v[k]=nums2[j];
            ++k;
            ++j;
        }

        int nums1length=nums1.size();
        nums1.assign(v.begin(),v.end());
        nums1.resize(nums1length);

    }
};

int main2038()
{
    vector<int> n1={1,2,3,0,0,0,0};
    vector<int> n2={2,5,6};
    Solution n;
    n.merge(n1,3,n2,3);
    for(auto i:n1)
        cout<<i<<" $ ";
    cout<<endl;
}