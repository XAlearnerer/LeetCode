//
// Created by zhao on 18-11-10.
//

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int top=0;
        int maxarea=-1;
        stack<int> s;
        int curarea;

        int i=0;
        while(i<heights.size())
        {
            if(s.empty() || heights[s.top()]<= heights[i])
                s.push(i++);

            else
            {
                top=s.top();
                s.pop();
                curarea=heights[top]* (s.empty()? i: i-s.top()-1);
                if(curarea>maxarea)
                    maxarea=curarea;
            }
        }

        while(!s.empty())
        {
            top=s.top();
            s.pop();
            curarea=heights[top]* (s.empty()? i: i-s.top()-1);
            if(curarea>maxarea)
                maxarea=curarea;
        }

        return maxarea;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.empty()) return 0;
        int num=matrix.size();
        vector<vector<int> >vmatr;
        vector<int> v(matrix[0].size());
        for(int i=0;i!=matrix[0].size();++i)
            v[i]=matrix[0][i]-'0';
        vmatr.push_back(v);
        for(int i=1;i!=num;++i)
        {
            for(int j=0;j!=matrix[0].size();++j)
            {
                if(matrix[i][j]=='0') v[j]=0;
                else v[j]+=matrix[i][j]-'0';
            }
            vmatr.push_back(v);
        }

        int maxarea=0;
        for(int i=0;i!=vmatr.size();++i)
        {
            if(maxarea<largestRectangleArea(vmatr[i]))
                maxarea=largestRectangleArea(vmatr[i]);
        }

        return maxarea;

    }
};

int  main1641()
{
    vector<vector<char>> matrix ={ {'1','0','1','0','0'},
                                   {'1','0','1','1','1'},
                                   {'1','1','1','1','1'},
                                   {'1','0','0','1','0'} };
    Solution n;
    cout<<n.maximalRectangle(matrix)<<endl;

    return 0;
}