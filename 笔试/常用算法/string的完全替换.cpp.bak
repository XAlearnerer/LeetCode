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
		pos = strBase.find(strSrc, (pos + deslen));
	}

}


void g(string& s, string a, string b)
{
	int len1 = a.size(), len2 = b.size();
	int pos = 0;
	pos = s.find(a, pos);
	while (pos != string::npos)
	{
		s.replace(pos, len1, b);
		pos = s.find(a, pos + len1);
	}


}



//int main()
//{
//	string s = "12345677890987765544";
//	//f(s, "77", "ABC");
//	g(s, "77", "ABC");
//	cout << s << endl;
//
//	return 0;
//}


