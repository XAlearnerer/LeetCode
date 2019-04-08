//
// Created by zhao on 19-4-7.
//

#include <iostream>
#include <string>

using  namespace std;


class WordDictionary {
public:
    struct wordTree{
        wordTree* child[26];
        bool isword;
        wordTree():isword(false)
        {
            for(auto &a:child) a= nullptr;
        }
    };

    wordTree *root;
    /** Initialize your data structure here. */
    WordDictionary() {
        root=new wordTree;
    }

    /** Adds a word into the data structure. */
    void addWord(string word) {
        wordTree *p=root;
        for(auto &a:word)
        {
            int n=a-'a';
            if(!p->child[n]) p->child[n]=new wordTree();
            p=p->child[n];
        }
        p->isword=true;
    }

    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        return searchWord(word, root, 0);
    }

    bool searchWord(string &word,wordTree *p,int n)
    {
        if(n==word.size()) return p->isword;
        if(word[n]=='.')
        {
            for(auto &a:p->child)
            {
                if(a && searchWord(word, a, n+1)) return true;
            }
            return false;
        }

        else
        {
            return p->child[word[n]-'a'] && searchWord(word,p->child[word[n]-'a'],n+1);
        }

    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */

