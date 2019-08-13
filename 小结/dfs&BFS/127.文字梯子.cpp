#include<iostream>
#include<vector>
#include<unordered_set>
#include<queue>

using namespace std;

class Solution {
public:
	int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
		unordered_set<string> t(wordList.begin(), wordList.end());
		if (t.count(endWord) == 0) return 0;
		queue<string> q;
		q.push(beginWord);
		int level = 0;
		while (!q.empty())
		{
			int len = q.size();
			for (int i = 0; i < len; ++i)
			{
				string cur = q.front();
				q.pop();
				if (cur == endWord) return level + 1;
				for (int j = 0; j < cur.size(); ++j)
				{
					string post = cur;
					for (int c = 'a'; c <= 'z'; ++c)
					{
						post[j] = c;
						if (post == cur) continue;
						if (t.find(post) != t.end())
						{
							q.push(post);
							t.erase(post);
						}
					}

				}

			}


			++level;
		}

		return 0;
	}
};
