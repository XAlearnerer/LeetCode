//
// Created by zhao on 19-5-20.
//

#include <iostream>
#include <map>
#include <vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    vector<int> fallingSquares(vector<vector<int>>& positions) {
        int n = positions.size(), cur = 0;
        vector<int> heights(n);
        for(int i=0;i<positions.size();++i)
        {
            int left=positions[i][0],len=positions[i][1];
            int right=left+len;
            heights[i]+=len;

            for(int j=i+1;j<positions.size();++j)
            {
                int left2=positions[j][0],len2=positions[j][1];
                int right2=left2+len2;

                if(left2<right && right2>left)
                {
                    heights[j]=max(heights[i],heights[j]);
                    //heights[j]=heights[i];

                    ////////////////////////////

//                    Input:
//                    [[50,47],[95,48],[88,77],[84,3],[53,87],[98,79],[88,28],[13,22],[53,73],[85,55]]
//                    Output:
//                    [47,95,172,172,172,216,244,244,317,372]
//                    Expected:
//                    [47,95,172,172,259,338,366,366,439,494]


                    ////////////////////////////

                }
            }

        }

        vector<int> res; int m=0;
        for(auto i:heights)
        {
            m=max(m,i);
            res.push_back(m);
        }
        return res;

    }
};


//int main()
//{
//    vector<vector<int>> v={{1, 2}, {2, 3}, {6, 1}};
//    Solution n;
//    for(auto i: n.fallingSquares(v))
//        cout<<i<<" ";
//    cout<<endl;
//
//    return 0;
//}