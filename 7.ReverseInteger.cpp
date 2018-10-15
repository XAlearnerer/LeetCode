//
// Created by zhao on 18-10-15.
//

#include <iostream>
using namespace std;

#include <math.h>
class Solution {
public:
    int reverse(int x)
    {
       if(x<-pow(2,31) || x>pow(2,31)-1)
            return 0;
        long y=0;
        while(x!=0)
        {
            y=y*10+x%10;
            x/=10;
        }
        if(y<-pow(2,31) || y>pow(2,31)-1)
            return 0;
        return (int)y;
    }
};



int main()
{
    int integer=1534236469;
    Solution n;
    cout<<n.reverse(integer)<<endl;
    return 0;
}