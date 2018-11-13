//
// Created by zhao on 18-11-8.
//

#include <iostream>
using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        int i=3,j=2,k=3;
        if(n==1)return 1;
        if(n==2)return 2;
        int tmp;
        while(k<=n)
        {
            tmp=i;
            i=i+j;
            j=tmp;
            ++k;
        }
        return i;
    }
};