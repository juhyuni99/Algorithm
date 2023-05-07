#include <iostream>
using namespace std;
int n, x, y, dir, findNum;
int cnt = 1, siz = 1;
int map[1001][1001];

//그려진 표 출력
void print() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << map[i][j] << ' ';
        cout << '\n';
    }
}

//달팽이 그리기
void make() {
    x = n / 2;
    y = n / 2;
    map[x][y] = 1;

    while (cnt < n * n) {
        //왼쪽 변
        if (dir == 0) {
            for (int k = 0; k < siz; k++) {
                map[--x][y] = ++cnt;
            }
        }
        //윗변
        else if (dir == 1) {
            for (int k = 0; k < siz; k++) map[x][++y] = ++cnt;
            siz++;
        }
        //오른쪽 변
        else if (dir == 2) {
            for (int k = 0; k < siz; k++) map[++x][y] = ++cnt;
        }
        //아랫변
        else if (dir == 3) {
            for (int k = 0; k < siz; k++)
                map[x][--y] = ++cnt;
            siz++;
        }
        dir = (dir + 1) % 4; //방향 전환
    }
}
int main() {
    cin >> n >> findNum;
    make();
    print();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (map[i][j] == findNum) {
                cout << i + 1 << ' ' << j + 1; //위치 출력
                break;
            }
        }
    }
}