#include <iostream>
#include <cstring>

using namespace std;

int n, m, k;
int matrix[100][100];
int tmp[100][100];
int topRows[100];


bool Boom()
{
    bool boomFlag = false;

    for(int iCol = 0 ; iCol < n ; ++iCol)
    {
        int topRow = topRows[iCol];

        if(topRow == n) continue;

        int row = topRow;

        int stdNum = matrix[row][iCol];
        int numCnt = 1;

        while(row < n)
        {
            if(row != (n-1) && stdNum == matrix[row + 1][iCol])
            {
                ++numCnt;
            }
            else
            {
                if(numCnt >= m)
                {
                    for(int iRow = row ; iRow > row - numCnt ; --iRow)
                    {
                        matrix[iRow][iCol] = 0;
                    }
                    boomFlag = true;
                }

                stdNum = matrix[row + 1][iCol];
                numCnt = 1;
            }
            ++row;
        }
    }

    return boomFlag;
}

void Gravity()
{
    memset(tmp, 0, 4*100*100);

    for(int iCol = 0 ; iCol < n ; ++iCol)
    {
        int topRow = topRows[iCol];
        int curRow = n - 1;
        for(int iRow = n - 1 ; iRow >= topRow ; --iRow)
        {
            if(matrix[iRow][iCol])
            {
                tmp[curRow--][iCol] = matrix[iRow][iCol];
            }
        }
        topRows[iCol] = curRow + 1;
    }

    for(int iRow = 0 ; iRow < n ; ++iRow)
    {
        for(int iCol = 0 ; iCol < n ; ++iCol)
        {
            matrix[iRow][iCol] = tmp[iRow][iCol];
        }
    }

}

void Rotate()
{
//( x, (n-1) - y )
    memset(tmp, 0, 4*100*100);

    for(int iRow = 0 ; iRow < n ; ++iRow)
    {
        for(int iCol = 0 ; iCol < n ; ++iCol)
        {
            tmp[iCol][(n-1) - iRow] = matrix[iRow][iCol];
        }
    }

    for(int iRow = 0 ; iRow < n ; ++iRow)
    {
        for(int iCol = 0 ; iCol < n ;++iCol)
        {
            matrix[iRow][iCol] = tmp[iRow][iCol];
        }
    }

    for(int iCol = 0 ; iCol < n ; ++iCol)
    {
        int topRow = 0;
        while(!matrix[topRow][iCol]) ++topRow;
        topRows[iCol] = topRow;
    }

    Gravity();

}

void Solve()
{
    while(Boom())
    {
        Gravity();
    }
    while(k--)
    {
        Rotate();
        while(Boom())
        {
            Gravity();
        }
    }


    int res = 0;

    for(int iRow = 0 ; iRow < n ; ++iRow)
    {
        for(int iCol = 0 ; iCol < n ; ++iCol)
        {
            if(matrix[iRow][iCol]) ++res;
        }
    }

    cout << res;
}

int main() {
    // 여기에 코드를 작성해주세요.

    cin >> n >> m >> k;

    for(int iRow = 0 ; iRow < n ; ++iRow)
    {
        for(int iCol = 0 ; iCol < n ; ++iCol)
        {
            cin >> matrix[iRow][iCol];
        }
    }

    Solve();

    return 0;
}

/*

정사각형 격자가 주어진다.

행 기준으로 M개 이상의 같은 숫자가 적혀 있으면 폭탄은 터진다.
M개 이상인 폭탄들의 쌍이 여러개라면 동시에 터져야 한다. -> BOOM 처리후 DROP

위의 과정을 반복하면서, 더이상 터지지 않는 상태까지 반복한다.

그리고 시계방향으로 90도 회전시킨다.

위 과정을 K번 반복 했을 때, 최종적으로 상자에 남아있는 폭탄의 수를 출력하라.

tmp 2차원배열
visit 2차원배열
topRows 1차원배열


Boom
Gravity
Rotate


1 3 1
2 1 2
3 1 1


3 2 1
1 1 3
1 2 1

(0, 0) -> (0, 2)
(0, 1) -> (1, 1)
(0, 2) -> (2, 0)

(1, 0) -> (0, 1)
(1, 1) -> (1, 1)
(1, 2) -> (2, 1)


( x, (n-1) - y )



1 0 1
2 0 2
3 3 1

3 2 1
3 0 0
1 2 1

3 0 0
3 2 1
1 2 1


3410
1200
0000
0000

34
121

*/