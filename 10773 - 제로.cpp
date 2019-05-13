#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	int many, n;
	int sum = 0;
	cin >> many;
	stack<int> s;
	for (int i = 0; i < many; i++) {
		cin >> n;
		if (n == 0)
			s.pop();
		else
			s.push(n);
	}
	while (!s.empty()) {
		sum += s.top();
		s.pop();
	}
	cout << sum;

	return 0;
}