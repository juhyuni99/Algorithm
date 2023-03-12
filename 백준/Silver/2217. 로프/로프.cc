#include <bits/stdc++.h>
using namespace std;

int n; // 로프 개수
int W_max; // 최대 중량

int main() {

	cin >> n;
	vector <int> rope_W(n);
	for (int i = 0; i < n; i++) {
		cin >> rope_W[i];
	}
	sort(rope_W.begin(),rope_W.end()); // 로프의 중량 정렬
	for (int i = 0; i < rope_W.size(); i++) {
		W_max = max(W_max, rope_W[n - i - 1] * (i + 1)); //최대인 중량들을 선택하면서 중량을 계산
	}
	cout << W_max;
}
