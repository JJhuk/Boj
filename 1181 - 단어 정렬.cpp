#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool cnt(const string &a, const string &b) {
	if (a.length() == b.length()) {	//���̰� �������
		return a < b;	//�׳� sorting
	}
	else
		return a.length() < b.length();
}

int main(void) {
	ios::sync_with_stdio(false);
	string str[20000];
	int count;
	cin >> count;
	for (int i = 0; i < count; i++) {
		cin >> str[i];
	}
	sort(str, str + count, cnt);
	for (int i = 0; i < count; i++) {
		if (str[i] != str[i + 1])	//�ߺ� ����
			cout << str[i] << "\n";
	}
	return 0;
}