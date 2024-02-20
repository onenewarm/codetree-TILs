#include <iostream>

using namespace std;

int n,r,c;
int matrix[101][101];
int res[10000];
int resSize = 0;
int dy[4] = {-1 ,1 , 0 , 0};
int dx[4] = { 0 , 0, -1 ,1};


void Solve()
{
    int maxNum = matrix[r][c];

    res[resSize++] = maxNum;

    bool flag = true;

    while(flag)
    {
        flag = false;
        for(int iCnt = 0 ; iCnt < 4 ; ++iCnt)
        {
            int nextY = r + dy[iCnt];
            int nextX = c + dx[iCnt];

            if(nextY < 1 || nextX < 1 || nextY > n || nextX > n) continue;

            if(matrix[nextY][nextX] > maxNum)
            {
                maxNum = matrix[nextY][nextX];
                r = nextY;
                c = nextX;
                res[resSize++] = maxNum;
                flag = true;
                break;
            }
        }
    }

    for(int iCnt = 0; iCnt < resSize; ++iCnt)
    {
        cout << res[iCnt] << ' ';
    }
}

int main() {
    // 여기에 코드를 작성해주세요.

    cin >> n >> r >> c;

    for(int iRow = 1 ; iRow <= n ;++iRow)
    {
        for(int iCol = 1 ; iCol <= n ; ++iCol)
        {
            cin >> matrix[iRow][iCol];
        }
    }

    Solve();


    return 0;
}

/*

정사각형 격자가 주어진다.
더 큰 위치로 끊임없이 이동한다.
상하좌우의 순서대로 확인을 한다.


*/