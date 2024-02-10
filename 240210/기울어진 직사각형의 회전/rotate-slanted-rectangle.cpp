#include <iostream>

using namespace std;

int dy[4] = {-1, -1, 1, 1};
int dx[4] = {-1, 1, 1, -1};

int Rdy[4] = {-1, -1, 1, 1};
int Rdx[4] = {1, -1, -1, 1};
int n;

int matrix[101][101];

int main() {
    // 여기에 코드를 작성해주세요.
    
    cin >> n;

    for(int iRow = 1 ; iRow < n + 1; ++iRow)
    {
        for(int iCol = 1; iCol < n + 1; ++iCol)
        {
            cin >> matrix[iRow][iCol];
        }
    }

    int r,c,dir;
    int m[4];

    cin >> r >> c >> m[0] >> m[1] >> m[2] >> m[3] >> dir;

    int curX = c;
    int curY = r;

    int nextTmp = matrix[r][c];

    if(dir == 0)
    {
        for(int iM = 0 ; iM < 4 ; ++iM)
        {
            curX += Rdx[iM] * m[iM];
            curY += Rdy[iM] * m[iM];
            int tmp = matrix[curY][curX];

            for(int iCnt = 0 ; iCnt < m[iM] - 1 ; ++iCnt)
            {
                int nextY = curY - Rdy[iM];
                int nextX = curX - Rdx[iM];

                matrix[curY][curX] = matrix[nextY][nextX];
                curY = nextY;
                curX = nextX;
            }

            matrix[curY][curX] = nextTmp;
            nextTmp = tmp;

            curY += Rdy[iM] * (m[iM] - 1);
            curX += Rdx[iM] * (m[iM] - 1);
        }
    }
    else
    {
        for(int iM = 3 ; iM >= 0 ; --iM)
        {
            curY += m[iM] * dy[iM];
            curX += m[iM] * dx[iM];
            int tmp = matrix[curY][curX];

            for(int iCnt = 0 ; iCnt < m[iM] - 1 ; ++iCnt)
            {
                int nextY = curY - dy[iM];
                int nextX = curX - dx[iM];

                matrix[curY][curX] = matrix[nextY][nextX];
                curY = nextY;
                curX = nextX;
            }

            matrix[curY][curX] = nextTmp;
            nextTmp = tmp;

            curY += dy[iM] * (m[iM] - 1);
            curX += dx[iM] * (m[iM] - 1);
        }
    }

    for(int iRow = 1 ; iRow < n + 1 ; ++iRow)
    {
        for(int iCol = 1 ; iCol < n + 1 ; ++iCol)
        {
            cout << matrix[iRow][iCol] << ' ';
        }
        cout << '\n';
    }

    return 0;
}

/*
고급 요구사항 :
n*n 격자가 있다. 각 요소는 1 ~ 100
기울어진 직사각형을 잡아 회전 시키려고 한다.
기울어진 직사각형 :
한 점이 6시이고, 반 시계 방향으로 대각선으로 이동을 해서 직사각형이 되는 경우

여기서 회전은 반 시계 방향으로의 회전을 말한다.

입력 :
n이 입력된다 (3 ~ 100)
n개에 줄에 걸쳐 격자에 대한 정보가 주어진다.
각 줄에는 각각의 행에 대한 정보가 주어진다.

그 다음 줄에는 기울어진 직사각형의 정보와 회전 방향을 나타내는 (r,c,m1,m2,m3,m4,dir) 값이 각각 공백들
사이에 두고 주어진다.


*/