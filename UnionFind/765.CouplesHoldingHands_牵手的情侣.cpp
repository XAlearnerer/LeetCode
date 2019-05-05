#include<iostream>
#include<vector>

using namespace std;


////////// Greedy /////////

// һ��trick��һ�����������1��������һ��λ��
// ���������⣬�����ż���Ļ������λ��0��
// �������1���ڼ���1������˿��Եĳɶ�������
// 
// ����������Ļ������λ��1���������1���Ϊ��0��
// ����˿��Եĳɶ�ż����



class Solution2 {
public:
	int minSwapsCouples(vector<int>& row) {
		int res = 0;
		int i = 0;
		while (i < row.size())
		{
			if (row[i + 1] == (row[i] ^ 1)) 
			{
				i += 2;
				continue;
			}
			for (int j = i + 2; j < row.size();++j)
			{
				if (row[j] == (row[i] ^ 1))
				{
					swap(row[i + 1], row[j]);
					break;
				}
			}
			++res;
			i += 2;
		}
		return res;
	}
};


//////////// unionfind ////////////////

class Solution {
public:
	int minSwapsCouples(vector<int>& row) {
		vector<int> root(row.size(), 0);
		int res = 0;
		for (int i = 0; i != row.size(); ++i) root[i] = i;
		for (int i = 0; i != row.size(); i += 2)
		{
			int m = find(root, row[i] / 2);
			int n = find(root, row[i + 1] / 2);
			if (m != n)
			{
				root[m] = n;
				++res;  //?  ����û��ͨ
			}
		}
		return res;
	}
	int find(vector<int>& root, int i)
	{
		while (i != root[i])
		{
			root[i] = root[root[i]];
			i = root[i];
		}
		return i;
	}
};



int main()
{
	vector<int> r = { 0, 2, 1, 3 };
	Solution n;
	cout << n.minSwapsCouples(r) << endl;
	return 0;
}
