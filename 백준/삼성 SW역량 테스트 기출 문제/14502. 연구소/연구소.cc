#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int N, M;
int board[8][8];
int tempBoard[8][8];
int answer = 0;

vector<pair<int, int>> virus;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void copyBoard() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            tempBoard[i][j] = board[i][j];
        }
    }
}

void spreadVirus() {
    queue<pair<int, int>> q;

    for (int i = 0; i < virus.size(); i++) {
        q.push(virus[i]);
    }

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int dir = 0; dir < 4; dir++) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];

            if (nx < 0 || nx >= N || ny < 0 || ny >= M) {
                continue;
            }

            if (tempBoard[nx][ny] == 0) {
                tempBoard[nx][ny] = 2;
                q.push({nx, ny});
            }
        }
    }
}

int countSafeArea() {
    int count = 0;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (tempBoard[i][j] == 0) {
                count++;
            }
        }
    }

    return count;
}

void makeWall(int count) {
    if (count == 3) {
        copyBoard();
        spreadVirus();
        answer = max(answer, countSafeArea());
        return;
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (board[i][j] == 0) {
                board[i][j] = 1;
                makeWall(count + 1);
                board[i][j] = 0;
            }
        }
    }
}

int main() {
    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> board[i][j];

            if (board[i][j] == 2) {
                virus.push_back({i, j});
            }
        }
    }

    makeWall(0);

    cout << answer << '\n';

    return 0;
}