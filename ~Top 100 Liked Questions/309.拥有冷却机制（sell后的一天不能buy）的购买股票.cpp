#include<iostream>
#include<cstring>  
#include<vector>
#include<algorithm>	


using namespace std;

//int main()
//{
//	//char a[] = "hello";
//	//a[0] = 'X';
//	//cout << a << endl;
//
//
//	//char *p = "world"; // 注意p指向常量字符串
//	//p[0] = 'X'; // 编译器不能发现该错误
//	//cout << p << endl;
//
//	char a[] = "hello";
//
//	char b[10];
//	strcpy(b, a); // 不能用 b = a;
//
//	cout << b << endl;
//
//	int len = strlen(a);
//	char *p = (char*)malloc(sizeof(char)*(len + 1));
//	strcpy(p, a); // 不要用 p = a;
//
//	cout << p << endl;
//
//	return 0;
//}





// After you sell your stock, you cannot buy stock on next day. (ie, cooldown 1 day)

   
//! buy[i]: The maximum profit can be made if the first i days end with buy or wait.
//! E.g "buy, sell, buy" or "buy, cooldown, cooldown"
//! sell[i] : The maximum profit can be made if the first i days end with sell or wait.
//! E.g "buy, sell, buy, sell" or "buy, sell, cooldown, cooldown"
//! price : prices[i - 1], which is the stock price of the i - th day
//! 
//! 	To calculate sell[i] :
//! 	If we sell on the i - th day, the maximum profit is buy[i - 1] + price, 
//! 	because we have to buy before we can sell.
//! 	If we cooldown on the i - th day, the maximum profit is same as sell[i - 1] 
//! 	since we did not do anything on the i - th day.
//! 	So sell[i] is the larger one of(buy[i - 1] + price, sell[i - 1])
//! 
//! 	To calculate buy[i] :
//! 	If we buy on the i - th day, the maximum profit is sell[i - 2] - price, 
//! 		because on the(i - 1)th day we can only cooldown.
//! 	If we cooldown on the i - th day, the maximum profit is same as buy[i - 1] 
//! 		since we did not do anything on the i - th day.
//! 	So buy[i] is the larger one of(sell[i - 2] - price, buy[i - 1])
   

class Solution {
public:
	int maxProfit(vector<int>& prices) {
		if (prices.empty()) return 0;
		int n = prices.size();
		vector<int> buy(n + 1, 0);
		vector<int> sell(n + 1, 0);
		buy[1] = -prices[0];

		for (int i = 2; i <= n; ++i)
		{
			int price = prices[i - 1];
			buy[i] = max(sell[i - 2] - price, buy[i - 1]);
			sell[i] = max(buy[i - 1] + price, sell[i - 1]);
		}

		return sell[n];
	}
};



