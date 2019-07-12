#include<iostream>

using namespace std;


struct TrieNode {
public:
	// Initialize your data structure here.
	TrieNode *child[26];
	bool isWord;
	TrieNode() : isWord(false) {
		for (auto &a : child) a = NULL;
	}
};


class Trie {
public:
	/** Initialize your data structure here. */
	Trie() {
		root = new TrieNode();
	}

	/** Inserts a word into the trie. */
	void insert(string word) {
		TrieNode* cur = root;
		for (auto c : word)
		{
			int i = c - 'a';
			if (!cur->child[i]) cur->child[i] = new TrieNode();
			cur = cur->child[i];
		}
		cur->isWord = true;
	}

	/** Returns if the word is in the trie. */
	bool search(string word) {
		TrieNode* t = root;
		for (auto c : word)
		{
			int i = c - 'a';
			if (!t->child[i]) return false;
			t = t->child[i];
		}
		if (t->isWord) return true;
		return false;
	}

	/** Returns if there is any word in the trie that starts with the given prefix. */
	bool startsWith(string prefix) {
		TrieNode* t = root;
		for (auto c : prefix)
		{
			int i = c - 'a';
			if (!t->child[i]) return false;
			t = t->child[i];
		}
		return true;
	}

	TrieNode* root;
};

/**
* Your Trie object will be instantiated and called as such:
* Trie* obj = new Trie();
* obj->insert(word);
* bool param_2 = obj->search(word);
* bool param_3 = obj->startsWith(prefix);
*/




