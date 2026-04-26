#include <iostream>
#include <vector>
using namespace std;

int N, M, x, y, K;
int board[20][20];

int topFace = 0;
int bottomFace = 0;
int eastFace = 0;
int westFace = 0;
int northFace = 0;
int southFace = 0;

// 동, 서, 북, 남
int dx[5] = {0, 0, 0, -1, 1};
int dy[5] = {0, 1, -1, 0, 0};

void rollDice(int dir) {
    int top = topFace;
    int bottom = bottomFace;
    int east = eastFace;
    int west = westFace;
    int north = northFace;
    int south = southFace;

    if (dir == 1) {
        // 동쪽으로 굴림
        topFace = west;
        bottomFace = east;
        eastFace = top;
        westFace = bottom;
    } else if (dir == 2) {
        // 서쪽으로 굴림
        topFace = east;
        bottomFace = west;
        eastFace = bottom;
        westFace = top;
    } else if (dir == 3) {
        // 북쪽으로 굴림
        topFace = south;
        bottomFace = north;
        northFace = top;
        southFace = bottom;
    } else if (dir == 4) {
        // 남쪽으로 굴림
        topFace = north;
        bottomFace = south;
        northFace = bottom;
        southFace = top;
    }
}

int main() {
    cin >> N >> M >> x >> y >> K;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> board[i][j];
        }
    }

    for (int i = 0; i < K; i++) {
        int command;
        cin >> command;

        int nx = x + dx[command];
        int ny = y + dy[command];

        // 지도 밖으로 나가면 명령 무시
        if (nx < 0 || nx >= N || ny < 0 || ny >= M) {
            continue;
        }

        // 위치 이동
        x = nx;
        y = ny;

        // 주사위 굴리기
        rollDice(command);

        // 지도와 주사위 바닥면 값 복사
        if (board[x][y] == 0) {
            board[x][y] = bottomFace;
        } else {
            bottomFace = board[x][y];
            board[x][y] = 0;
        }

        // 윗면 출력
        cout << topFace << '\n';
    }

    return 0;
}