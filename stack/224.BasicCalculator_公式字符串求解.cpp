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