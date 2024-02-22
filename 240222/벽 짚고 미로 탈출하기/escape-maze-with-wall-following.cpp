#include <iostream>

using namespace std;

int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, 1, 0, -1 };

int curIdx = 1;

int startX, startY;

int n;
char matrix[101][101];

void Solve()
{
    int curY = startY;
    int curX = startX;

    int cnt = 0;

    while (1)
    {
        int nextY = curY + dy[curIdx];
        int nextX = curX + dx[curIdx];

        int visit[101][101][4];

        if (nextY < 1 || nextX < 1 || nextY > n || nextX > n)
        {
            ++cnt;
            break;
        }

        if (visit[nextY][nextX][curIdx] == 1)
        {
            cnt = -1;
            break;
        }

        if (matrix[nextY][nextX] == '#')
        {
            visit[nextY][nextX][curIdx] = 1;
            curIdx = (curIdx + 3) % 4;
        }
        else
        {
            visit[nextY][nextX][curIdx] = 1;
            curY = nextY;
            curX = nextX;
            ++cnt;

            int checkY = curY + dy[(curIdx + 5) % 4];
            int checkX = curX + dx[(curIdx + 5) % 4];

            if (checkY < 1 || checkX < 1 || checkY > n || checkX > n || matrix[checkY][checkX] == '#') continue;

            curIdx = (curIdx + 5) % 4;
            visit[checkY][checkX][curIdx] = 1;
            curY = checkY;
            curX = checkX;
            ++cnt;
        }
    }

    cout << cnt;
}

int main() {
    // 여기에 코드를 작성해주세요.

    cin >> n;
    cin >> startY >> startX;
    for (int iRow = 1; iRow < n + 1; ++iRow)
    {
        for (int iCol = 1; iCol < n + 1; ++iCol)
        {
            cin >> matrix[iRow][iCol];
        }
    }

    Solve();


    return 0;
}

/*

정사각형이 격자가 주어지낟.
우측 방향을 바라보고 시작한다.
오른쪽 방향으로 이동한다.

이동을 못하면 반시계 방향으로 90도 회전한다. curIdx, dx, dy를 시계방향으로 구성하고 인덱스를 뒤로 이동ㅅ킨다.

이동하는 방향이 격자 밖이면 끝.

이동하는 방향에 시계 방향 위치에 벽이 있어야 한다. 없다면 일단 이동 후, 시계방향으로 회전


*/