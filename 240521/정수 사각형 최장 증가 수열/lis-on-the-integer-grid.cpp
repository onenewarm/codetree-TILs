#include <iostream>

using namespace std;

int n;
int matrix[501][501];
int dp[501][501];

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1 ,1, 0, 0};

int DFS(int iRow, int iCol)
{
    if(dp[iRow][iCol] != -1) return dp[iRow][iCol];

    int moveCnt = 1;

    for(int iDir = 0 ; iDir < 4 ; ++iDir)
    {
        int iNextRow = iRow + dy[iDir];
        int iNextCol = iCol + dx[iDir];

        if(iNextRow < 1 || iNextCol < 1 || iNextRow > n || iNextCol > n
        || matrix[iRow][iCol] >= matrix[iNextRow][iNextCol]) continue;

        int iCurDirMoveCnt = DFS(iNextRow, iNextCol) + 1;

        moveCnt = max(moveCnt, iCurDirMoveCnt);
    }

    return dp[iRow][iCol] = moveCnt;
}

int main() {
    // 여기에 코드를 작성해주세요.

    cin >> n;

    for(int iRow = 1 ; iRow <= n ; ++iRow)
    {
        for(int iCol = 1 ; iCol <= n ; ++iCol)
        {
            cin >> matrix[iRow][iCol];
            dp[iRow][iCol] = -1;
        }
    }

    int ans = 0;

    for(int iRow = 1 ; iRow <=n ;++iRow)
    {
        for(int iCol = 1; iCol <=n ;++iCol)
        {
            ans = max(ans,DFS(iRow,iCol));
        }
    }

    cout << ans;


    return 0;
}