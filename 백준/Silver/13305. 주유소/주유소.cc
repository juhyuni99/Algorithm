#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
long long N; // 도시 수

int main(void) {
	long long result = 0; //비용
	cin >> N;

	vector<long long> d(N);
	vector<long long> price(N);

	for (int i = 0; i < N-1; i++) { //도로의 길이
		cin >> d[i];
	}
	for (int i = 0; i < price.size(); i++) { // 각 도시 주유소 가격
		cin >> price[i];
	}
	// price[0]->price[1]에 갈때는 무조건 price[0]에서 d[0]만큼 기름 넣고 출발
	long long min = price[0]; 
	result = min * d[0];

	for(int i = 0; i< price.size(); i++){
		//주유소 가격 비교하기
		if (min >= price[i + 1]) min = price[i + 1]; 
		// 최소 주유소 가격 * 다음 도시까지의 도로 길이
		result += min * d[i + 1];
	}
	cout << result;
	return 0;
}