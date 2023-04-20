#include <iostream>
#include <algorithm>

using namespace std;
int swch[101]; //스위치 상태
int chil; // 학생 수
int n; //스위치 개수

//남학생
void boy(int num) {
	//받은 수의 배수 부분의 스위치 상태를 바꿔줌
	for (int i = 1; i * num <= n; i++) {
		swch[num*i] = !swch[num*i];
	}
}

//여학생
void girl(int num) {
	swch[num] = !swch[num]; // 받은 수 먼저 상태를 바꿔 줌.
	//범위 주의
	for (int i = 1; num - i >= 1 && num + i <= n; i++) {
		//받은 수를 기준으로 양옆의 스위치 상태가 같으면 상태를 바꿔줌
		if (swch[num - i] == swch[num + i]) {
			swch[num - i] = !swch[num - i];
			swch[num + i] = !swch[num + i];
		}
		//스위치 상태가 다르면 for문 탈출
		else break;
	}
}

int main(void) {
	
	cin >> n; 
	for (int i = 1; i <= n; i++) { // 스위치 번호 시작 1번부터
		cin >> swch[i]; // 스위치 상태
	}
	cin >> chil;  
	for (int i = 0; i < chil; i++) {
		int gender, num; // 학생 성별, 학생이 받은 수 
		cin >> gender >> num;
		if (gender == 1) { // 남학생
			boy(num); //함수 호출
		}
		else if (gender == 2) { //여학생
			girl(num); //함수 호출
		}
	}

	//스위치 상태 출력
	for (int i = 1; i <= n; i++) {
		cout << swch[i] << " ";
		if (i % 20 == 0) { // 한줄에 20개씩 출력, 개행
			cout << '\n';
		}
	}
}
