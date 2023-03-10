#include <bits/stdc++.h>
using namespace std;

int r_money; // 총 거스름 돈
int m_1 = 0; //  돈 종류1 5원
int m_2 = 0; // 돈 종류2 2원
int sum = 0; // 최소 동전의 개수

int main() {
	cin >> r_money; // 거스름 돈 입력
	
	if (r_money ==1 || r_money == 3) {
		cout << -1;
		return 0;
	}

	else {
		if (r_money % 5 == 0) { //5의 배수 일때
			sum = r_money / 5; // 최소 동전의 개수
			cout << sum;
		}

		else { // 5의 배수가 아닐 경우
			sum = r_money / 5;// 최소 동전의 개수
			r_money %= 5; // 나머지 거스름 돈
			if (r_money % 2 == 0) { // 나머지 거스름 돈이 짝수 일 때
				sum += r_money / 2; 
				cout << sum;
			}
			else { // 나머지 거스름 돈 홀수 일  때
				sum -= 1;
				r_money += 5;
				sum += r_money / 2;
				cout << sum;
			}
		}
		return 0;
	}
	
}
