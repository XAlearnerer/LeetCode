//#include <iostream>
//#include <ctime>
//#include <cstdlib>
//
//using namespace std;
//
//class solution
//{
//public:
//	solution() {}
//	~solution() {}
//
//	void testAlgorithm() {    //��Ҫ���Ե��㷨a
//
//	}
//
//	void comparator(int arr[]) {     //��ȫ��ȷ���㷨b���õ���ð������ʱ�临�Ӷ�Ϊo(n^2)���ռ临�Ӷ�Ϊo(1)
//		int size = computeLengthOfArr(arr);
//		if (arr == NULL || size < 2) {
//			return;
//		}
//		for (int i = size - 1; i >= 0; i--) {
//			for (int j = 0; j < i; j++) {
//				if (arr[j] > arr[j + 1]) {
//					swap(arr[j], arr[j + 1]);
//				}
//			}
//		}
//	}
//
//	void swap(int i, int j) {
//		int tmp = i;
//		i = j;
//		j = tmp;
//	}
//
//	int computeLengthOfArr(int arr[]) {   //�������鳤��
//		if (arr == NULL) {
//			return 0;
//		}
//		return sizeof(arr) / sizeof(arr[0]);
//	}
//
//	int* generateRandomArr(int maxSize, int maxValue) { //�����������
//		int size = rand() % maxSize + 1;
//		int *arr = new int[size];        //��ʼ����������
//		for (int i = 0; i < size; i++) {
//			arr[i] = rand() % maxValue + 1;
//		}
//		return arr;
//	}
//
//	int* copyArr(int arr[]) {         //����һ����ȫһ��������
//		if (arr == NULL) {
//			return;
//		}
//		int size = computeLengthOfArr(arr);
//		int* copy = new int[size];
//		for (int i = 0; i < size; i++) {
//			copy[i] = arr[i];
//		}
//		return copy;
//	}
//
//	bool isEqual(int arr1[], int arr2[]) {    //��������ĶԱȣ��������㷨������������жԱȣ��Ƿ�һ��
//		if ((arr1 != NULL && arr2 == NULL) || (arr1 == NULL && arr2 != NULL)) {
//			return false;
//		}
//		if (arr1 == NULL && arr2 == NULL) {
//			return true;
//		}
//		int size1 = computeLengthOfArr(arr1);
//		int size2 = computeLengthOfArr(arr2);
//		if (size1 != size2) {
//			return false;
//		}
//		for (int i = 0; i < size1; ++i) {
//			if (arr1[i] != arr2[i]) {
//				return false;
//			}
//		}
//		return true;
//	}
//
//	void printArr(int arr[]) {  //��ӡ����
//		if (arr == NULL) {
//			return;
//		}
//		int size = computeLengthOfArr(arr);
//		for (int i = 0; i < size; i++) {
//			cout << arr[i] << ',';
//		}
//	}
//
//	void logarithm() {
//		int testTime = 100000;
//		int maxSize = 10;
//		int maxValue = 50;
//		bool succed = true;
//		for (int i = 0; i < testTime; i++) {
//			int arr1[] = generateRandomArr(maxSize, maxValue);
//			int arr2[] = copyArr(arr1);
//			testAlgorithm(arr1);
//			comparator(arr2);
//			if (!isEqual(arr1, arr2)) {
//				succed = false;
//				break;
//			}
//		}
//		cout << succed ? "Nice!" : "Fucking! Error!" << endl;
//	}
//
//
//
//};