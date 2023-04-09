#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int bingo[6][6];//2차원 배열 빙고판
pair<int, int> num[26];

bool check(){
	int bingo1 = 0; // 몇 줄 그어졌는지 count
	int crossR = 0; //대각선 빙고 좌->우
	int crossL = 0; // 대각선 빙고 우->좌

	for (int i = 0; i < 5; i++) { // 빙고판과 사회자가 부른 수 동일 여부 확인
		int col = 0;
		int row = 0;
		for (int j = 0; j < 5; j++) {
			if (bingo[i][j] == 0) { //가로
				row++;
			}
			if (bingo[j][i] == 0) { //세로
				col++;
			}
		}
		if (col == 5) { // 열 one line
			bingo1++;
		}
		if (row == 5) { // 행 one line
			bingo1++;
		}
		if (bingo[i][i] == 0) {  //대각선 좌->우 
			crossR++;
		}
		if (bingo[i][5-1-i] == 0) { // 대각선 우->좌 
			crossL++;
		}
	}
	if (crossR == 5) { // 좌대각선 one line
		bingo1++;
	}
	if (crossL == 5) { // 우대각선 one line
		bingo1++;
	}
	if (bingo1 >= 3) { // 3줄 이상이면 빙고
		return true;
	}
	return false;
}

int main() {
	//C++의 입출력 성능 개선
	//입출력 버퍼를 동기화하지 않도록 설정 
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			cin >> bingo[i][j]; //빙고판 입력
			num[bingo[i][j]] = { i, j }; // 빙고판 수와 위치 저장

		}
	}
	int ans = 0; //사회자가 부른 회수 cnt
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			ans++;
			int number; //사회자가 부른 수
			cin >> number;
			bingo[num[number].first][num[number].second] = 0; // 사회자가 부른 수를 빙고판에서 찾고 값을 0으로 바꿔주기
			if (i > 1) {
				if (check()) {
					cout << ans;
					return 0;
				}
			}
		}
	}
	return 0;
}