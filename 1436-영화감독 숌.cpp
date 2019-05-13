#include <iostream>
#include <string>
#include <algorithm>
#include <deque>

using namespace std;



int main(void) {
	ios::sync_with_stdio(false);
	int n;
	int start = 666;
	cin >> n;
	string str;
	int count = 1;
		while (count!=n) {
			start++;
			str = to_string(start);
			for (int i = 0; i < str.length()-2; i++) {
				if (str[i] == '6'&&str[i + 1] == '6' && str[i+2] == '6') {
					count++;
					break;
				}
			}
		}
	cout << start;

	

	system("pause");
	return 0;
}