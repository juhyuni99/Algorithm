#include <iostream>
#include <algorithm>

using namespace std;

int arr[20][20]; //오목 판
int ny, nx; //다음 위치
int dx[4] = {1,1,1,0}, dy[4] = {-1,0,1,1}; //이동 방향(위에서부터)
bool check[20][20] = { 0, }; // 위치 방문 여부 check

//오목 승리 여부 체크
void b_f(int y, int x, int y_0, int x_0, int num, int dir) {
	// 현재 좌표, 시작 좌표, 누적 갯수, 선택 방향
	check[y][x] = true;
	for (int i = 0; i < 4; i++) { // 4가지 방향 탐색
		ny = y + dy[i];
		nx = x + dx[i];
		if (ny >= 1 && ny <= 19 && nx >= 1 && nx <= 19 && !check[ny][nx] && arr[y][x] == arr[ny][nx]) {//false, 같은색 바둑알
			if (y == ny) { //가로
				if (dir == 1) {
					b_f(ny, nx, y_0, x_0, num + 1, dir);
				}
				else {
					b_f(ny, nx, y,x,2,1);
				}
			}
			else if (x == nx) { //세로
				if (dir == 2) {
					b_f(ny, nx, y_0, x_0, num + 1, dir);
				}
				else {
					b_f(ny, nx, y, x, 2, 2);
				}
			}
			else if (y - ny == 1 && nx - x == 1) { // 우상향
				if (dir == 3) {
					b_f(ny, nx, y_0, x_0, num + 1, dir);
				}
				else {
					b_f(ny, nx, y, x, 2, 3);
				}
			}
			else { // 우하향
				if (dir == 4) {
					b_f(ny, nx, y_0, x_0, num + 1, dir);
				}
				else {
					b_f(ny, nx, y, x, 2, 4);
				}
			}
		}
	}
	check[y][x] = false;
	if (num == 5) {
		//5개 이상 돌 연속이라면
		if (dir == 1) {
			if ((x > 5 && arr[y][x] == arr[y][x - 5]) || (x < 19 && arr[y][x] == arr[y][x + 1])) return;
		}
		else if (dir == 2) {
			if ((y > 5 && arr[y][x] == arr[y - 5][x]) || (y < 19 && arr[y][x] == arr[y + 1][x])) return;
		}
		else if (dir == 3) {
			if ((y < 15 && x>5 && arr[y][x] == arr[y + 5][x - 5]) || (y > 1 && x < 19 && arr[y][x] == arr[y - 1][x + 1])) return;
		}
		else if (dir == 4) {
			if ((y > 5 && x > 5 && arr[y][x] == arr[y - 5][x - 5]) || (y < 19 && x < 19 && arr[y][x] == arr[y + 1][x + 1])) return;
		}
		//오목이라면
		cout << arr[y][x] << "\n" << y_0 << " " << x_0 << "\n"; // 색상, 시작 위치
		exit(0); //강제종료
	}
}

int main() {
	//바둑판 입력
	for (int i = 1; i <= 19; i++) {
		for (int j = 1; j <= 19; j++) {
			cin >> arr[i][j];
		}
	}
	//승리 여부 함수 호출
	for (int i = 1; i <= 19; i++) {
		for (int j = 1; j <= 19; j++) {
			if ((arr[i][j] == 1 || arr[i][j] == 2) && !check[i][j]) {
				b_f(i, j, i, j, 1, 0);
			}
		}
	}
	//승리한 돌 없을 경우
	cout << 0 << "\n";
	return 0;
}
