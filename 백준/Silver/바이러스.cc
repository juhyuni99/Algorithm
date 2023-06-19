#include <iostream>
#include <vector>

using namespace std;
bool visited[7];
vector<int> graph[7];
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
	int com, path;
	cin >> com >> path;
	for (int i = 0; i < path; i++) {
		int a,b;
		cin >> a >> b;
		graph[a].push_back(b);
	}
	dfs(1);
	cout << num;
}
