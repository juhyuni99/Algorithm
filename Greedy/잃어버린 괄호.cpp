https://www.acmicpc.net/problem/1541

#include <bits/stdc++.h>
using namespace std;

int len, tmp;
int sum = 0;
bool flag; // '-'가 있는지 확인
char str[51]; //길이 최대 50 + null값 크기의 식

int main(void) {
	cin >> str;
	len = strlen(str); //식의 길이

	for (int i = 0; i <= len; i++) { // 식의 길이만큼
		if (str[i] == '+' || str[i] == '-' || i == len) { // '+','-'가 등장했거나 혹은 수식의 끝일때
			if (flag == false){ //'-' 이전 모든 값 양수화
				sum += tmp;
				tmp = 0;
			}
			else // (flag == true), '-' 이후로 모든 값 음수화
			{
				sum -= tmp;
				tmp = 0;
			}

			if (str[i] == '-') flag = true; // '-'등장 시 체크

		}
		else // tmp변수에 값 누적
		{
			tmp *= 10;
			tmp += str[i] - '0'; // char 데이터를 정수로 변환
		}
	}

	cout << sum;

}
