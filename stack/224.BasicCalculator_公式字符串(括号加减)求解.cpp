//
// Created by zhao on 19-4-12.
//
#include <iostream>
#include <stack>
#include <string>
#include <algorithm>
#include<iterator>


using namespace std;

class Solution {
public:
	int calculate(string s) {
		stack<int> numstack,symstack;
		int num = 0;
		int res = 0;
		int sym = 1;
		for (auto a : s)
		{
			if (a >= '0' && a <= '9')
			{
				num = 10 * num + (a - '0');
			}
			else
			{
				res = res + sym*num;
				num = 0;
				if (a == '+') sym = 1;
				if (a == '-') sym = -1;
				if (a == '(')
				{
					numstack.push(res);
					symstack.push(sym);
					res = 0;
					sym = 1;
				}
				if (a == ')')
				{
					res = res*symstack.top() + numstack.top();
					symstack.pop();
					numstack.pop();
				}
			}
		}

		res = res + sym*num;
		return res;
    }
};





///// some stl algorithm test

//int main()
//{
//    string s="AAAABBAVABA";
//    string c="AB";
//    char cc='B';
//    int n = count_if(s.begin(),s.end(),bind2nd(equal_to<char>(),cc));
//    cout<<n<<endl;
//
//    vector<int> v;
//    for(int i=1;i!=10;++i)
//    {
//        if(i%2==0)
//            v.push_back(i);
//        else
//            v.push_back(-i);
//    }
//
//    cout<<count_if(v.begin(),v.end(),not1(bind2nd(modulus<int>(),2)))<<endl;
//    transform(v.begin(),v.end(),ostream_iterator<int>(cout," "),negate<int>());
//    cout<<endl;
//
//    transform(v.begin(),v.end(),v.begin(),v.begin(),multiplies<int>());
//    for(auto a:v)
//        cout<<a<<" ";
//    cout<<endl;
//
//    return 0;
//}