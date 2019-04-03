//
// Created by zhao on 19-4-3.
//

#include <iostream>
#include <vector>
using  namespace std;


//埃拉托斯特尼筛法Sieve of Eratosthenes中，
//这个算法的过程如下图所示，我们从2开始遍历到根号n，先找到第一个质数2，
//然后将其所有的倍数全部标记出来，
//然后到下一个质数3，标记其所有倍数，依次类推，直到根号n，此时数组中未被标记的数字就是质数。
//我们需要一个n-1长度的bool型数组来记录每个数字是否被标记，长度为n-1的原因是题目说是小于n的质数个数，并不包括n。


class Solution {
public:
    int countPrimes(int n) {
        if(n<2) return 0;
        vector<bool> prime(n-1,true);
        int res=0;
        for(int i=2;i!=n;++i)
        {
            if(prime[i])
                ++res;
            for(int j=2;i*j<n;++j)
                prime[i*j]=false;
        }
        return res;
    }
};



