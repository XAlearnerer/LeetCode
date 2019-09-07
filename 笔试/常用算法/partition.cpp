#include<iostream>
#include<vector>

using namespace std;

void partition(vector<int>& arr, int l, int r) {
	int less = l - 1;
	int more = r;
	while (l < more) {
		if (arr[l] < arr[r]) {
			swap(arr[++less], arr[l++]);
		}
		else if (arr[l] > arr[r]) {
			swap(arr[--more], arr[l]);
		}
		else {
			l++;
		}
	}

	swap(arr[more], arr[r]);
}

//int main()
//{
//	vector<int> v = { 2,3,9,1,36,9,6,7,22,9 };
//	partition(v, 0, v.size() - 1);
//
//	for (auto i : v)
//		cout << i << " ";
//	cout << endl;
//
//	return 0;
//}
