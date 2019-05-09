#include <iostream>
#include <stack>
#include <algorithm>
#include <string>

using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	int inPut;
	int div_5, Max_div_3;
	int div_3;
	int count = 0;
	int temp;
	bool isDone = false;
	cin >> inPut;
	temp = inPut;
	div_5 = inPut / 5;
	Max_div_3 = inPut / 3;
	div_3 = 1;
	while (!isDone) {
		if (div_5 == 0) {
			if (div_3*3 == temp)
			{
				count = div_3;
				isDone = true;
			}
			else {
				if (div_3 + 1 <= Max_div_3) {
					div_3++;
				}
				else { 
						isDone = true;
						count = -1;
				}
			}
		}
		else if (div_5*5 == temp) {
			count = div_5;
			isDone = true;
		}
		else if (((div_5*5)+(div_3*3))==temp) {
			count = div_5 + div_3;
			isDone = true;
		}
		else
		{
			if (div_3 + 1 <= Max_div_3) {
				div_3++;
			}
			else {  //max주머니보다 클 경우 
				div_5--;
				div_3 = 1;
				if (div_5 < 0) {
					isDone = true;
					count = -1;
				}
			}
		}
	}

	cout << count;
	system("pause");
	return 0;
}