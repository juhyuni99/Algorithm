#include <iostream>
#include <vector>

using namespace std;
vector<long long> arr;
long long N, k; // 동전종류개수, 값

int main(void) {
	int result = 0;//최종 동전개수
	cin >> N >> k;
	vector<long long> arr(N);
	
	for (int i = 0; i < arr.size(); i++) { //동전종류
		cin >> arr[i];
	}
	for (int i = arr.size()-1; i >= 0; i--) {
		result += k / arr[i];	
		k = k % arr[i]; //나머지 돈
	}
	cout << result;
	return 0;
}