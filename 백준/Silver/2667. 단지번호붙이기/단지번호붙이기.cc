
#include<iostream>
#include<queue>
#include<algorithm>

using namespace std;
int n;
int cnt = 0;//단지수 카운트
string graph[26]; //맵
bool visited[26][26] = { 0, };
vector<int> result; //각 단지 개수 저장
int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };

void bfs(int x, int y){
	queue<pair<int, int>> q;
	q.push({ x,y });
	visited[x][y] = true;
	cnt++;
	//q가 빌때까지 반복
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		// 현재 위치에서 4가지 방향으로의 위치 확인
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue; //board범위
			if (visited[nx][ny] == true) continue; // 이미 방문한곳은 패스
			if (graph[nx][ny] == '1')
			{
				q.push({ nx,ny });
				visited[nx][ny] = true;
				cnt++;
			}
		}
	}
}

int main(void) {
	
	cin >> n;
	//2차원 맵정보 입력 받기
	for (int i = 0; i < n; i++) {	
		cin>>graph[i];// 정수 한개씩 입력받기
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if(graph[i][j] == '1' && visited[i][j] == false) {
				cnt = 0;
				bfs(i, j);
				result.push_back(cnt);
			}
		}
	}
	sort(result.begin(), result.end());
	cout << result.size() << '\n';
	for (int i = 0; i<result.size(); i++) {
		cout << result[i] << '\n';
	}
	return 0;
}