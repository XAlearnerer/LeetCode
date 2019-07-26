//#include<iostream>
//
//using namespace std;
//
//class A
//{
//public:
//	A() :b(100) {
//	}
//	int a = 10;
//	const int b = 11;
//	static const int e;
//	//int s[a];
//
//};
//
//const int A::e = 400;
//
//class B
//{
//	const int c = 20;
//	static int d;
//public:
//	//B()
//	//{
//	//	c = 200;
//	//}
//	int getc()
//	{
//		return c;
//	}
//};
//
//int B::d = 100;
//
//
//class foo {
//public:
//	foo() :i(200) {}
//private:
//	const int i = 100;//error!!!
//};
//
//
//int main()
//{
//	A q;
//	cout << q.a << " " << q.b << endl;
//
//	B p;
//	cout << p.getc() << endl;
//
//	foo f;
//	
//
//	return 0;
//}