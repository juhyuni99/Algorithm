#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
vector<long long> arr;
long long N; 

int main(void) {
	int result = 0;
	cin>> N; // 유제품 수
	vector<int> arr(N);
	
	for (int i = 0; i < arr.size(); i++) { //유제품 가격
		cin >> arr[i];
	}
	sort(arr.begin(), arr.end(), greater<int>());//내림차순

	for (int i = 0; i < arr.size(); i++) {
		// 3개씩 묵은것중 가장 작은 값 -> 즉 3의 배수이면 계산안하기
		if ((i + 1) % 3 == 0) continue;
		result += arr[i];
	}
	cout << result;
	return 0;
}