#include <iostream>
#include <algorithm>

using namespace std;

struct POINT {
	int x;
	int y;
};

bool cmp(const POINT &a, const POINT &b) {
	if (a.x == b.x) {
		return a.y < b.y;
	}
	return a.x < b.x;
}


int main(void) {
	ios::sync_with_stdio(false);
	POINT xy[100000];
	int count;
	cin >> count;
	for (int i = 0; i < count; i++) {
		cin >> xy[i].x >> xy[i].y;
	}
	sort(xy, xy + count, cmp);	//여기 cmp쓴게 핵심인거 같아염
	for (int i = 0; i < count; i++) {
		cout << xy[i].x << " " << xy[i].y << "\n";
	}
	return 0;
}