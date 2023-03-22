#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;
double N; // 운동기구 개수

int main(void) {
	long long T_MAX = 0; // T의 최댓값
	cin >> N;
	vector<long long> t(N); // 근손실 정도

	for (long unsigned int i = 0; i < t.size(); i++) { //근손실 정도 입력
		cin >> t[i];
	}
	sort(t.begin(), t.end()); // 오름차순 정렬
	long long r = round(N / 2); // 몇개의 쌍으로 묶이는지
	vector<long long> T(r); //0으로 초기화된 vcetor r개 생성

	for (long unsigned int i = 0; i < T.size(); i++) { // T 최댓값 구하기 (쌍을 만들어서 더해주기)
		//홀수일 때
		if (int(N) % 2 != 0) {
			if (i == r - 1) { // 오른쪽 끝에 있는 제일 큰 값
				T[i] = t[N - 1];
			}
			else {
				T[i] = t[i] + t[N - i - 2];
			}
			T_MAX = max(T_MAX, T[i]); // 제일 큰 T값 구하기
		}
		
		//짝수일 때
		else {
			T[i] = t[i] + t[N - i - 1];
			T_MAX = max(T_MAX, T[i]); // 제일 큰 T값 구하기
		}
	}

	cout << T_MAX; // T의 최댓값
	return 0;
}
