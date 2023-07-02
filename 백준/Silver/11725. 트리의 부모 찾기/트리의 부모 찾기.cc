#include<iostream>
#include<queue>
#include<vector>

using namespace std;
vector<int> graph[100001]; //그래프
bool visit[100001];//방문 표시
int res[100001];// 부모노드 값 저장

//bfs 탐색
void bfs() {
	queue<int> q;
	visit[1] = true;
	q.push(1);
	while (!empty(q)) { //큐가 비어있지 않을 때까지 반복
		int parent = q.front();
		q.pop();
		for (int i = 0; i < graph[parent].size(); i++) { //자식노드 검사
			int child = graph[parent][i];
			if (!visit[child]) {//방문하지 않았으면
				res[child] = parent;
				visit[child] = true;
				q.push(child);
			}
		}
	}
}

int main() {
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	bfs();
	for (int i = 2; i <= N; i++) {
		cout << res[i] << "\n";
	}

}