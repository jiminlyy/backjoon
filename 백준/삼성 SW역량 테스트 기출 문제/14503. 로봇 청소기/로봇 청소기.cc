#include <iostream>
using namespace std;

int N, M;
int r, c, d;
int board[50][50];

// 북, 동, 남, 서
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

int answer = 0;

bool hasUncleanAround(int x, int y) {
    for (int dir = 0; dir < 4; dir++) {
        int nx = x + dx[dir];
        int ny = y + dy[dir];

        if (nx < 0 || nx >= N || ny < 0 || ny >= M) {
            continue;
        }

        if (board[nx][ny] == 0) {
            return true;
        }
    }

    return false;
}

int main() {
    cin >> N >> M;
    cin >> r >> c >> d;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> board[i][j];
        }
    }

    while (true) {
        // 1. 현재 칸이 청소되지 않은 경우 청소
        if (board[r][c] == 0) {
            board[r][c] = 2; // 청소 완료 표시
            answer++;
        }

        // 2. 주변 4칸 중 청소되지 않은 빈 칸이 있는 경우
        if (hasUncleanAround(r, c)) {
            // 반시계 방향으로 90도 회전
            d = (d + 3) % 4;

            int nr = r + dx[d];
            int nc = c + dy[d];

            // 바라보는 방향 앞쪽 칸이 청소되지 않은 빈 칸이면 전진
            if (board[nr][nc] == 0) {
                r = nr;
                c = nc;
            }
        }
        // 3. 주변 4칸 중 청소되지 않은 빈 칸이 없는 경우
        else {
            // 뒤쪽 방향
            int backDir = (d + 2) % 4;
            int nr = r + dx[backDir];
            int nc = c + dy[backDir];

            // 뒤쪽 칸이 벽이면 작동 종료
            if (board[nr][nc] == 1) {
                break;
            }

            // 바라보는 방향은 유지한 채 뒤로 이동
            r = nr;
            c = nc;
        }
    }

    cout << answer << '\n';

    return 0;
}