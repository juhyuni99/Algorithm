#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>

using namespace std;
vector<int> graph[10001]; //그래프
bool visit[10001];//방문 표시
vector<pair<int, int>> v; //컴퓨터 번호, 해킹 가능한 컴퓨터 수
int hacked = 1;//해킹 가능한 컴퓨터 수

//bfs 탐색
void bfs(int v) {
	queue<int> q;
	visit[v] = true;
	q.push(v);
	while (!empty(q)) { //큐가 비어있지 않을 때까지 반복
		int parent = q.front();
		q.pop();
		for (int i = 0; i < graph[parent].size(); i++) { //자식노드 검사
			int child = graph[parent][i];
			if (!visit[child]) {//방문하지 않았으면
				visit[child] = true;
				q.push(child);
				hacked++;
			}
		}
	}
}

int main() {
	int N, M; //컴퓨터 수, 관계
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		graph[b].push_back(a);
	}
	for (int i = 1; i <= N; i++) {
		bfs(i);
		for (int j = 1; j <= N; j++) {//초화
			visit[j] = 0;
		}
		v.push_back(make_pair(i, hacked));
		hacked = 1;//초기화
	}
	
	//해킹 가능한 최대 컴퓨터 수 구하기
	int maxHack = 0;
	for (int i = 0; i < v.size(); i++) {
		if (v[i].second > maxHack) {
			maxHack = v[i].second;
		}
	}

	//maxHack에 해당하는 컴퓨터 번호 모두 출력
	for (int i = 0; i < v.size(); i++) {
		if (v[i].second == maxHack) {
			cout << v[i].first << " ";
		}
	}
}
