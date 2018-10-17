//
// Created by zhao on 18-10-17.
//

#include <iostream>
using namespace std;

class Solution2 {
public:
    bool isPalindrome(int x) {
        string s = to_string(x);
        if (s.length() == 1) return true;

        size_t i = 0, j = s.length() - 1;
        while (i < j) {
            if (s[i] != s[j]) return false;
            ++i;
            --j;
        }
        return true;
    }
};

class Solution3 {
public:
    bool isPalindrome(int x) {
        if((x!=0 &&x%10==0 )|| x<0) return false;
        if(x==reverse(x)) return true;
        else return false;

    }
    int reverse(int x)
    {
        int y=0;
        while(x!=0)
        {
            y=y*10+x%10;
            x/=10;
        }
        return y;
    }
};

class Solution {
public:
    bool isPalindrome(int x) {
        if((x!=0 &&x%10==0 )|| x<0) return false;
        int res=x;
        long long y=0;
        while(x){
            y*=10;
            y+=x%10;
            x/=10;
        }
        if (res==y){
            return true;
        }
        else{
            return false;
        }
    }
};

int main()
{
    int a=1010;
    Solution n;
    cout<<n.isPalindrome(a)<<endl;
    return 0;
}