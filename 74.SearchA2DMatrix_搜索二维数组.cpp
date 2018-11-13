//
// Created by zhao on 18-11-8.
//

#include <iostream>
#include <vector>
using  namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.empty() || matrix[0].empty()) return 0;
        int rows=matrix.size(),cols=matrix[0].size();
        int rleft=0,rright =rows-1;
        int rmid;
        while(rleft<=rright)
        {
            rmid=(rleft+rright)/2;
            if(matrix[rmid][0]==target)
                return true;
            else if(matrix[rmid][0]>target)
            {
                rright=rmid-1;
            }
            else
            {
                rleft=rmid+1;
            }
        }
//        if(matrix[rmid][0]>target)
//            --rmid;
        rmid=rright;
        if(rmid<0) return false;


        int cmid;
        int lleft=0,lright=cols-1;
        while(lleft<=lright)
        {
            cmid=(lleft+lright)/2;
            if(matrix[rmid][cmid]==target)
                return true;
            else if(matrix[rmid][cmid]>target)
            {
                lright=cmid-1;
            }
            else
            {
                lleft=cmid+1;
            }
        }

       return matrix[rmid][cmid]==target? true: false;
    }
};

class Solution2 {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.size() == 0 || matrix[0].size() == 0)
        {
            return false;
        }
        int m=matrix.size(),n=matrix[0].size();
        if(matrix[m-1][n-1] < target) return false;
        int start=0,end=m-1;
        while(start<=end){
            if(target<matrix[(start+end)/2][0])
                end=(start+end)/2-1;
            else if (target>matrix[(start+end)/2][0])
                start=(start+end)/2+1;
            else return true;
        }

        int row=end;
        start=0;
        end=n-1;
        if (row>=0){
            while(start<=end){
                if(target<matrix[row][(start+end)/2])
                    end=(start+end)/2-1;
                else if (target>matrix[row][(start+end)/2])
                    start=(start+end)/2+1;
                else return true;
            }
        }
        return false;
    }

};

int main1714()
{
   //vector<vector<int>> v={ {1, 3,  5,  7},{10, 11, 16, 20},{23, 30, 34, 50}};
    vector<vector<int>> v={{1}};
    Solution2 n;
    cout<<n.searchMatrix(v,0)<<endl;

    return 0;
}