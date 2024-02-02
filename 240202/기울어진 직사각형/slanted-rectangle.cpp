#include <iostream>

using namespace std;

int dy[4] = { -1, -1, 1, 1 };
int dx[4] = { 1, -1, -1, 1 };

int main() {
    // 여기에 코드를 작성해주세요.
    int n;
    cin >> n;

    int matrix[21][21];

    for (int iRow = 0; iRow < n; ++iRow)
    {
        for (int iCol = 0; iCol < n; ++iCol)
        {
            cin >> matrix[iRow][iCol];
        }
    }

    int ans = 0;

    for (int iRow = 0; iRow < n; ++iRow)
    {
        for (int iCol = 0; iCol < n; ++iCol)
        {
            for (int sideLen = 1; sideLen < n - 1; ++sideLen)
            {
                int firstNextY = iRow + (sideLen * dy[0]);
                int firstNextX = iCol + (sideLen * dx[0]);

                if (firstNextY < 0 || firstNextY > n - 1 || firstNextX < 0 || firstNextX > n - 1) break;

                for (int bottomLen = 1; bottomLen < n - sideLen; ++bottomLen)
                {
                    int sum = 0;

                    int nextY = firstNextY + (bottomLen * dy[1]);
                    int nextX = firstNextX + (bottomLen * dx[1]);

                    if (nextY < 0 || nextY > n - 1 || nextX < 0 || nextX > n - 1) break;

                    nextY = nextY + (sideLen * dy[2]);
                    nextX = nextX + (sideLen * dx[2]);

                    if (nextY < 0 || nextY > n - 1 || nextX < 0 || nextX > n - 1) break;

                    nextY = nextY + (bottomLen * dy[3]);
                    nextX = nextX + (bottomLen * dx[3]);

                    if (nextY < 0 || nextY > n - 1 || nextX < 0 || nextX > n - 1) break;

                    int curY = iRow;
                    int curX = iCol;

                    for (int iFirst = 0; iFirst < sideLen; ++iFirst)
                    {
                        curY = curY += dy[0];
                        curX = curX += dx[0];
                        sum += matrix[curY][curX];
                    }

                    for (int iSecond = 0; iSecond < bottomLen; ++iSecond)
                    {
                        curY = curY += dy[1];
                        curX = curX += dx[1];
                        sum += matrix[curY][curX];
                    }

                    for (int iThird = 0; iThird < sideLen; ++iThird)
                    {
                        curY = curY += dy[2];
                        curX = curX += dx[2];
                        sum += matrix[curY][curX];
                    }

                    for (int iForth = 0; iForth < bottomLen; ++iForth)
                    {
                        curY = curY += dy[3];
                        curX = curX += dx[3];
                        sum += matrix[curY][curX];
                    }

                    ans = max(ans, sum);
                }
            }
        }
    }


    cout << ans;

    return 0;
}

/*
고급 요구사항 :
n * n 크기의 격자 정보가 주어진다. 1 ~ 100 사이의 숫자로 이루어져 있다.

격자 내에 있는 기울어진 직사각형을 살펴보려고 한다.

기울어진 직사각형 :
한 지점에서 체스의 비숍처럼 대각선으로 움직이며 반시계 순회를 했을 때 지나왔던 지점들의 집합을 일컫는다.
순서 : 아래를 시작으로 반시계로 돈다.

가능한 기울어진 직사각형들 중 해당 직사각형을 이루는 지점에 적힌 숫자들의 합이 최대가 되로고 하려고 한다.

입력 :
격자의 크기를 나타내는 n (3 ~ 20)


아이디어 :
한 점을 아래 위치로 잡는다.
반시계로 돈다. 최대 n - 2번 이동 가능하다.

*/