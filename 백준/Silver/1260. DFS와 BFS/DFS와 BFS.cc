#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;
bool visited1[10001];
bool visited2[10001];
vector<int> graph[10001];

//dfs 함수
void dfs(int x) {
	visited1[x] = true;
	sort(graph[x].begin(), graph[x].end());
	for (int i = 0; i < graph[x].size(); i++) {
		int y = graph[x][i];
		if (!visited1[y]) {
			cout << y << ' ';
			dfs(y);
		}
	}
}

//bfs 함수
void bfs(int start) {
	queue<int> q;
	q.push(start);
	//현재 노드를 방문 처리
	visited2[start] = true;
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		cout << x << ' ';
		for (int i = 0; i < graph[x].size(); i++) {
			int y = graph[x][i];
			if (!visited2[y]) {
				q.push(y);
				visited2[y] = true;
			}
		}
	}
}
int main() {
	int n, m, v;
	cin >> n >> m >> v;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
		
	}
	cout << v <<' ';
	dfs(v);
	cout << endl;
	bfs(v);
}