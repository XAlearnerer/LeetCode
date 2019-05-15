//
// Created by zhao on 19-5-15.
//

#include <iostream>
using namespace std;

class Solution2 {
public:
    bool isPerfectSquare(int num) {
        for(int i=1;i <= num/i;++i)
        {
            if(i*i==num) return true;
        }

        return false;
    }
};

class Solution3 {  //// worng
public:
    bool isPerfectSquare(int num) {
        int left=1,right=num;
        while(left<right)
        {
            //int mid=(left+right)/2;
            int mid=left+(right-left)/2;
            int temp=mid*mid;
            if(temp==num) return true;
            else if(temp<num) left=mid+1;
            else right=mid;
        }
        return false;

    }
};

class Solution {
public:
    bool isPerfectSquare(int num) {
        long left = 0, right = num;
        while (left <= right) {
            long mid = left + (right - left) / 2, t = mid * mid;
            if (t == num) return true;
            else if (t < num) left = mid + 1;
            else right = mid - 1;
        }
        return false;
    }
};