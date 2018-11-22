//
// Created by zhao on 18-11-21.
//
#include <iostream>
using namespace std;

class Solution {
public:
    int numTrees(int n) {
        if(n==1) return 1;
        int i=2;
        int *a=new int[n+1];
        a[0]=1,a[1]=1;
        while(i<=n)
        {
            for(int j=0;j!=i;++j) {
                a[i] += a[j] * a[i-1 - j];
            }
            ++i;
        }
        return a[n];
    }
};

