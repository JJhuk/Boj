#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	int count_mode[8001] = { 0 };	//index 0 ~ 3999까지는 -4000~-1 //index 4000은 0 //index 40001~ 8000은 1~4000
	int find_secondmin[8001] = { 0 };
	int n;
	int inPut;
	cin >> n;
	double arithmetic_mean; //산술평균 - N개의 수들의 합을 n으로 나눈 값
	double middle;	//중앙값 - n개의 수들을 증가하는 순서로 나열했을 경우 그 중앙에 위치하는 값
	double mode; //최빈값 - n개의 수들 중 가장 많이 나타나는 값
	double range; // 범위 - n개의 수들 중 최댓값과 최솟값의 차이
	int sum = 0;
	int max = 0;
	int count = 0;
	vector<int> v;
	vector<int> mode_save;
	for (int i = 0; i < n; i++) {
		cin >> inPut;
		v.push_back(inPut);
		sum += inPut;
	}
	arithmetic_mean = (double)sum / (double)n;
	if (arithmetic_mean > 0)
		arithmetic_mean += 0.5;
	else
		arithmetic_mean -= 0.5;

	sort(v.begin(), v.end());
	middle = v.at((n - (n / 2)) - 1);

	for (int i = 0; i < v.size(); i++)
		count_mode[v[i] + 4000]++;
	for (int i = 0; i <= 8000; i++)
		max = max > count_mode[i] ? max : count_mode[i];
	for (int i = 0; i <= 8000; i++) {
		if (count_mode[i] == max) {
			mode_save.push_back(i - 4000);
		}
	}

	sort(mode_save.begin(), mode_save.end());

	if (mode_save.size() == 1)
		mode = mode_save.front();
	else
		mode = mode_save.at(1);


	range = *max_element(v.begin(), v.end()) - *min_element(v.begin(), v.end());

	cout << (int)arithmetic_mean << "\n" << middle << "\n" << mode << "\n" << range;

	system("pause");
	return 0;
}
