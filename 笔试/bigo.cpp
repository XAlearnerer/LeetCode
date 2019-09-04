#include<iostream>

using namespace std;


//
//int  main()
//{
//	char *a[] = { "China","French","America","German" };
//	char **s = a;
//
//	printf("%s", *s);
//	printf("%s", a[0]);
//	printf("%s", *a);
//
//	return 0;
//}

//
//int main()
//{
//	cout << "Hello" << endl;
//	return 0;
//}




//int main()
//{
//	char a[5] = "\x78\x56\x34\x12";
//	char p = '\x30';
//	char q = '\48';
//	cout << p << " - " << q << endl;
//
//	int i = *(int*)a;
//	cout << i << endl;
//	int t = 0x78;
//	if (i == 0x12345678)
//		cout << "OK" << endl;
//	else
//		cout << i << " " << t << endl;
//
//	return 0;
//}



//class A
//{
//	int a;
//public:
//	A() : a(1) {}
//	void printf() { cout << a << endl; }
//	int& f()
//	{
//		return a;
//	}
//};
//
//int main()
//{
//	A a;
//	*(int*)&a = 10;
//	a.printf();
//
//	int *p = &a.f();
//	a.printf();
//	*p = 100;
//	a.printf();
//
//	return 0;
//}

//
//#include<stdio.h>
//unsigned int f(unsigned int value)
//{
//	unsigned int num = 0;
//	for (int i = 0; i < 4; ++i)
//	{
//		num |= value & 1;
//		num <<= 1;
//		value >>= 1;
//	}
//
//	return num;
//}
//
//
//unsigned int ReverseBit(unsigned int value)
//{
//	unsigned int answer = 0U;
//	//for (unsigned int i = 1U; i != 0; i <<= 1)
//	for (int i = 0; i < 4; ++i)
//	{
//		answer <<= 1;
//		if (value & 1)
//		{
//			answer |= 1;
//		}
//		value >>= 1;
//	}
//	return answer;
//}
//
//int main()
//{
//	unsigned int a = 8;
//	cout << f(a) << endl;
//	cout << ReverseBit(a) << endl;
//	return 0;
//}
//
//



//int main()
//{
//	int a[3][4] = { {1,2,3,4},{5,6,7,8},{9,10,11,12} };
//	//cout << (a + 1) << " " << *(*a + 1) << " " << **a + 1 << endl;
//	cout << (a + 1) << " " << *(a + 1) << " " << a[1] << endl;
//
//	return 0;
//}






