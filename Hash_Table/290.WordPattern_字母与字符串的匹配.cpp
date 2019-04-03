//
// Created by zhao on 19-4-3.
//
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using  namespace std;

class Solution {
public:
    bool wordPattern(string pattern, string str) {
        vector<string> v;
        string word;
        for(int i=0;i!=str.size();++i)
        {
            if(str[i]==' ')
            {
                if(word!=" ")
                    v.push_back(word);
                word="";
            }
            else
            {
                word+=str[i];
            }
        }
        if(!word.empty()) v.push_back(word);
        if(pattern.length()!=v.size())
            return false;


        unordered_map<char,int> p;
        unordered_map<string,int> s;

        for(int i=0;i!=pattern.length();++i)
        {
            if(p.count(pattern[i])!=0)
            {
                if(s.count(v[i])==0) return false;
                if(p[pattern[i]]!=s[v[i]]) return false;
            }
            else
            {
                if(s.count(v[i])!=0) return false;
                p[pattern[i]]=i;
                s[v[i]]=i;
            }
        }

        return true;

    }
};

int main()
{
    string pattern = "abba", str = "dog cat cat dog";
    Solution n;
    cout<<n.wordPattern(pattern,str)<<endl;

    return 0;
}