#include<iostream>
#include<vector>
#include<string>
#include<map>

using namespace std;

class Solution {
public:
	string countOfAtoms(string formula) {
		map<string, int> m; // attation :  Mg Fe !!!!
		string res = "";
		int pos = 0;
		for (auto i : helper(formula, pos))
		{
			if (i.second != 1)
				res += i.first + to_string(i.second);
			else
				res += i.first;
		}
		return res;
	}

	map<string, int> helper(string &s, int &pos)
	{
		map<string, int> cur;
		while (pos < s.length())
		{
			if (s[pos] == '(')
			{
				++pos;
				for (auto i : helper(s, pos))
					cur[i.first] += i.second;
			}
			else if (s[pos] == ')')
			{
				++pos;
				int numpre = pos;
				while (pos < s.length() && isdigit(s[pos])) ++pos;
				int multi = stoi(s.substr(numpre, pos - numpre));
				for (auto& i : cur)
					i.second *= multi;
				return cur;
			}
			else
			{
				int cter = pos;
				++pos;
				while (pos < s.length() && islower(s[pos])) ++pos;
				string letter = s.substr(cter, pos - cter);
				cter = pos;
				while (pos < s.length() && isdigit(s[pos])) ++pos;
				string letnum = s.substr(cter, pos - cter);
				if (letnum.empty()) cur[letter] += 1;
				else cur[letter] += stoi(letnum);
			}
		}
		return cur;
	}

};









//  ��ô���ǿ��Է��ֹ��ɣ���ͳ���������ԭ�Ӹ�����
//  Ȼ������������������֣���ô������ÿ��ԭ�ӵĸ���������������ּ��ɣ�
//  Ȼ����������������֣���ô�ͼ�����������֣����ִ���Ƕ����ʽ���ַ�����
//  �Ƚ��ʺ��õݹ��������������յ�Ŀ����ͳ��ÿ��ԭ�ӵ�������
//  ��������ֻҪ������ÿ��Ԫ�غ�����ִ�����ӳ�䣬�Ϳ������ɷ��ص��ַ�����
//  ��������Ҫ��Ԫ�ص���ĸ˳�����У���������ʹ��TreeMap������ӳ�䡣
//  
//  ����ʹ��һ������pos������¼���Ǳ�����λ�ã����Ǹ�ȫ�ֵı�����
//  �ڵݹ麯����������Ҫ�������á����Ǳ�����ʱ����Ҫ������������ۣ�
//  �ֱ������������ţ������ţ�������������һ����������
//  
//  �����ǰ�������ţ���ô����pos������1����������λ�ã�
//  Ȼ�����ǿ��Ե��õݹ麯������������������а������������ݣ�
//  ����Ϻ�������֣�����Mg(OH)2����pos = 2�����������ţ�
//  ������ݹ麯����posָ�������һ���ַ��ĺ�һλ����pos = 7��
//  ����K4(ON(SO3)2)2�У�����������м���Ǹ�������pos = 5ʱ��
//  ������ݹ麯����posָ���˵ڶ��������ţ���pos = 11��
//  �ݹ麯���������м䲿������ԭ�Ӹ������֮���ӳ�䣬
//  ����ֱ�ӽ��䶼���뵽��ǰ��ӳ���м��ɡ�
//  
//  �����ǰ�������ţ�˵��һ�������������Ѿ��������ˣ�
//  ������Ҫȡ�����������֣�������Ŵ��ڣ���ô����һ��������֣�
//  ������Ҫ���š�������������pos����1���������ŵ�λ�ã�
//  Ȼ���ø�����i��¼��ǰλ�ã��ٽ���whileѭ�����ҳ���һ�������ֵ�λ�ã�
//  ��ô�м�Ͷ�������������substr������ȡ��������תΪ������Ȼ�������ǰ��ӳ��ԣ�
//  ÿ��ֵ����������������ɣ�Ȼ�󷵻ء�
//  
//  �����ǰ����ĸ����ô��Ҫ��Ԫ������ȡ�����ˣ�
//  ��Ŀ��˵��Ԫ����ֻ�е�һ����ĸ�Ǵ�д����������еĻ�������Сд��ĸ��
//  ���������ø�whileѭ���ҵ���һ����Сд��ĸ��λ�ã���substrȡ���м���ַ�����
//  ��Ԫ����������Ԫ������Ҳ���ܸ����֣��������ø�whileѭ����
//  ����֮���һ�������ֵ�λ�ã���substr��ȡ�������ַ�����
//  ��ȻҲ����Ԫ������û�����֣���ȡ�����������ַ������ǿյģ�
//  ���Ǽӵ�ʱ���ж�һ�£����Ϊ�վ�ֻ��1������ͼ���ת�����������


class Solution2 {
public:
	string countOfAtoms(string formula) {
		string res = "";
		int pos = 0;
		map<string, int> m = parse(formula, pos);
		for (auto a : m) {
			res += a.first + (a.second == 1 ? "" : to_string(a.second));
		}
		return res;
	}
	map<string, int> parse(string& str, int& pos) {
		map<string, int> res;
		while (pos < str.size()) {
			if (str[pos] == '(') {
				++pos;
				for (auto a : parse(str, pos)) res[a.first] += a.second;
			}
			else if (str[pos] == ')') {
				int i = ++pos;
				while (pos < str.size() && isdigit(str[pos])) ++pos;
				int multiple = stoi(str.substr(i, pos - i));
				for (auto a : res) res[a.first] *= multiple;
				return res;
			}
			else {
				int i = pos++;
				while (pos < str.size() && islower(str[pos])) ++pos;
				string elem = str.substr(i, pos - i);
				i = pos;
				while (pos < str.size() && isdigit(str[pos])) ++pos;
				string cnt = str.substr(i, pos - i);
				res[elem] += cnt.empty() ? 1 : stoi(cnt);
			}
		}
		return res;
	}
};
