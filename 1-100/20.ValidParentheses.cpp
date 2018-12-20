#include<iostream>
using namespace std;
#include<stack>

//? "([)]" is inValid!!!!!

//class Solution {
//public:
//	bool isValid(string s) {
//		if (s.empty()) return true;
//		int a[3] = { 0 };
//		for (int i = 0; i != s.length(); ++i)
//		{
//			if (a[0] < 0 || a[1] < 0 || a[2] < 0)
//				return false;
//			switch (s[i])
//			{
//				case '(':
//				{
//					++a[0];
//					break; 
//				}
//				case ')':
//				{
//					--a[0];
//					break;
//				}
//				case '[':
//				{
//					++a[1];
//					break;
//				}
//				case ']':
//				{
//					--a[1];
//					break;
//				}
//				case '{':
//				{
//					++a[2];
//					break;
//				}
//				case '}':
//				{
//					--a[2];
//					break;
//				}
//				default:
//					return false;
//		
//			}
//		}
//		if (a[0] == 0 && a[1] == 0 && a[2] == 0)
//			return true;
//		else
//			return false;
//
//	}
//};

class Solution {
public:
	bool isValid(string s) {
		stack<char> st;
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
				st.push(s[i]);
			}
			else {
				if (!st.empty()) {
					if (st.top() == '(' && s[i] == ')') {
						st.pop();
						continue;
					}
					else if (st.top() == '[' && s[i] == ']') {
						st.pop();
						continue;
					}
					else if (st.top() == '{' && s[i] == '}') {
						st.pop();
						continue;
					}
					else {
						return false;
					}
				}
				else {
					return false;
				}
			}
		}
		if (st.empty()) return true;
		else return false;
	}
};

int main2126()
{
	//"([)]" 
	string s = "{[]}";
	Solution n;
	cout << n.isValid(s) << endl;
	return 0;
}