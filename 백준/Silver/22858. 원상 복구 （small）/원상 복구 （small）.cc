#include <iostream>
#include <memory.h>
using namespace std;
// i번째로 가지고 오기, K번 카드를 섞은 후 카드 배치, 원래 카드의 배치
int D[10001], S[100001], P[1000001];

int main() {
	int n, k; // 카드 개수, 섞은 횟수
	cin >> n >> k;
	for (int i = 1; i <= n; i++) { 
		cin >> S[i];// K번 카드를 섞은 후 카드 배치
	}
	for (int i = 1; i <= n; i++) {
		cin >> D[i];// i번째로 가지고 오기
	}
	while (k--) {//카드 섞은 횟수 만큼 반복
		for (int i = 1; i <= n; i++) {
			P[D[i]] = S[i]; // 한 번 섞었을 때의 결과
		}
		memcpy(S, P, sizeof(S));//S에 K 메모리 복사
	}
	
	for (int i = 1; i <= n; i++) {
		cout << P[i] << " "; // 원래 카드의 배치 출력
	}
	return 0;
}
