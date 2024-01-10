#include <iostream>
using namespace std;

int n;
int arr[1000000];
int res[1000000];

void merge(int start, int mid, int end) {
	int i = start, j = mid + 1, k = start;
	while (i <= mid && j <= end) {
		res[k++] = arr[i] < arr[j] ? arr[i++] : arr[j++];
	}
	while (i <= mid) {
		res[k++] = arr[i++];
	}
	while (j <= end) {
		res[k++] = arr[j++];
	}
	if (start == 0 && end == n - 1) {
		return ;
	}
	while (start <= end) {
		arr[start] = res[start];
		start++;
	}
}

void mergeSort(int start, int end) {
	if (start == end) {
		return ;
	}
	int mid = (start + end) / 2;
	mergeSort(start, mid);
	mergeSort(mid + 1, end);
	merge(start, mid, end);
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];	
	}

	if (n == 1) {
		cout << arr[0] << '\n';
		return 0;
	}

	mergeSort(0, n - 1);

	for (int i = 0; i < n; i++) {
		cout << res[i] << '\n';
	}
}