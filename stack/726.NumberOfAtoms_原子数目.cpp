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









//  那么我们可以发现规律，先统计括号里的原子个数，
//  然后如果括号外面有数字，那么括号里每个原子的个数乘以外面的数字即可，
//  然后在外层若还有数字，那么就继续乘这个数字，这种带有嵌套形式的字符串，
//  比较适合用递归来做。我们最终的目的是统计每个原子的数量，
//  所以我们只要建立了每个元素和其出现次数的映射，就可以生成返回的字符串了
//  ，由于需要按元素的字母顺序排列，所以我们使用TreeMap来建立映射。
//  
//  我们使用一个变量pos，来记录我们遍历的位置，这是个全局的变量，
//  在递归函数参数中需要设置引用。我们遍历的时候，需要分三种情况讨论，
//  分别是遇到左括号，右括号，和其他。我们一个个来看：
//  
//  如果当前是左括号，那么我们pos先自增1，跳过括号位置，
//  然后我们可以调用递归函数，来处理这个括号中包括的所有内容，
//  外加上后面的数字，比如Mg(OH)2，在pos = 2处遇到左括号，
//  调用完递归函数后pos指向了最后一个字符的后一位，即pos = 7。
//  而在K4(ON(SO3)2)2中，如果是遇到中间的那个左括号pos = 5时，
//  调用完递归函数后pos指向了第二个右括号，即pos = 11。
//  递归函数返回了中间部分所有原子跟其个数之间的映射，
//  我们直接将其都加入到当前的映射中即可。
//  
//  如果当前是右括号，说明一个完整的括号已经遍历完了，
//  我们需要取出其后面的数字，如果括号存在，那么后面一定会跟数字，
//  否则不需要括号。所以我们先让pos自增1，跳过括号的位置，
//  然后用个变量i记录当前位置，再进行while循环，找出第一个非数字的位置，
//  那么中间就都是数字啦，用substr将其提取出来，并转为整数，然后遍历当前的映射对，
//  每个值都乘以这个倍数即可，然后返回。
//  
//  如果当前是字母，那么需要将元素名提取出来了，
//  题目中说了元素名只有第一个字母是大写，后面如果有的话，都是小写字母。
//  所以我们用个while循环找到第一个非小写字母的位置，用substr取出中间的字符串，
//  即元素名。由于元素名后也可能跟数字，所以在用个while循环，
//  来找之后第一个非数字的位置，用substr提取出数字字符串。
//  当然也可能元素名后没有数字，提取出来的数字字符串就是空的，
//  我们加的时候判断一下，如果为空就只加1，否则就加上转化后的整数。


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
