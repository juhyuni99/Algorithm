
#include<iostream>
#include<vector>
#include<queue>

using namespace std;
int n, m;
int graph[101][101]; //미로
int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };

int bfs(int x, int y){
	queue<pair<int, int>> q;
	q.push({ x,y });
	//q가 빌때까지 반복
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		// 현재 위치에서 4가지 방향으로의 위치 확인
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			//미로 찾기 공간을 벗어난 경우 무시
			if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
			//벽인 경우 무시
			if (graph[nx][ny] == 0) continue;
			// 해당 노드를 처음 방문하는 경우에만 최단 거리 기록
			if (graph[nx][ny] == 1) {
				graph[nx][ny] = graph[x][y] + 1;
				q.push({ nx, ny });
			}
		}
	}
	// 가장 오른쪽 아래까지의 최단 거리 반환
	return graph[n - 1][m - 1];
}

int main(void) {
	
	cin >> n >> m;
	//2차원 맵정보 입력 받기
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%1d", &graph[i][j]); //정수 한개씩 입력받기
		}
	}
	// BFS를 수행한 결과 출력
	cout << bfs(0, 0) << '\n';
	return 0;
}
