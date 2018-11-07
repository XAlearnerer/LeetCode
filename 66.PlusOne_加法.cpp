//
// Created by zhao on 18-11-6.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n=digits.size();
        for(int i=n-1;i>=0;--i)
        {
            if(digits[i]+1<10)
            {
                digits[i]+=1;
                return digits;
            }
            else
            {
                digits[i]=0;
                if(i==0)
                {
//                    digits.resize(digits.size()+1);
//                    for(int i=digits.size()-1;i>=0;--i)
//                    {
//                        digits[i+1]=digits[i];
//                    }
//                    digits[0]=1;
                    vector<int> v(digits.size()+1,0);
                    v[0]=1;
                    return v;

                }
            }
        }
        return digits;
    }
};

int main2130()
{
    vector<int> v={9,9,9};
    Solution n;
    vector<int> vv=n.plusOne(v);
    for(auto i:vv)
        cout<<i<<" ";
    cout<<endl;
    return 0;
}