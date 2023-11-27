#include <iostream>

double getSlope(double x1, double y1, double x2, double y2) {
	return (y2 - y1) / (x2 - x1);
}

double getYIntercept(double slope, double x, double y) {
	return y - slope * x;
}

int main() {
	int n;
	double arr[50];

	std::cin >> n;
	std::cin.ignore();
	for (int i = 0; i < n; i++) {
		std::cin >> arr[i];
	}

	if (n == 1) {
		std::cout << "0\n";
		return 0;
	}

	double slope, yIntercept;
	double count;
	double maxCount = 0;

	for (int i = 0; i < n; i++) {
		if (i == 0 || i == n - 1) {
			count = 1;
		} else {
			count = 2;
		}
		for (int j = i - 2; j >= 0; j--) {
			slope = getSlope(j, arr[j], i, arr[i]);
			yIntercept = getYIntercept(slope, i, arr[i]);
			int k;
			for (k = i - 1; k > j; k--) {
				if (arr[k] >= slope * double(k) + yIntercept) {
					break ;
				}
			}
			if (k == j) {
				count++;
			}
		}
		for (int j = i + 2; j < n; j++) {
			slope = getSlope(i, arr[i], j, arr[j]);
			yIntercept = getYIntercept(slope, i, arr[i]);
			int k;
			for (k = i + 1; k < j; k++) {
				if (arr[k] >= slope * double(k) + yIntercept) {
					break ;
				}
			}
			if (k == j) {
				count++;
			}
		}
		if (count > maxCount) {
			maxCount = count;
		}
	}

	std::cout << maxCount << '\n';

	return 0;
}