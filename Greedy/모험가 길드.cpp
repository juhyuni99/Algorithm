#include <bits/stdc++.h>

using namespace std;

int N;
vector<int> arr; // 배열 -> c++에서는 vertor라이브러리 사용 , python은 list
// 비어있는 벡터 arr 생성
int main(void) {
	cin >> N;
	for (int i = 0; i < N; i++) {
		int x;
		cin >> x;
		arr.push_back(x); // 0번 요소 값을 생성하고 x로 초기화
	}
	sort(arr.begin(), arr.end()); // 오름차순 정렬
//내림차순 정렬 : sort(arr.begin(), arr.end(), greater<int>());

	int result = 0; // 총 그룹의 수
	int cnt = 0; // 현재 그룹에 포함된 모험가의 수
	for (int i = 0; i < N; i++) { //공포도를 낮은 것부터 하나씩 확인하며
		cnt += 1; // 현재 그룹에 해당 모험가를 포함시키기
		if (cnt >= arr[i]) { // 현재 그룹에 포함된 모험가의 수가 현재의 공포도 이상이라면, 그룹 결성
			result += 1; // 총 그룹의 수 증가시키기
			cnt = 0; // 현재 그룹에 포함된 모험가의 수 초기화
		}
	}
	cout << result << '\n'; // 총 그룹의 수 출력
}
