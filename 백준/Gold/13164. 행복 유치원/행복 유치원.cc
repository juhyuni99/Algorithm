#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(void) {
	int N, K;
	cin >> N >> K;
	vector<int> n(N);
	vector<int> cost(N-1);
	for (int i = 0; i < N; i++) {
		cin >> n[i];
		if (i >= 1) {
			cost[i - 1] = n[i] - n[i - 1]; // 키 차이 저장
		}
	}
	sort(cost.begin(), cost.end());
	long long result = 0;
	for (int i = 0; i < N - K; i++) {
		result += cost[i];
	}
	cout << result;
	return 0;
}