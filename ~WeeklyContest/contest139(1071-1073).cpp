#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <bitset>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <string>
#include <set>
#include <map>

using namespace std;

class Solution1071 {
public:
	string gcdOfStrings(string str1, string str2) {
		if (str1.empty() || str2.empty()) return "";
		int res = 0;
		for (int i = 1; i <= min(str1.size(), str2.size()); ++i)
		{
			if (str1.size() % i == 0 && str2.size() % i == 0)
			{
				string cur = str1.substr(0, i);
				string a, b;
				for (int p = 0; p < str1.size() / i; ++p) a += cur;
				for (int q = 0; q < str2.size() / i; ++q) b += cur;
				if (a == str1 && b == str2) res = i;
			}
		}
		return str1.substr(0, res);

		//string s, l;
		//if (str1.size() < str2.size()) { s = str1; l = str2; }
		//else { s = str2; l = str1; }

		//if (search(l.begin(), l.end(), s.begin(), s.end()) == l.end()) return "";
		//else
		//{

		//}

	//	vector<int> v(26, 0);
	//	for (auto i : s) ++v[i - 'A'];
	//	sort(v.begin(), v.end());
	//	if (v[0] == 1) return s;
	//	else
	//	{
	//		int times = v[0];
	//		if (s.size() % v[0] != 0) return s;
	//		else
	//		{
	//			int pos = 0;
	//			while (s.size() / v[0] + pos < s.size())
	//			{
	//				if (s[pos] == s[s.size() / v[0] + pos])
	//					++pos;
	//				else return s;
	//			}
	//			return s.substr
	//		}
	//	}

	}
};


//////////////////////////////////////////////////////////////////////////


//  e.g.1
//  000     110
//  001 ->  111 <-all ones
//	110     000 <-all zeros
//	       ^^
//	       flip columns
//
//	e.g.2
//	00111       11111 <-all ones
//	11000       00000 <-all zeros
//	10101  ->   01101
//	10100       01100
//	00111       11111 <-all ones
//			   ^^
//			   flip columns
//
//	now we look closer, actually row0, row1 and row4 have the same pattern originally
//	row0 = 00111
//	row1 = 11000
//	row4 = 00111
//
//	so we can just flip the rows count the pattern occurrence 
//  instead of brainlessly flipping the columns
//


class Solution1072 {
public:
	int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
		int res = 1;
		for (int i = 0; i < matrix.size() - 1; ++i)
		{
			int cur = 1;
			for (int j = i + 1; j < matrix.size(); ++j)
			{
				if (helper(matrix[i], matrix[j])) ++cur;
			}
			res = max(res, cur);
		}
		return res;
	}



	bool helper(vector<int> a, vector<int> b)
	{
		if (a[0] == b[0])
		{
			for (int i = 1; i < a.size(); ++i)
			{
				if (a[i] != b[i]) return false;
			}
			return true;
		}
		else
		{
			for (int i = 1; i < a.size(); ++i)
			{
				if (a[i] == b[i]) return false;
			}
			return true;
		}
	}


};


//////////////////////////////////////////////////////////////////////////

class Solution1073 {
public:
	vector<int> addNegabinary(vector<int>& arr1, vector<int>& arr2) {
		//int a = 0, posta = 1;
		//for (int i = arr1.size() - 1; i >= 0; --i)
		//{

		//}

		//int b = 0;
		//for (int i = arr2.size() - 1; i >= 0; --i)
		//{

		//}


		///////////// �������ӷ� ////////////////

		if (arr1.empty()) return arr2;
		if (arr2.empty()) return arr1;
		int len1 = arr1.size(), len2 = arr2.size();
		int len = len1 + len2 + 1; 
//? ���� + 1 ��Ե�ʣ� [1]+[1] �Ļ���len1+len2 �ĳ��� ���㹻 ++res[i + 2];
		vector<int> res(len, 0);
		reverse(arr1.begin(), arr1.end());
		reverse(arr2.begin(), arr2.end());

		arr1.resize(len, 0);
		arr2.resize(len, 0);

		for (int i = 0; i < len; ++i) res[i] = arr1[i] + arr2[i];
		for (int i = 0; i < len - 1; ++i)
		{
			while (res[i] >= 2 && res[i + 1] > 0)
			{
				res[i] -= 2;
				--res[i + 1];
			}
			while (res[i] >= 2)
			{
				res[i] -= 2;
				++res[i + 1];
				++res[i + 2];
			}
		}

		while (res.size() > 1 && res.back() == 0) res.pop_back();
		reverse(res.begin(), res.end());
		return res;

	}
};


// ���⣺�������� - 2Ϊ���������֣�����������֮�͡�
// 
// ˼·�����ڴ������ӷ�����һ���Ƿ�ת�ַ�����ʹ�õ�λ��ǰ�棬��λ�ں��档
// �ڶ����Ǹ�λ���㡣
// ����������ӡ����� - 2�����������ԣ�����������ʱ���ܽ�λ���⡣
// ���Ĳ��Ǵ����λ�߼���
// ���岽ȥǰ���㡣
// ��������ת��������õ��𰸡�
// 
// ������ؼ���һ������δ����λ��
// �����ǰλ��ֵ��0��1���ǾͲ���Ҫ����
// �����ǰλ���ڵ���2������һλ����0����ô���Ե�������2*(-2) ^ k + (-2) ^ (k + 1) = 0��
// �����ǰλ��2����һλΪ0�������ת��Ϊ������λ������������
// 2 * (-2) ^ k = (-2) ^ (k + 1) + (-2) ^ (k + 2)��
// 
// ֤����
// ��k��ż��ʱ�����ս����2 ^ (k + 1)���ǹ�ʽչ�� - 2 ^ (k + 1) + 2 ^ (k + 2) = 2 ^ (k + 1)��
// ��k������ʱ�����ս���� - 2 ^ (k + 1)���ǹ�ʽչ��2 ^ (k + 1) - 2 ^ (k + 2) = -2 ^ (k + 1)��
// 
// �ɴˣ�����������Ĵ������еĽ�λ�ˡ�








