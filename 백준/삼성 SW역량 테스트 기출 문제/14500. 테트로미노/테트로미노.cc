#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
int board[500][500];
bool visited[500][500];

int answer = 0;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void dfs(int x, int y, int depth, int sum) {
    if (depth == 4) {
        answer = max(answer, sum);
        return;
    }

    for (int dir = 0; dir < 4; dir++) {
        int nx = x + dx[dir];
        int ny = y + dy[dir];

        if (nx < 0 || nx >= N || ny < 0 || ny >= M) {
            continue;
        }

        if (visited[nx][ny]) {
            continue;
        }

        visited[nx][ny] = true;
        dfs(nx, ny, depth + 1, sum + board[nx][ny]);
        visited[nx][ny] = false;
    }
}

void checkTShape(int x, int y) {
    // ㅗ, ㅜ, ㅓ, ㅏ 모양을 직접 검사

    // ㅗ 모양
    if (x - 1 >= 0 && y - 1 >= 0 && y + 1 < M) {
        int sum = board[x][y] + board[x - 1][y] + board[x][y - 1] + board[x][y + 1];
        answer = max(answer, sum);
    }

    // ㅜ 모양
    if (x + 1 < N && y - 1 >= 0 && y + 1 < M) {
        int sum = board[x][y] + board[x + 1][y] + board[x][y - 1] + board[x][y + 1];
        answer = max(answer, sum);
    }

    // ㅓ 모양
    if (x - 1 >= 0 && x + 1 < N && y - 1 >= 0) {
        int sum = board[x][y] + board[x - 1][y] + board[x + 1][y] + board[x][y - 1];
        answer = max(answer, sum);
    }

    // ㅏ 모양
    if (x - 1 >= 0 && x + 1 < N && y + 1 < M) {
        int sum = board[x][y] + board[x - 1][y] + board[x + 1][y] + board[x][y + 1];
        answer = max(answer, sum);
    }
}

int main() {
    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> board[i][j];
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            visited[i][j] = true;
            dfs(i, j, 1, board[i][j]);
            visited[i][j] = false;

            checkTShape(i, j);
        }
    }

    cout << answer << '\n';

    return 0;
}