//
// Created by zhao on 19-5-13.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include<bitset>
#include <unordered_map>
#include <map>

using namespace std;

class Solution717 {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int pos=0;
        while(pos<bits.size())
        {
            if(pos==bits.size()-1) return true;
            if(bits[pos]==1)
                pos+=2;
            else
                ++pos;
        }
        return false;
    }
};



/////////////////////////////////////////////////////////////


class Solution443 {
public:
    int compress(vector<char>& chars) {
        //map<char,int> m;
        vector<pair<char,int>> m;
        char pre=chars[0];
        int sub=0;

        // ["a","a","a","b","b","a","a"]  ->   ["a","3","b","2","a","2"]
        for(auto i:chars)
        {


            if(i==pre) ++sub;
            else
            {
                //m[pre]=sub;
                m.push_back({pre,sub});
                pre=i;
                sub=1;
            }
        }
        //m[pre]=sub;
        m.push_back({pre,sub});


        if(chars.size()==m.size())
        {
            return chars.size();
        }
        else
        {
            chars.clear();
            for(auto i:m)
            {
                chars.push_back(i.first);
                if(i.second>1)
                {
                    int cur=i.second;
                    string s;
                    while(cur>0)
                    {
                        s+=cur%10+'0';
                        cur/=10;
                    }
                    reverse(s.begin(),s.end());
                    for(auto j:s)
                        chars.push_back(j);
                }
            }
        }

        return chars.size();

    }
};

//////////////////////////////////////////////////////////////////////

class Solution718_2 {
public:
    int findLength(vector<int>& A, vector<int>& B) {
        int col=A.size(),raw=B.size();
        if(raw==0 || col==0) return 0;
        vector<vector<int>> dp(raw+1,vector<int> (col+1,0));
        int res=0;
        for(int i=1;i<=raw;++i)
        {
            for(int j=1;j<=col;++j)
            {

                if(A[j-1]==B[i-1])
                {  dp[i][j]=dp[i-1][j-1]+1;
                    res=max(res,dp[i][j]);
                }
            }
        }
        return res;
    }
};



class Solution718 {
public:
    int findLength(vector<int>& A, vector<int>& B) {
        int m=A.size(),n=B.size();
        vector<int> dp(n+1,0);
        int res=0;
        if(m==0 || n==0) return 0;
        for(int i=m-1;i>=0;--i)
        {
            for(int j=0;j<n;++j)
            {
                if(A[i]==B[j])
                    dp[j]=1+dp[j+1];
                else
                    dp[j]=0;
                res=max(res,dp[j]);
            }
        }


        return res;
    }
};



//////////////////////////////////////////////////////////////////////

//class Solution2 {
//public:
//    int smallestDistancePair(vector<int>& nums, int k) {
//        vector<int> res;
//        for(int i=0;i!=nums.size();++i)
//        {
//            for(int j=0;j!=nums.size();++j)
//            {
//                if(i==j) continue;
//                res.push_back(abs(nums[i]-nums[j]));
//            }
//        }
//        sort(res.begin(),res.end());
//        return res[k*2-1];
//    }
//};
//
//
//class Solution3 {
//public:
//    int smallestDistancePair(vector<int>& nums, int k) {
//        vector<int> res;
//        unordered_map<int,int> check;
//        for(int i=0;i!=nums.size();++i)
//        {
//            for(int j=0;j!=nums.size();++j)
//            {
//                if(i==j) continue;
//                if(check.count(nums[i]))
//                {
//                    if(check[nums[i]]==nums[j]) continue;
//                }
//                check[nums[i]]=nums[j];
//                check[nums[j]]=nums[i];
//                res.push_back(abs(nums[i]-nums[j]));
//            }
//        }
//        sort(res.begin(),res.end());
//        return res[k-1];
//    }
//};






