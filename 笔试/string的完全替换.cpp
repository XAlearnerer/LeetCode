#include<iostream>
#include<string>

using namespace std;


void f(string& strBase, string strSrc, string strDes)
{
	string::size_type pos = 0;
	string::size_type srclen = strSrc.size();
	string::size_type deslen = strDes.size();
	pos = strBase.find(strSrc, pos);
	while (pos != string::npos)
	{
		strBase.replace(pos, srclen, strDes);
		pos = strBase.find(strSrc, (pos, deslen));
	}

}


//int main()
//{
//	string s = "12345677890987765544";
//	f(s, "77", "ABC");
//	cout << s << endl;
//
//	return 0;
//}
