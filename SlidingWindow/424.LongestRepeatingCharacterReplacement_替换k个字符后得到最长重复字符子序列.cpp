#include<iostream>
#include<string>
#include<algorithm>
#include<unordered_map>

using namespace std;


class Solution {
public:
	int characterReplacement(string s, int k) {
		unordered_map<char, int> m;
		int left = 0, right = 0;
		int cur = 0, res = 0;
		for (; right < s.size(); ++right)
		{
			cur = max(cur, ++m[s[right]]);

			//for (auto i : m)
			//	cout << i.first << " -- " << i.second << endl;
			//cout << endl;

			while (right - left + 1 - cur > k)
			{
				--m[s[left]];
				++left;
			}
			res = max(res, right - left + 1);
		}

		return res;
	}
};










//�����������룬���û��k�����ƣ�
//����������ַ������ֻ��һ���ַ��ظ����ַ�����Ҫ����С�û�������
//��ô�����ַ������ܳ��ȼ�ȥ���ִ��������ַ��ĸ�����
//
//�������k�����ƣ�������ʵ����������
//(���ַ����ĳ��ȼ�ȥ���ִ��������ַ�����) <= k ��������ַ������ȼ��ɣ�
//��������һ�㣬����Ҳ��Ӧ��֪����ô�û������������˰�
//������һ������start��¼����������߽磬��ʼ��Ϊ0��Ȼ�����Ǳ����ַ�����
//ÿ���ۼӳ����ַ��ĸ�����Ȼ����³�������ַ��ĸ�����
//Ȼ�������жϵ�ǰ���������Ƿ�����֮ǰ˵���Ǹ�������
//��������㣬���ǾͰѻ���������߽������ƶ�һ������ע��ȥ�����ַ�Ҫ��counts���һ��
//ֱ���������������Ǹ��½��res����