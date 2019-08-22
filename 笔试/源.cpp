#include <vector>
#include <numeric>
#include <functional>
#include <iostream>


using namespace std;

int main()
{
	vector<int> v = { 1,2,3,4,5 };
	v[0] = accumulate(v.begin(), v.end(), 0);
	for (auto i : v)
		cout << i << " ";
	cout << endl;

	return 0;
}
