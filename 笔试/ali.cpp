
#include<iostream>
using namespace std;

//int cnt;
//char arr[1005] = { 'a','A','b','B','c','C','d','D','e','E','f','F','g','G','h','H',
//'i','I','j','J','k','K','l','L','m','M','n','N' };
//void Merge(char* arr, char* tmp, int left, int right, int rightEnd) {
//	int leftEnd = right - 1;
//	int start = left;
//	while (left <= leftEnd && right <= rightEnd) {
//		if (arr[left] > arr[right]) {
//			tmp[start++] = arr[right++];
//			cnt += (leftEnd - left + 1); //�����ǰleftλ���ϵ�������rightλ���ϵ�������ô��left��leftEnd���е���������
//		}
//		else {
//			tmp[start++] = arr[left++];
//		}
//	}
//	while (left <= leftEnd) {
//		tmp[start++] = arr[left++];
//	}
//	while (right <= rightEnd) {
//		tmp[start++] = arr[right++];
//	}
//}
//void MergeSort(char* arr, char* tmp, int n, int length)//length��ǰ�������еĳ���
//{
//	int i;
//	for (i = 0; i <= n - 2 * length; i += 2 * length) {
//		Merge(arr, tmp, i, i + length, i + 2 * length - 1);
//	}
//	//���ʣ���������У����й鲢
//	if (i + length < n) {
//		Merge(arr, tmp, i, i + length, n - 1);
//	}
//	else {//ֻʣ���һ�����У����ܳɶ�
//		for (int j = i; j < n; j++) {
//			tmp[j] = arr[j];
//		}
//	}
//}
//void Merge_Sort(char* arr, int n) {
//	int lenght = 1;
//	char* tmp = (char *)malloc(sizeof(char)*n);
//	while (lenght < n) {
//		MergeSort(arr, tmp, n, lenght);
//		lenght *= 2;
//		MergeSort(tmp, arr, n, lenght);
//		lenght *= 2;
//	}
//	free(tmp);
//}
//int main()
//{
//	int n;
//	/*while (scanf("%d", &n) != EOF) {
//		memset(arr, 0, sizeof(arr));
//		for (int i = 0; i<n; i++) {
//			scanf("%d", &arr[i]);
//		}
//		cnt = 0;
//		Merge_Sort(arr, n);
//		printf("%d\n", cnt);
//	}*/
//	cnt = 0;
//	n = 28;
//	Merge_Sort(arr, n);
//	printf("%d\n", cnt);
//
//	return 0;
//}



//int main()
//{
//	char b[1024] = { 111 };
//	cout << b[1] << endl;
//	int i = *(int*)b;
//	cout << i << endl;
//
//
//	return 0;
//}