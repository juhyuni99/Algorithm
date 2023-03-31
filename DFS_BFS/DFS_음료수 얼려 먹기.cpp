#include <iostream>
#define _CRT_SECUER_NO_WARNINGS

using namespace std;

int n, m; // 세로, 가로
int graph[1000][1000];

//dfs로 특정 노드를 방문하고 연결된 모든 노드 방문
bool dfs(int x, int y) {
	//주어진 범위를 벗어나는 경우에는 즉시 종료
	if (x < 0 || x>=n || y < 0 || y>=m) {
		return false;
	}
	//현재 노드를 아직 방문하지 않았다면
	if (graph[x][y] == 0) {
		//해당 노드 방문 처리
		graph[x][y] = 1;
		//상, 하, 좌, 우의 위치들도 모두 재귀적으로 호출
		dfs(x - 1, y); // up
		dfs(x, y - 1); // left
		dfs(x + 1, y); // down
		dfs(x, y + 1); // right
		return true;
	}
	return false;

}
int main(){
	//N, M을 공백을 기준으로 구분하여 입력 받기
	cin >> n >> m;
	//2차원 리스트의 맵 정보 입력 받기
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf_s("%1d", &graph[i][j]); //%ld : 정수 한개씩 입력받기
		}
	}
	//모든 노드(위치)에 대하여 음료수 채우기
	int result = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			//현재 위치에서 DFS 수행
			if (dfs(i, j)) {
				result += 1;
			}
		}
	}
	cout << result << '\n'; // 정답 출력
}
