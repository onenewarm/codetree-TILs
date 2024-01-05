#include <iostream>

using namespace std;

int dy[8] = {-1,-1,-1, 0, 0, 1, 1, 1};
int dx[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

int main() {
    // 여기에 코드를 작성해주세요.
    int n,m;

    cin >> n >> m;

    char strGrid[51][51];

    for(int iRow = 0; iRow < n; ++iRow)
    {
        cin >> strGrid[iRow];
    }

    int ans = 0;

    for(int iRow = 0; iRow < n ;++iRow)
    {
        for(int iCol = 0;iCol < m ;++iCol)
        {
            if(strGrid[iRow][iCol] == 'L')
            {
                for(int iCnt = 0; iCnt < 8 ;++iCnt)
                {
                    int nextY = iRow + dy[iCnt];
                    int nextX = iCol + dx[iCnt];

                    if(nextY < 0 || nextX < 0 || nextY > n-1 || nextX > m-1
                    || strGrid[nextY][nextX] != 'E') continue;

                    nextY += dy[iCnt];
                    nextX += dx[iCnt];

                    if(nextY < 0 || nextX < 0 || nextY > n-1 || nextX > m-1
                    || strGrid[nextY][nextX] != 'E') continue;

                    ++ans;
                }
            }
        }
    }

    cout << ans;

    return 0;
}