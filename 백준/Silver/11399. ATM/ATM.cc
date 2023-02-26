#include <bits/stdc++.h>
using namespace std;

int n; // 사람의 수

vector<int> arr; // 비어있는 vector 생성

int main(void) {
	cin >> n; 
	int result = 0; // 각 사람이 돈을 인출하는데 필요한, 시간의 합의 최솟값
	int sum = 0; //사람마다 걸리는 시간(대기+인출)
	for (int i = 0; i < n; i++) {
		int p;
		cin >> p; // 각 사람이 돈을 인출하는데 걸리는 시간
		arr.push_back(p); // 각 요소 값 생성하고 p로 초기화
	}
	sort(arr.begin(), arr.end());//오름차순 정렬
	for (int i = 0; i < n; i++) { 
		sum += arr[i]; 
		result += sum;
	}
	cout << result << endl; //각 사람이 돈을 인출하는데 필요한, 시간의 합의 최솟값 출력
}
