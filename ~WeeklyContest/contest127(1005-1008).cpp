//
// Created by zhao on 19-5-18.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

class Solution1005 {
public:
    int largestSumAfterKNegations(vector<int>& A, int K) {
        if(A.empty()) return 0;
        while(K>0)
        {
           int m=A[0],mi=0;
           for(int i=1;i<A.size();++i)
           {
               if(A[i]<m)
               {
                   m=A[i];
                   mi=i;
               }
           }
           A[mi]=-A[mi];
           --K;
        }

        int res=0;
        for(auto i:A)
            res+=i;
        return res;
    }
};

/////////////////////////////////////////////////////////////

class Solution1006 {
public:
    int clumsy(int N) {
        stack<int> s;
        s.push(1);
        while (N > 0) {
            int t = s.top();
            s.pop();
            s.push(N * t);
            --N;
            if(N>0)
            {
                t = s.top();
                s.pop();
                s.push(t * N);
                --N;
            }
            if (N > 0) {
                t = s.top();
                s.pop();
                s.push(t / N);
                --N;
            }
            if (N > 0) {
                s.push(N);
                --N;
            }
            if (N > 0) {
                s.push(-1);
            }
        }

        int res = 0;
        while (!s.empty()) {
            int i=s.top();
            s.pop();
            res += i;
        }


        return res;
    }
};

/////////////////////////////////////////////////////////////


class Solution1007 {
public:
    int minDominoRotations(vector<int>& A, vector<int>& B) {
        vector<int> v(10,0);
        for(auto i:A) ++v[i];
        for(auto i:B) ++v[i];

        int th=0,m=v[0];
        for(int i=1;i<10;++i)
        {
            if(v[i]>m)
            {
                m=v[i];
                th=i;
            }
        }

        int a=0,b=0;
        for(int i=0;i<A.size();++i)
        {
            if(A[i]==th && B[i]==th) continue;
            if(A[i]!=th && B[i]!=th) return -1;
            if(A[i]==th) ++a;
            if(B[i]==th) ++b;
        }

        return a<b?a:b;

    }
};


/////////////////////////////////////////////////////////////


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution1008 {
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        if(preorder.empty()) return NULL;
//        int height=0;
//        int len=preorder.size();
//        while(len>0)
//        {
//            len/=2;
//            ++height;
//        }

        //TreeNode* root=new TreeNode(preorder[0]);
        return  helper(preorder,0,preorder.size()-1);

    }

    TreeNode* helper(vector<int>& preorder,int left,int right)
    {
        TreeNode* cur=new TreeNode(preorder[left]);
        if(left==right) return cur;
        int pos=-1;
        bool flag=false;
        for(pos=left+1;pos<=right;++pos)
        {
            if(preorder[pos]>preorder[left])
            {
                flag=true;
                break;
            }
        }
        if(flag) cur->right=helper(preorder,pos,right);
        else cur->right=NULL;
        if(pos-left<=1) cur->left=NULL;
        else cur->left=helper(preorder,left+1,pos-1);
        return cur;
    }
};








