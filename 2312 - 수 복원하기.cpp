#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	int test_case;
	int inPut,temp;
	cin >> test_case;
	for (int i = 0; i < test_case; i++) {
		int result[100001] = { 0 };
		cin >> inPut;
		temp = inPut;
		for (int j = 2; j <= inPut; j++) {
			if (inPut%j == 0 && inPut >= j) {
				inPut /= j;
				result[j]++;
				j -= 1;
			}
		}
		for (int k = 2; k <= temp; k++) {
			if (result[k] != 0) {
				cout << k << " " << result[k] << "\n";
			}
		}
	}


	system("pause");
	return 0;
}