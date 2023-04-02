#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
	int N;//회의의 수
	cin >> N;
	int start, end;//회의 시작시간, 회의 종료시간
	vector<pair<int, int>> inf; // 회의 정보(2개의 값 쌍으로 저장)

	for (int i = 0; i < N; i++) {
		cin >> start >> end;
		inf.push_back(make_pair(end, start));
	}
	sort(inf.begin(), inf.end()); // 오름차순 정렬

	int time = inf[0].first;
	int cnt = 1;
	for (int i = 1; i < N; i++){
		if (inf[i].second>=time) {
			cnt++;
			time = inf[i].first;
		}
	}
	cout << cnt;
}