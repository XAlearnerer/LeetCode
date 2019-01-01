//
// Created by zhao on 18-12-26.
//

#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int ladlen=0;

        unordered_set<string> wordSet(wordList.begin(), wordList.end());
//        if(find(wordList.begin(),wordList.end(),endWord)==wordList.end())
//            return ladlen;
        if(!wordSet.count(endWord))
            return ladlen;
        queue<string> q;
        q.push(beginWord);
        while(!q.empty())
        {
            int size=q.size();
            for(int k=0;k!=size;++k) {
                string wo = q.front();
                q.pop();
                if (wo == endWord)
                    return ladlen+1;

                for (int i = 0; i != wo.length(); ++i) {
                    string newwo=wo;
                    for (int j = 0; j != 26; ++j) {
                            newwo[i] = (char) ('a' + j);
                        //auto it=find(wordList.begin(), wordList.end(), newwo);
                        //if (it != wordList.end() && newwo!=wo) {
                        if (wordSet.count(newwo) && newwo!=wo) {
                            q.push(newwo);
                            wordSet.erase(newwo);
                        }
                    }
                }
            }
            ++ladlen;
        }
        return 0;
    }
};


