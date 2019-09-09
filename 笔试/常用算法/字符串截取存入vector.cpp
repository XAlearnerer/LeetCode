
#include<iostream>
#include<string>
#include<vector>

using namespace std;


//void splitstring(const string& s, vector<string>& v, const string& c) {
//	string::size_type pos1, pos2;
//	pos2 = s.find(c);
//	pos1 = 0;
//	while (string::npos != pos2)
//	{
//		v.push_back(s.substr(pos1, pos2 - pos1));
//		pos1 = pos2 + c.size();
//		pos2 = s.find(c, pos1);
//	}
//	if (pos1 != s.length())
//		v.push_back(s.substr(pos1));
//}

void splitstring(const string& s, vector<string>& v, const string& c) {
	int pos1, pos2;
	pos2 = s.find(c);
	pos1 = 0;
	while (string::npos != pos2)
	{
		v.push_back(s.substr(pos1, pos2 - pos1));
		pos1 = pos2 + c.size();
		pos2 = s.find(c, pos1);
	}
	if (pos1 != s.length())
		v.push_back(s.substr(pos1));
}



void helper(string& s, vector<string>& v, string f)
{
	int pos1 = 0, pos2 = s.find(f);
	while (pos2 != string::npos)
	{
		v.push_back(s.substr(pos1, pos2 - pos1));
		pos1 = pos2 + f.size();
		pos2 = s.find(f, pos1);
	}
	
	v.push_back(s.substr(pos1));
}







//int main()
//{
//	vector<string> v;
//	string s = "1234&567890&98765&4321";
//	//splitstring(s, v, "&");
//	helper(s, v, "&");
//	for (auto i : v)
//		cout << i << ends;
//	cout << endl;
//
//	return 0;
//}


