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
	
	for (int i = 0; i < n; i++) {	//합과 vector안에 원소를 집어넣는과정
		cin >> inPut;
		v.push_back(inPut);
		sum += inPut;
	}
	
	arithmetic_mean = (double)sum / (double)n;	//산술평균 구하는 과정
	if (arithmetic_mean > 0)	//반올림
		arithmetic_mean += 0.5;
	else
		arithmetic_mean -= 0.5;

	sort(v.begin(), v.end());	//정렬
	
	middle = v.at((n - (n / 2)) - 1);	//정렬 후 중앙값

	for (int i = 0; i < v.size(); i++)	//각 인덱스가 숫자를 의미함
		count_mode[v[i] + 4000]++;
	for (int i = 0; i <= 8000; i++)
		max = max > count_mode[i] ? max : count_mode[i];
	for (int i = 0; i <= 8000; i++) {
		if (count_mode[i] == max) {
			mode_save.push_back(i - 4000);	//각 인덱스를 vector에 집어넣음
		}
	}

	sort(mode_save.begin(), mode_save.end());	//혹시 최빈값이 중복일때를 위해!

	if (mode_save.size() == 1)	//벡터의 원소가 1개면 front
		mode = mode_save.front();
	else	//벡터의 원소가 2개 이상일때 2번째로 작은 숫자
		mode = mode_save.at(1);


	range = *max_element(v.begin(), v.end()) - *min_element(v.begin(), v.end());	//백터의 최대와 최소의 차

	cout << (int)arithmetic_mean << "\n" << middle << "\n" << mode << "\n" << range;

	system("pause");
	return 0;
}
