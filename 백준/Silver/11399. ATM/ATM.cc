#include <bits/stdc++.h>
using namespace std;

int n; // 사람의 수

vector<int> arr; // 비어있는 vector 생성

int main(void) {
	cin >> n;
	int result = 0;
	int sum = 0;
	for (int i = 0; i < n; i++) {
		int p;
		
		cin >> p; // 각 사람이 돈을 인출하는데 걸리는 시간
		arr.push_back(p); // p값 생성
	}
	sort(arr.begin(), arr.end());
	for (int i = 0; i < n; i++) {
		sum += arr[i];
		result += sum;// 필요한 시간의 합
	}
	cout << result << endl;
}