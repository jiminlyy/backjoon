#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
int answer = 0;

void updateAnswer(const vector<vector<int>>& board) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            answer = max(answer, board[i][j]);
        }
    }
}

vector<vector<int>> moveBoard(vector<vector<int>> board, int dir) {
    vector<vector<int>> result(N, vector<int>(N, 0));

    // dir = 0: 위
    if (dir == 0) {
        for (int col = 0; col < N; col++) {
            vector<int> temp;

            for (int row = 0; row < N; row++) {
                if (board[row][col] != 0) {
                    temp.push_back(board[row][col]);
                }
            }

            int idx = 0;
            for (int i = 0; i < temp.size(); i++) {
                if (i + 1 < temp.size() && temp[i] == temp[i + 1]) {
                    result[idx][col] = temp[i] * 2;
                    i++;
                } else {
                    result[idx][col] = temp[i];
                }
                idx++;
            }
        }
    }

    // dir = 1: 아래
    else if (dir == 1) {
        for (int col = 0; col < N; col++) {
            vector<int> temp;

            for (int row = N - 1; row >= 0; row--) {
                if (board[row][col] != 0) {
                    temp.push_back(board[row][col]);
                }
            }

            int idx = N - 1;
            for (int i = 0; i < temp.size(); i++) {
                if (i + 1 < temp.size() && temp[i] == temp[i + 1]) {
                    result[idx][col] = temp[i] * 2;
                    i++;
                } else {
                    result[idx][col] = temp[i];
                }
                idx--;
            }
        }
    }

    // dir = 2: 왼쪽
    else if (dir == 2) {
        for (int row = 0; row < N; row++) {
            vector<int> temp;

            for (int col = 0; col < N; col++) {
                if (board[row][col] != 0) {
                    temp.push_back(board[row][col]);
                }
            }

            int idx = 0;
            for (int i = 0; i < temp.size(); i++) {
                if (i + 1 < temp.size() && temp[i] == temp[i + 1]) {
                    result[row][idx] = temp[i] * 2;
                    i++;
                } else {
                    result[row][idx] = temp[i];
                }
                idx++;
            }
        }
    }

    // dir = 3: 오른쪽
    else if (dir == 3) {
        for (int row = 0; row < N; row++) {
            vector<int> temp;

            for (int col = N - 1; col >= 0; col--) {
                if (board[row][col] != 0) {
                    temp.push_back(board[row][col]);
                }
            }

            int idx = N - 1;
            for (int i = 0; i < temp.size(); i++) {
                if (i + 1 < temp.size() && temp[i] == temp[i + 1]) {
                    result[row][idx] = temp[i] * 2;
                    i++;
                } else {
                    result[row][idx] = temp[i];
                }
                idx--;
            }
        }
    }

    return result;
}

void dfs(int depth, vector<vector<int>> board) {
    if (depth == 5) {
        updateAnswer(board);
        return;
    }

    for (int dir = 0; dir < 4; dir++) {
        vector<vector<int>> nextBoard = moveBoard(board, dir);
        dfs(depth + 1, nextBoard);
    }
}

int main() {
    cin >> N;

    vector<vector<int>> board(N, vector<int>(N));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> board[i][j];
            answer = max(answer, board[i][j]);
        }
    }

    dfs(0, board);

    cout << answer << '\n';

    return 0;
}