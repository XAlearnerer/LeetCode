#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>

using namespace std;

class solution
{
public:
	solution() {}
	~solution() {}

	void testAlgorithm(vector<int>& v) {    //��Ҫ���Ե��㷨a

	}

	void comparator(vector<int>& v) {     //��ȫ��ȷ���㷨b
	
	}

	//void swap(int i, int j) {
	//	int tmp = i;
	//	i = j;
	//	j = tmp;
	//}

	//int computeLengthOfArr(int arr[]) {   //�������鳤��
	//	if (arr == NULL) {
	//		return 0;
	//	}
	//	return sizeof(arr) / sizeof(arr[0]);
	//}

	vector<int> generateRandomArr(int maxSize, int maxValue) { //�����������
		int size = rand() % maxSize + 1;
		//int *arr = new int[size];        //��ʼ����������
		vector<int> arr(size);
		for (int i = 0; i < size; i++) {
			arr[i] = rand() % maxValue + 1;
		}
		return arr;
	}

	vector<int> copyArr(vector<int> arr) {         //����һ����ȫһ��������
		if (arr.empty()) {
			return;
		}
		//int size = computeLengthOfArr(arr);
		int size = arr.size();
		//int* copy = new int[size];
		vector<int> copy(size);
		for (int i = 0; i < size; i++) {
			copy[i] = arr[i];
		}
		return copy;
	}

	bool isEqual(vector<int> arr1, vector<int> arr2) {    //��������ĶԱȣ��������㷨������������жԱȣ��Ƿ�һ��
		if ((arr1.empty() && arr2.empty()) || (arr1.empty() && arr2.empty())) {
			return false;
		}
		if (arr1.empty() && arr2.empty()) {
			return true;
		}
		/*int size1 = computeLengthOfArr(arr1);
		int size2 = computeLengthOfArr(arr2);*/

		int size1 = arr1.size();
		int size2 = arr2.size();

		if (size1 != size2) {
			return false;
		}
		for (int i = 0; i < size1; ++i) {
			if (arr1[i] != arr2[i]) {
				return false;
			}
		}
		return true;
	}

	void printArr(vector<int> arr) {  //��ӡ����
		if (arr.empty()) {
			return;
		}
		//int size = computeLengthOfArr(arr);
		int size = arr.size();
		for (int i = 0; i < size; i++) {
			cout << arr[i] << ',';
		}
	}

	void logarithm() {
		int testTime = 100000;
		int maxSize = 10;
		int maxValue = 50;
		bool succed = true;
		for (int i = 0; i < testTime; i++) {
			vector<int> arr1 = generateRandomArr(maxSize, maxValue);
			vector<int> arr2 = copyArr(arr1);

			testAlgorithm(arr1);
			comparator(arr2);
			
			if (!isEqual(arr1, arr2)) {
				succed = false;

				printArr(arr1);

				break;
			}
		}
		//cout << succed ? "Nice!" : "Fucking! Error!" << endl;
	}

};
