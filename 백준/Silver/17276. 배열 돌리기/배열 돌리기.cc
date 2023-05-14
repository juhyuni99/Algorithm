#include<iostream>
#include<memory.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t_c; // 테스트 케이스
	int N, d; // 개수, 각도
	cin >> t_c;
	
	while(t_c--){
		cin >> N >> d;
		int map[501][501]; // n*n map
		int temp[501][501]; // 회전 후 map
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> map[i][j];
			}
		}
		memcpy(temp, map, sizeof(temp));
		if (d > 0) { //시계방향
			int cnt = d / 45;
			while (cnt--) {
				//대각선(왼->오)
				for (int i = 0; i < N; i++) temp[i][(N + 1) / 2 - 1] = map[i][i];
				//가운데 가로 선
				for (int i = 0; i < N; i++) temp[i][i] = map[(N + 1) / 2 - 1][i];
				//대각선(오->왼)
				for (int i = N - 1; i >= 0; i--) temp[(N + 1) / 2 - 1][N - 1 - i] = map[i][N - 1 - i];
				//가운데 세로 선
				for (int i = N - 1; i >= 0; i--) temp[i][N - 1 - i] = map[i][(N + 1) / 2 - 1];
				memcpy(map, temp, sizeof(map));
			}
		}
		else { //반시계방향
			int cnt = abs(d / 45);
			while (cnt--) {
				//대각선(왼->오)
				for (int i = 0; i < N; i++) temp[(N + 1) / 2 - 1][i] = map[i][i];
				//가운데 가로 선
				for (int i = N - 1; i >= 0; i--) temp[i][N - 1 - i] = map[(N + 1) / 2 - 1][N - 1 - i];
				//대각선(오->왼)
				for (int i = N - 1; i >= 0; i--) temp[i][(N + 1) / 2 - 1] = map[i][N - 1 - i];
				//가운데 세로 선
				for (int i = 0; i < N; i++) temp[i][i] = map[i][(N + 1) / 2 - 1];
				memcpy(map, temp, sizeof(map));
			}
		}
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cout << temp[i][j] << " ";
			}
			cout << '\n';
		}
	}
	return 0;
}