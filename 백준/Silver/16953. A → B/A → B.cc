#include <iostream>
#include <algorithm>

using namespace std;
int A, B;

int main(void) {
	cin >> A;
	cin >> B;
	int cnt = 0; // 필요한 연산의 최솟값

	while (B > A) {
		if (B % 2 == 0) // 2의 배수
			B = B / 2;
		else if (B % 10 == 1) //일의 자리수 없애기
			B = B / 10;
		else  // 이외에 수는 while문 빠져나감
			break; 
		cnt++;
	}
	if (B == A) // 값이 같으면 cnt값에 +1 하여 출력
		cout << cnt + 1;
	else // 만들 수 없는 경우 -1 출력
		cout << "-1"; 
	return 0;
}
