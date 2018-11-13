//
// Created by zhao on 18-11-12.
//
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> res{0};
        for (int i = 0; i < n; ++i) {
            int size = res.size();
            for (int j = size - 1; j >= 0; --j) {
                res.push_back(res[j] | (1 << i));
            }
        }
        return res;
    }
};

int main1622()
{
    Solution n;
    vector<int> m= n.grayCode(4);
    for(auto i:m)
        cout<<i<<" ";
    cout<<endl;

    return 0;
}