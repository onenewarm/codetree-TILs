#include <iostream>
#include <cstring>

using namespace std;

int n,m,t;
int matrix[21][21];
int Cnt[21][21];
int nextCnt[21][21];

int dy[4] = { -1, 1, 0, 0};
int dx[4] = { 0, 0, -1, 1};

void Solve()
{
    memset(nextCnt, 0, sizeof(int) * 21 * 21);
    for(int iRow = 1; iRow <= n ; ++iRow)
    {
        for(int iCol = 1 ; iCol <= n ; ++iCol)
        {
            if(Cnt[iRow][iCol])
            {
                int maxNum = -1;

                int nextY,nextX;

                for(int iCnt = 0 ; iCnt < 4 ; ++iCnt)
                {
                    int ny = iRow + dy[iCnt];
                    int nx = iCol + dx[iCnt];

                    if(ny < 1 || nx < 1 || ny > n || nx > n || maxNum >= matrix[ny][nx]) continue;

                    maxNum = matrix[ny][nx];
                    nextY = ny;
                    nextX = nx;
                    ++nextCnt[nextY][nextX];
                }
            }
        }
    }


    for(int iRow = 1 ; iRow <= n ; ++iRow)
    {
        for(int iCol = 1; iCol <= n ; ++iCol)
        {
            if(nextCnt[iRow][iCol] > 1) nextCnt[iRow][iCol] = 0;
        }
    }


    memcpy(Cnt, nextCnt, sizeof(int) *  21 * 21);
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n >> m >> t;

    for(int iRow = 1 ; iRow <= n ; ++iRow)
    {
        for(int iCol = 1 ; iCol <= n ; ++iCol)
        {
            cin >> matrix[iRow][iCol];
        }
    }

    for(int iCnt = 0 ; iCnt < m ; ++iCnt)
    {
        int r,c;
        cin >> r >> c;
        Cnt[r][c] = 1;
    }

    while(t--)
    {
        Solve();
    }
    
    int res = 0;

    for(int iRow = 1 ; iRow <= n ; ++iRow)
    {
        for(int iCol = 1 ; iCol <= n ; ++iCol)
        {
            if(Cnt[iRow][iCol]) ++res;
        }
    }

    cout << res;
    
    return 0;
}

/*

정사각형 격자판이 주어지고,
m개의 구슬이 주어진다. (서로 다른 위치)
1초에 한 번 씩 상하좌우로 움직인다.
인접한 곳 중에서 숫자가 가장 큰 값이 적혀 있는 쪽으로 동시에 간다.

이런 위치가 여러개이면 상하좌우 순으로 간다. 격자를 벗어나서는 안된다.



*/