#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
vector<pair<int, int>> inf; // 수업 정보(2개의 값 쌍으로 저장)
// 우선순위 큐를 <자료형, 구현체, 비교연산자> 를 이용하여 선언한다.
// 비교연산자에 greater<int>를 사용하여 int가 작은값이 우선한다.
priority_queue<int, vector<int>, greater<int>> pq; // 종료시간(가장 작은 값이 우선순위가 되는 큐)

int main(void) {
	int N;//수업의 수
	cin >> N;
	int start, end;//수업 시작시간, 수업 종료시간
	

	for (int i = 0; i < N; i++) {
		cin >> start >> end; // 수업시간 입력
		inf.push_back(make_pair(start, end)); //pair 타입을 저장하는 vector이므로 make_pair을 사용해 주어서 값을 저장
	}
	sort(inf.begin(), inf.end()); // 첫 번째 원소인 시작시간을 기준으로 오름차순으로 정렬

	pq.push(inf[0].second); //첫 번째 수업 종료시간을 pq에 추가
	
	
	for (int i = 1; i < N; i++) {
		if (pq.top() <= inf[i].first) { // 현재 수업 종료시간보다 수업 시작 시간이 늦거나 같을 경우
			pq.pop(); // 수업 종료시간 change
			pq.push(inf[i].second); 
		}
		else { // 현재 수업 종료시간보다 수업시작 시간이 빠를 경우
			pq.push(inf[i].second); // 수업 종료시간 추가
		}
	}
	//int room = pq.size();
	cout << pq.size(); // 최소 강의실 개수 출력
	return 0;
}