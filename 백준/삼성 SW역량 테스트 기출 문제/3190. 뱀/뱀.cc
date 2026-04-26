#include <iostream>
#include <deque>
#include <vector>
using namespace std;

int N, K, L;
int board[101][101];

// 오른쪽, 아래, 왼쪽, 위
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int main() {
    cin >> N;
    cin >> K;

    for (int i = 0; i < K; i++) {
        int r, c;
        cin >> r >> c;
        board[r][c] = 1; // 사과
    }

    cin >> L;

    vector<pair<int, char>> turns;

    for (int i = 0; i < L; i++) {
        int x;
        char c;
        cin >> x >> c;
        turns.push_back({x, c});
    }

    deque<pair<int, int>> snake;
    snake.push_front({1, 1});
    board[1][1] = 2; // 뱀 몸

    int dir = 0;   // 처음 방향: 오른쪽
    int time = 0;
    int turnIndex = 0;

    while (true) {
        time++;

        int headX = snake.front().first;
        int headY = snake.front().second;

        int nx = headX + dx[dir];
        int ny = headY + dy[dir];

        // 벽에 부딪힘
        if (nx < 1 || nx > N || ny < 1 || ny > N) {
            break;
        }

        // 자기 몸에 부딪힘
        if (board[nx][ny] == 2) {
            break;
        }

        // 새 머리 추가
        snake.push_front({nx, ny});

        // 사과가 있으면
        if (board[nx][ny] == 1) {
            board[nx][ny] = 2;
        }
        // 사과가 없으면
        else {
            board[nx][ny] = 2;

            int tailX = snake.back().first;
            int tailY = snake.back().second;

            board[tailX][tailY] = 0;
            snake.pop_back();
        }

        // 방향 전환
        if (turnIndex < L && time == turns[turnIndex].first) {
            char turn = turns[turnIndex].second;

            if (turn == 'D') {
                dir = (dir + 1) % 4;
            } else if (turn == 'L') {
                dir = (dir + 3) % 4;
            }

            turnIndex++;
        }
    }

    cout << time << '\n';

    return 0;
}