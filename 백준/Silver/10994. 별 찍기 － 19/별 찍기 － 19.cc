#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <string>
using namespace std;

char arr[397][397]; // n의 최댓값 4n-3 = 4*100-3 = 397
void draw(int len, int row, int col) { // len = 4n-3
	for (int i = 0; i < len; i++) {
		if (i == 0 || i == len - 1) { // 윗 변, 아랫 변
			for (int j = 0; j < len; j++) {
				arr[row + i][col + j] = '*';
			}
		}
		else { //높이 : 별 두개 찍기
			arr[row + i][col] = '*'; //첫번째 열
			arr[row + i][col + len - 1] = '*'; // 마지막 열
		}
	}
}

void square(int N, int row, int col) {
	int len = 4 * N - 3;
	draw(len, row, col); // 재귀 전에 현재 지점의 사각형 먼저 그리기
// n이 1이면 별 1개, 더 작은 크기의 사각형을 그릴 필요가 없음
//따라서, 이 경우에는 재귀 호출을 중단하고 함수를 빠져나와야 함
	if (N == 1) { 
		return;
	}
	square(N - 1, row + 2, col + 2); // 다음 미니 사각형 만들 때 다음 재귀 시작 지점 인수로 넘겨주기
}

int main(void) {
	int n; //숫자
	cin >> n;

	//별 찍기 전에 미리 전체 배열에 공백 넣어주기
	for (int i = 0; i < 4*n-3; i++) {
		for (int j = 0; j < 4 * n - 3; j++) {
			arr[i][j] = ' ';
		}

	}
	square(n, 0, 0); // 별 찍기. 가장 큰 사각형부터. 시작점은 좌상단.

	//출력
	for (int i = 0; i < 4 * n - 3; i++) {
		for (int j = 0; j < 4 * n - 3; j++) {
			cout << arr[i][j];
		}
		cout << '\n';
	}
	return 0;
}
