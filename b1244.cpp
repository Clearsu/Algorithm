#include <iostream>

int main() {
	int numOfSwitches;
	std::cin >> numOfSwitches;
	std::cin.ignore();

	char switches[100];
	for (int i = 0; i < numOfSwitches; i++) {
		std::cin >> switches[i];
	}	
	std::cin.ignore();
	
	int numOfStudents;
	std::cin >> numOfStudents;
	std::cin.ignore();

	int sex;
	int num;
	int span;
	for (int i = 0; i < numOfStudents; i++) {
		std::cin >> sex;
		std::cin >> num;	
		if (sex == 1) {
			for (int j = 0; j < numOfSwitches; j++) {
				if ((j + 1) % num == 0) {
					if (switches[j] == '0') {
						switches[j] = '1';
					} else {
						switches[j] = '0';
					}
				}
			}
		} else {
			int span = 0;
			while (switches[num - 1 - span] == switches[num - 1 + span]
					&& num - 1 - span >= 0 && num - 1 + span < numOfSwitches) {
				if (switches[num - 1 - span] == '0') {
					switches[num - 1 - span] = '1';
					switches[num - 1 + span] = '1';
				} else {
					switches[num - 1 - span] = '0';
					switches[num - 1 + span] = '0';
				}
				span++;	
			}
		}
		std::cin.ignore();
	}

	for (int i = 0; i < numOfSwitches; i++) {
		std::cout << switches[i];
		std::cout << ((i + 1) % 20 == 0 ? '\n' : ' ');
	}
}