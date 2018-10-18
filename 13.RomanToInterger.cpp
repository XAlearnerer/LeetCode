//
// Created by zhao on 18-10-18.
//

#include <map>
#include <iostream>
using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        int res=0;
        map<char, int> m{{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};
        for(int i=0;i!=s.length();++i)
        {
            if(m[s[i]]>= m[s[i+1]] || i==s.length()-1) res+=m[s[i]];
            else
                res-=m[s[i]];
        }
        return res;
    }
};



int main()
{
    string s="III";
    Solution n;
    cout<<n.romanToInt(s)<<endl;
    return 0;
}