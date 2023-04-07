#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;



int main(void) {
	int cost;
	int cost1 = 0;
	int cost2 = 0; // 준현, 성민 현금
	int result1 = 0; // 준현, 성민 보유주식수
	int result2 = 0; 
	int cnt1 = 0;// 3일 연속 하락 check
	int cnt2 = 0;// 3일 연속 상승 check
	cin >> cost;
	cost1 = cost;
	cost2 = cost;
	vector<int> juga(cost); // 주가
	bool flag = false;
	for (int i = 0; i < 14; i++) {
		cin >> juga[i];
		if (juga[i] <= cost1) { //준현
			result1 += cost1 / juga[i]; // 보유 주식 수
			cost1 %= juga[i];
		}
		if (juga[i] <= cost2) { //성민
			if (i >= 1 && juga[i] < juga[i - 1]) { //3일 연속 하락
				cnt1+=1;
			}
			else cnt1 = 0;
			if (cnt1 >= 3) { // 매수
				result2 += cost2 / juga[i];
				cost2 %= juga[i];
			}
			if (i >= 1 && juga[i] > juga[i - 1]) { //3일 연속 상승
				cnt2+=1;
			}
			else cnt2 = 0;
			if (cnt2 >= 3) { // 매도
				cost2 = result2 * juga[i];
				result2 = 0;
			}
		}
	}

	if (cost1 + juga[13] * result1 > cost2 + juga[13] * result2) {
		cout << "BNP";
	}
	else if (cost1 + juga[13] * result1 < cost2 + juga[13] * result2) {
		cout << "TIMING";
	}
	else {
		cout << "SAMESAME";
	}
	
}

