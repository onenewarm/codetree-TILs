#include <iostream>

using namespace std;

int n,m,r,c;
int matrix[101][101];

int dy[4] = {-1, 1 , 0, 0};
int dx[4] = {0, 0, -1 , 1};

int curT = 0;

int main() {
    // 여기에 코드를 작성해주세요.

    cin >> n >> m >> r >> c;

    matrix[r][c] = 1;


    while(curT < m)
    {
        int tmp[101][101] = {};

        for(int iRow = 1 ; iRow <= n ; ++iRow)
        {
            for(int iCol = 1 ; iCol <= n ; ++iCol)
            {
                if(matrix[iRow][iCol] == 0) continue;
                
                tmp[iRow][iCol] = matrix[iRow][iCol];

                for(int iCnt = 0 ; iCnt < 4 ; ++iCnt)
                {
                    int nextY = iRow + (dy[iCnt] * (1 << curT));
                    int nextX = iCol + (dx[iCnt] * (1 << curT));

                    if(nextY < 1 || nextX < 1 || nextY > n || nextX > n ||
                        tmp[nextY][nextX] != 0) continue;

                    tmp[nextY][nextX] = 1;
                }
            }
        }

        for(int iRow = 1 ; iRow <= n ; ++iRow)
        {
            for(int iCol = 1 ; iCol <= n ; ++iCol)
            {
                matrix[iRow][iCol] = tmp[iRow][iCol];
            }
        }

        ++curT;
    }

    int res = 0;

    for(int iRow = 1 ; iRow <= n ; ++iRow)
    {
        for(int iCol = 1 ; iCol <= n ; ++iCol)
        {
            if(matrix[iRow][iCol]) ++res;
        }
    }

    cout << res;

    return 0;
}

/*

정사각형 격자가 있다.

한 지점에 폭탄이 있다.
폭탄은 시간이 흐름에 따라 4방향으로 폭발한다.

1초에 한 번 씩 폭발한다.
t초가 되면 t - 1초에 폭탄이 있떤 위치에서 상하좌우로 4방향 거리 2^(t-1) 만큼 떨어진
지점에 폭탄이 생성된다. 기존에 있던 폭탄은 그대로 남아있고 계속해서 터짐이 발생한다.

n,m
r,c

matrix
dy,dx

curT



*/