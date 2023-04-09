/*
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
vector<vector<int>> bingo;
vector<vector<int>> ist;

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
		if (col == 5) { // one cross
			bingo1++;
		}
		if (row == 5) {
			bingo1++;
		}
		if (bingo[i][i] == 0) {  //대각선 좌->우
			crossR++;
		}
		if (bingo[i][5-1-i] == 0) { // 대각선 우->좌
			crossL++;
		}
	}
	if (crossR == 5) { // 좌대각선 빙고
		bingo1++;
	}
	if (crossL == 5) { // 우대각선 빙고
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
			cin >> bingo[i][j];
		}
	}
	int ans = 0;
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			ans++;
			int number;
			cin >> number;
			if (bingo[i][j] == number) {
				bingo[i][j] = 0;
			}
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
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int N;
	cin>>N;
	int sum = 0;
	int cntmax = 0;
	int val = 0;
	vector<int> n(N); // 값을 저장할 벡터
	vector<int> cnt(8001);//최빈값을 계산할 벡터
	for (int i = 0; i < N; i++) {
		cin >> n[i];
		sum += n[i];
		cnt[n[i] + 4000]++;
	}
	sort(n.begin(), n.end());
	//최빈값 중 가장 작은 값
	for (int i = 0; i <= 8000; ++i) {
		if (cnt[i] > cntmax) {
			cntmax = cnt[i];
			val = i;
		}
	}

	//두번쨰로 작은 최빈값
	for (int i = val + 1; i <= 8000; ++i) {
		if (cnt[i] == cntmax) {
			val = i;
			break;
		}
	}
	sum = round(double(sum) / N);
	cout << sum <<"\n";
	cout << n[(N-1)/2]<<"\n";
	cout << val - 4000 << "\n";
	cout << n[N-1]-n[0];
}