//
// Created by zhao on 19-4-3.
//

#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
#include <unordered_set>
#include <limits.h>
using namespace std;

//class Solution2 {
//public:
//    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
//        unordered_set<string> dir(wordList.begin(),wordList.end());
//        vector<vector<string>> res;
//        queue<string> q;
//        if(dir.count(endWord)==0)
//            return res;
//        q.push(beginWord);
//        while(!q.empty())
//        {
//            int size=q.size();
//            for(int i=0;i!=size;++i)
//            {
//                string cha=q.front();
//                q.pop();
//                if(cha==endWord)
//                {
//
//                }
//
//                string newcha=cha;
//                for(int j=0;j!=cha.size();++j)
//                {
//                    for(int k=0;k!=26;++k)
//                    {
//                        newcha[j]=char('a'+k);
//                        if(dir.count(newcha)!=0 && cha!=newcha)
//                        {
//                            q.push(newcha);
//
//                        }
//                    }
//
//                }
//            }
//        }
//
//        return res;
//    }
//};


////////////////////// 针对path的BFS算法 //////////////////////
class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dir(wordList.begin(),wordList.end());
        vector<vector<string>> res(0,vector<string>(0));
        if(dir.count(endWord)==0) return res;
        queue<vector<string>> paths;
        paths.push({beginWord});
        int level=1,minlevel=INT_MAX;
        unordered_set<string> visited(0);
        while (!paths.empty())
        {
            vector<string> p=paths.front();
            paths.pop();
            if(level<p.size())
            {
                for(auto a:visited) dir.erase(a);
                visited.clear();
                if(p.size()>minlevel) break;
                else level=p.size();
            }

            string str=p.back();
            for(int i=0;i!=str.size();++i)
            {
                string str2=str;
                for(int j=0;j!=26;++j)
                {
                    str2[i]=char('a'+j);
                    if(dir.count(str2)!=0 && str2!=str)
                    {
                        vector<string> np=p;
                        np.push_back(str2);
                        visited.insert(str2);
                        if(str2==endWord)
                        {
                            res.push_back(np);
                            minlevel=level;
                        }
                        else
                        {
                            paths.push(np);
                        }
                    }
                }
            }
        }
        return res;
    }
};

//int main()
//{
//    string beginWord="hit";
//    string endWord="cog";
//    vector<string> wordList={"hot","dot","dog","lot","log","cog"};
//    Solution n;
//    vector<vector<string>> res = n.findLadders(beginWord,endWord,wordList);
//    for(auto a:res)
//    {
//        for(auto b:a)
//            cout<<b<<" ";
//        cout<<endl;
//    }
//    return 0;
//}
