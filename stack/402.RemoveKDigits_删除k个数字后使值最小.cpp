#include<iostream>
#include<string>

using namespace std;

class Solution {
public:
	string removeKdigits(string num, int k) {
		if (k == num.size()) return "0";
		int n = num.length();
		string res = "";
		int reslen = n - k;
		for (char c : num)
		{
			while (k && c < res.back() && res.size() > 0)
			{
				res.pop_back();
				--k;
			}
			res.push_back(c);
		}

		res.resize(reslen);
		while (!res.empty() && res[0] == '0') res.erase(res.begin());
		if (res.empty()) return "0";
		return res;
	}
};







//
//����������ǽ�����������ȥ��kλ��Ҫʹ����������������С��
//�����LeetCode��֮ǰ�ǵ�Create Maximum Number��Щ���ƣ�
//���Խ�����е�˼·�����n��num�ĳ��ȣ�����Ҫȥ��k������ô��Ҫʣ��n - k����
//���ǿ�ʼ������������num��ÿһλ�����ڵ�ǰ������������c��
//��������whileѭ�������res��Ϊ�գ���k����0����res�����һλ����c��
//��ô����Ӧ�ý�res�����һλ��ȥ����k�Լ�1��������whileѭ�������ǽ�c����res�У�
//������ǽ�res�Ĵ�С����Ϊn - k��������Ŀ�е����������ܻ����"0200"����������Ҫ��������
//����������һ��whileѭ����ȥ��ǰ�������0��Ȼ�󷵻�ʱ�ж��Ƿ�Ϊ�գ�Ϊ���򷵻ء�0��
