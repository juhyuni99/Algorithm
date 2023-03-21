#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;
double N; // 운동기구 개수
int main(void) {
	long long M_MAX = 0; // M의 최댓값
	cin >> N;
	vector<long long> t(N);

	for (long unsigned int i = 0; i < t.size(); i++) { //근손실 정도 입력
		cin >> t[i];
	}
	sort(t.begin(), t.end()); // 오름차순 정렬
	long long r = round(N / 2);
	vector<long long> M(r);

	for (long unsigned int i = 0; i < M.size(); i++) {
		// M 최솟값 구하기 (가장 큰 값만 빼고 나머지 큰값 + 작은값 더하기)
		//홀수일때
		if (int(N) % 2 != 0) {
			if (i == r - 1) {
				M[i] = t[N - 1];
			}
			else {
				M[i] = t[i] + t[N - i - 2];
			}
			M_MAX = max(M_MAX, M[i]);
		}
		
		//짝수일때
		else {
			M[i] = t[i] + t[N - i - 1];
			M_MAX = max(M_MAX, M[i]);
		}
	}
	cout << M_MAX;
	return 0;
}