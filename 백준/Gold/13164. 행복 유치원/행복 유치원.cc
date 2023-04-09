#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(void) {
	int N, K; // 학생수, 조의 수
	cin >> N >> K;
	vector<int> n(N); // 원생들의 키
	vector<int> cost(N-1); // 옆사람과의 키 차이
	for (int i = 0; i < N; i++) {
		cin >> n[i];
		if (i >= 1) {
			cost[i - 1] = n[i] - n[i - 1]; // 옆사람과의 키 차이 저장
		}
	}
	sort(cost.begin(), cost.end()); // 오름차순 정렬
	long long result = 0;
	for (int i = 0; i < N - K; i++) { //N-K개수를 제외한 나머지 키 차이의 합
		result += cost[i];
	}
	cout << result; //최소비용
	return 0;
}
