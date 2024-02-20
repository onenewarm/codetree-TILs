#include <iostream>
#include <cstring>

using namespace std;

int matrix[50][50];
int tmp[50][50];
int res[50][50];
int n;

int dy[4] = { -1, 1, 0, 0};
int dx[4] = { 0, 0, -1, 1};

int maxVal = 0;

void Bomb(int y, int x)
{
    memcpy(res, matrix, 4*50*50);

    int num = matrix[y][x];

    res[y][x] = 0;

    for(int boomSize = 1 ; boomSize < num ; ++boomSize)
    {
        for(int iCnt = 0 ; iCnt < 4 ; ++iCnt)
        {
            int nextY = y + dy[iCnt] * boomSize;
            int nextX = x + dx[iCnt] * boomSize;
        
            if(nextY < 0 || nextX < 0 || nextY > n -1 || nextX > n -1) continue;
            res[nextY][nextX] = 0;
        }
    }

}

void Gravity()
{
    memset(tmp, 0, 4*50*50);
    for(int iCol = 0 ; iCol < n ; ++iCol)
    {
        int curRow = n-1;
        for(int iRow = n -1 ; iRow >= 0 ; --iRow)
        {
            if(res[iRow][iCol])
            {
                tmp[curRow--][iCol] = res[iRow][iCol];
            }
        }
    }

    for(int iRow = 0 ; iRow < n ; ++iRow)
    {
        for(int iCol = 0 ; iCol < n ; ++iCol)
        {
            res[iRow][iCol] = tmp[iRow][iCol];
        }
    }
}

void GetCouple()
{
    char visit[50][50][4] = {};

    int cnt = 0;

    for(int iRow = 0 ; iRow < n ; ++iRow)
    {
        for(int iCol = 0 ; iCol < n ; ++iCol)
        {
            if(res[iRow][iCol] == 0) continue;

            for(int iCnt = 0 ; iCnt < 4 ; ++iCnt)
            {
                if(visit[iRow][iCol][iCnt] == true) continue;

                int nextY = iRow + dy[iCnt];
                int nextX = iCol + dx[iCnt];

                int visitIdx;

                switch(iCnt)
                {
                    case 0:
                        visitIdx = 1;
                        break;
                    case 1:
                        visitIdx = 0;
                        break;
                    case 2:
                        visitIdx = 3;
                        break;
                    case 3:
                        visitIdx = 2;
                        break;
                }

                if(nextY < 0 || nextX < 0 || nextY > n-1 || nextX > n-1 || visit[nextY][nextX][visitIdx]) continue;
                
                if(res[iRow][iCol] == res[nextY][nextX]) ++cnt;
                visit[iRow][iCol][iCnt] = true;
                visit[nextY][nextX][visitIdx] = true;
            }
        }
    }
    maxVal = max(maxVal, cnt);    
}

void Solve()
{
    
    for(int iRow = 0 ; iRow < n ; ++iRow)
    {
        for(int iCol = 0 ; iCol < n ; ++iCol)
        {
            Bomb(iRow, iCol);
            Gravity();
            // for(int _iRow = 0 ; _iRow < n ; ++_iRow)
            // {
            //     for(int _iCol = 0 ; _iCol < n ;++_iCol)
            //     {
            //         cout << res[_iRow][_iCol] << ' ';
            //     }
            //     cout << '\n';
            // }
            // cout << '\n';
            
            GetCouple();
        }
    }

    cout << maxVal;
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n;

    for(int iRow = 0 ; iRow < n ; ++iRow)
    {
        for(int iCol = 0 ; iCol < n ;++iCol)
        {
            cin >> matrix[iRow][iCol];
        }
    }

    Solve();

    return 0;
}

/*

정사각형 격자가 주어진다.
특정 위치를 선택한다.
선택 위치의 값 크기의 십자 모양 폭탄이 터진다.
중력에 의해서 숫자들이 아래로 떨어진다.

최적의 십자모양 폭발
특정 위치를 선택 했을 때, 폭탄이 터진 후 중력이 작용한 이후에
상하좌우로 인접한 격자끼리 적혀있는 숫자가 동일한 쌍의 수가 최대가 되도록 하는 폭발을 의미합니다.

완전탐색을 피할 수 있는 방법이 있는가? 없다 다보아라

tmp 2차원 배열 
dy,dx


Bomb
Gravity
GetCouple

*/