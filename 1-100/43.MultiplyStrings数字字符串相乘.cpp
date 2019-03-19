#include<iostream>
#include<string>
using namespace std;
#include <algorithm>
#include <vector>


class Solution2 {
public:
	string multiply(string num1, string num2) {
		int i, j;
		int m = num1.size(), n = num2.size();
		// max (m + n) digits
		vector<int> product(m + n, 0);
		string result;

		// reverse for ease of calc
		reverse(num1.begin(), num1.end());
		reverse(num2.begin(), num2.end());

		// digit i * digit j contributes to digit i + j
		for (i = 0; i < m; i++) {
			for (j = 0; j < n; j++) {
				product[i + j] += (num1[i] - '0') * (num2[j] - '0');
				product[i + j + 1] += product[i + j] / 10;
				product[i + j] %= 10;
			}
		}

		// remove leading 0; keep last 0 if all 0
		for (i = m + n - 1; i > 0 && 0 == product[i]; i--);

		for (; i >= 0; i--)
			result += to_string(product[i]);

		return result;
	}
};


class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1=="0" || num2=="0") return "0";
        int *A = new int [num1.length()+num2.length()];
        reverse(num1.begin(),num1.end());
        reverse(num2.begin(),num2.end());

        int i,j;
        for(int i=0;i!=num1.length();++i)
            for(int j=0;j!=num2.length();++j)
            {
                A[i+j]+=(num1[i]-'0')*(num2[j]-'0');
                A[i+j+1]+=A[i+j]/10;
                A[i+j]%=10;
            }

        string s;
        for(int k=0;k!=num1.length()+num2.length();++k)
             s+=to_string(A[k]);
        delete[] A;

        size_t position=s.find_last_not_of('0');
        s.resize(position+1);
        reverse(s.begin(),s.end());

        return s;
    }
};

int main1032()
{
    string num1="9";
    string num2="98";
    Solution n;
    cout<< n.multiply(num1,num2) <<endl;

    return 0;
}