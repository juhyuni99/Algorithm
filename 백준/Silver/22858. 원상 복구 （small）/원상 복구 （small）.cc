#include <iostream>
#include <memory.h>
using namespace std;
int D[10001], S[100001], P[1000001];

int main() {
	int n, k; // 카드 개수, 섞은 횟수
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> S[i];
	}
	for (int i = 1; i <= n; i++) {
		cin >> D[i];
	}
	while (k--) {
		for (int i = 1; i <= n; i++) {
			P[D[i]] = S[i];
		}
		memcpy(S, P, sizeof(S));
	}
	
	for (int i = 1; i <= n; i++) {
		cout << P[i] << " ";
	}
	return 0;
}