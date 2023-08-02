#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;
vector<int> graph[10001];
bool visited[10001];
int n,m,cnt;
struct cmp {
	bool operator()(pair<int, int> a, pair<int, int> b) {
		if (a.first == b.first)
			return a.second > b.second;
		return a.first < b.first;
	}
};


void dfs(int start) {

	cnt++;
	visited[start] = true;
	for (int i = 0; i < graph[start].size(); i++) {

		if (!visited[graph[start][i]]) {
			
			dfs(graph[start][i]);
		}

	}

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;

	for (int i = 0; i < m; i++) {
		int to, from;
		cin >> to >> from;
		graph[from].push_back(to);
	}
	for (int i = 1; i <= n; i++) {
		dfs(i);
		pq.push({ cnt,i });
		//cout << i << ' ' << cnt << '\n';
		cnt = 0;
		memset(visited, false, sizeof(visited));
	}
	if (!pq.empty()) {
		int first = pq.top().first;
		int result = pq.top().second;
		cout << result << ' ';
		pq.pop();
		while (!pq.empty()&& first==pq.top().first) {
			cout << pq.top().second << ' ';
			pq.pop();
		}
	}

	return 0;
}