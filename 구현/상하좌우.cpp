#include <bits/stdc++.h>

using namespace std;

int n;
string plans;
int x = 1, y = 1; //현재위치

// L,R,U,D에 따른 이동 방향
int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0};
char moveTypes[4] = { 'L', 'R', 'U', 'D' };

int main(void) {

	//c++과 java에서는 정수 입력받은 뒤에 문자열을 입력받으면 꼭 버퍼 비워주기!!!
	cin >> n;
	cin.ignore();//버퍼에 있는 null문자 없애주기
	getline(cin, plans); //문자열 입력 받기

	//이동 계획을 하나씩 확인하기
	for (int i = 0; i < plans.size(); i++) {
		char plan = plans[i];
		//이동 후 좌표 구하기
		int nx = -2, ny = -2;
		for (int j = 0; j < 4; j++) {
			if (plan == moveTypes[j]) {
				nx = x + dx[j];
				ny = y + dy[j];
			}
		}
		// 공간을 벗어나는 경우 무시
		if (nx<1 || ny<1 || nx>n || ny>n)continue;
		// 이동 수행
		x = nx;
		y = ny;
	}
	cout << x << ' ' << y << '\n';
	return 0;
}
