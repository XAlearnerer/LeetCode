//
// Created by zhao on 19-5-20.
//

#include <iostream>
#include <map>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> fallingSquares(vector<vector<int>>& positions) {
        int n = positions.size(), cur = 0;
        vector<int> heights(n), res;
        for(int i=0;i<positions.size();++i)
        {
            int left=positions[i][0],len=positions[i][1];
            int right=left+len;
            heights[i]+=len;

            for(int j=i+1;j<positions.size();++j)
            {
                int left2=positions[j][0],len2=positions[j][1];
                int right2=left2+len2;

                if(left2<right)
                {
                    heights[j]=max(heights[i],heights[j]);
                }
            }


        }


    }
};