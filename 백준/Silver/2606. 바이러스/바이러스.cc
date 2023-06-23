#include <iostream>
#include <vector>


using namespace std;
bool visited[101]; //방문 check
vector<int> graph[101]; //컴퓨터 정보
int num;// 개수

//dfs 함수
void dfs(int x) {
	visited[x] = true;
	for (int i = 0; i < graph[x].size(); i++) {
		int y = graph[x][i];
		if (!visited[y]) { //방문하지 않았을 경우
			dfs(y);
			num++;
		}
	}
}
int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int com, path;
	cin >> com >> path; //컴퓨터 수, 컴퓨터 쌍의 수
	for (int i = 0; i < path; i++) { //컴퓨터 번호 쌍
		int a,b;
		cin >> a >> b;
		graph[a].push_back(b); //정보 추가
		graph[b].push_back(a);
	}
	dfs(1); //함수 호출
	cout << num;
}
