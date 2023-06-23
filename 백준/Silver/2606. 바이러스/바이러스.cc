#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
bool visited[101];
vector<int> graph[101];
int num;

void dfs(int x) {
	visited[x] = true;
	for (int i = 0; i < graph[x].size(); i++) {
		int y = graph[x][i];
		if (!visited[y]) {
			dfs(y);
			num++;
		}
	}
}
int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int com, path;
	cin >> com >> path;
	for (int i = 0; i < path; i++) {
		int a,b;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	dfs(1);
	cout << num;
}
