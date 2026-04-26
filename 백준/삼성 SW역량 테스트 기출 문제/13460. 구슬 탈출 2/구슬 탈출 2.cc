#include <iostream>
#include <queue>
#include <tuple>
#include <string>
using namespace std;

int N, M;
char board[10][10];
bool visited[10][10][10][10];

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
// 위, 아래, 왼쪽, 오른쪽

struct State
{
    int rx, ry;
    int bx, by;
    int depth;
};

struct MoveResult
{
    int x, y;
    int count;
    bool hole;
};

MoveResult moveBall(int x, int y, int dir)
{
    int count = 0;

    while (true)
    {
        int nx = x + dx[dir];
        int ny = y + dy[dir];

        if (board[nx][ny] == '#')
        {
            break;
        }

        x = nx;
        y = ny;
        count++;

        if (board[x][y] == 'O')
        {
            return {x, y, count, true};
        }
    }

    return {x, y, count, false};
}

int bfs(int rx, int ry, int bx, int by)
{
    queue<State> q;

    q.push({rx, ry, bx, by, 0});
    visited[rx][ry][bx][by] = true;

    while (!q.empty())
    {
        State cur = q.front();
        q.pop();

        if (cur.depth >= 10)
        {
            continue;
        }

        for (int dir = 0; dir < 4; dir++)
        {
            MoveResult red = moveBall(cur.rx, cur.ry, dir);
            MoveResult blue = moveBall(cur.bx, cur.by, dir);

            // 파란 구슬이 빠지면 실패
            if (blue.hole)
            {
                continue;
            }

            // 빨간 구슬만 빠지면 성공
            if (red.hole)
            {
                return cur.depth + 1;
            }

            // 두 구슬이 같은 위치에 있으면 하나를 뒤로 빼야 함
            if (red.x == blue.x && red.y == blue.y)
            {
                if (red.count > blue.count)
                {
                    red.x -= dx[dir];
                    red.y -= dy[dir];
                }
                else
                {
                    blue.x -= dx[dir];
                    blue.y -= dy[dir];
                }
            }

            if (!visited[red.x][red.y][blue.x][blue.y])
            {
                visited[red.x][red.y][blue.x][blue.y] = true;
                q.push({red.x, red.y, blue.x, blue.y, cur.depth + 1});
            }
        }
    }

    return -1;
}

int main()
{
    cin >> N >> M;

    int rx, ry, bx, by;

    for (int i = 0; i < N; i++)
    {
        string line;
        cin >> line;

        for (int j = 0; j < M; j++)
        {
            board[i][j] = line[j];

            if (board[i][j] == 'R')
            {
                rx = i;
                ry = j;
                board[i][j] = '.';
            }
            else if (board[i][j] == 'B')
            {
                bx = i;
                by = j;
                board[i][j] = '.';
            }
        }
    }

    cout << bfs(rx, ry, bx, by) << '\n';

    return 0;
}