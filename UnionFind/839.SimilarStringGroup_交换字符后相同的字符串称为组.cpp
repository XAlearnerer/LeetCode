#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

class Solution {
public:
	int numSimilarGroups(vector<string>& A) {
		unordered_map<string, string> m;
		for (int i = 0; i != A.size(); ++i)
		{
			if (m.find(A[i]) != m.end()) continue;
			m[A[i]] = A[i];
			for (int j = i - 1; j >= 0; --j)
			{
				//? worng Ϊʲô�أ�
				// if (similar(A[i], A[j]) && m[A[i]] != A[j])
				// {
				// 	   string temp = find(m, A[j]);
				// 	   m[A[i]] = temp;
				// }

				if (similar(A[i], A[j]) && m[A[j]] != A[i])
				{
					string temp = find(m, A[j]);
					m[temp] = A[i];
				}

			}
		}
		int res = 0;
		for (auto i : m)
		{
			if (i.first == i.second)
				++res;
		}

		return res;
	}

	string find(unordered_map<string, string>& m,string cur)
	{
		while (m[cur] != cur)
		{
			m[cur] = m[m[cur]];
			cur = m[cur];
		}
		return m[cur];
	}

	bool similar(string a, string b)
	{
		if (a.length() != b.length()) return false;
		int dif = 0;
		for (int i = 0; i != a.length(); ++i)
		{
			if (a[i] != b[i]) ++dif;
		}
		return dif == 2;
	}
};

