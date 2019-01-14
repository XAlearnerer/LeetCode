//
// Created by zhao on 19-1-14.
//

#include <iostream>
#include <vector>
using  namespace std;


//class Solution2 {
//public:
//    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
//        int gassum=0,costsum=0;
//        for(int i=0;i!=gas.size();++i)
//            gassum+=gas[i];
//        for(int k=0;k!=cost.size();++k)
//            costsum+=cost[k];
//        if(gassum<costsum)
//            return -1;
//
//        vector<int> beginPoint;
//        for(int i=0;i!=gas.size();++i)
//            if(gas[i]>=cost[i])
//                beginPoint.push_back(i);
//
//        int restgas=0;
//        for(int i=0;i!=beginPoint.size();++i)
//        {
//            int start=beginPoint[i],now,next;
//            for(int j=0;j!=gas.size();++j)
//            {
//                if(j==gas.size()-1)
//                    next=0;
//                else
//                    next=next+1;
//
//                restgas+=gas[]
//
//            }
//        }
//    }
//};



class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int total=0,sum=0;
        int start=0;
        for(int i=0;i!=gas.size();++i)
        {
            total+=gas[i]-cost[i];
            sum+=gas[i]-cost[i];
            if(sum<0)
            {
                start=i+1;
                sum=0;
            }
        }
        if(total>=0) return start;
        else return -1;
    }
};


class Solution2 {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int total=0;
        int start=0,mx=-1;
        for(int j=gas.size()-1;j>=0;--j)
        {
            total+=gas[j]-cost[j];
            if(total>mx)
            {
                start=j;
                mx=total;
            }
        }
        if(total>=0) return start;
        else return -1;
    }
};