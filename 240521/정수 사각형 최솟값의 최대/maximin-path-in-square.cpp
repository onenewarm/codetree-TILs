#include <iostream>

using namespace std;

#define INF 2147483647

int N;
int matrix[101][101];
int dp[101][101];

int DFS(int iRow, int iCol)
{
    if(dp[iRow][iCol] != INF) return dp[iRow][iCol];

    int maxOfMinVal = max(DFS(iRow -1, iCol), DFS(iRow, iCol -1));

    return dp[iRow][iCol] =  min(matrix[iRow][iCol], maxOfMinVal);
}

int main() {
    // 여기에 코드를 작성해주세요.

    cin >> N;

    for(int iRow = 1; iRow <= N ; ++iRow)
    {
        for (int iCol = 1; iCol <=N ; ++iCol)
        {
            cin >> matrix[iRow][iCol];
            dp[iRow][iCol] = INF;
        }
    }

    int tmp = INF;

    for(int iRow = 1 ; iRow <= N ; ++iRow)
    {
        tmp = min(tmp, matrix[iRow][1]);
        dp[iRow][1] = tmp;
    }

    tmp = INF;

    for(int iCol = 1 ; iCol <= N ; ++iCol)
    {
        tmp = min(tmp, matrix[1][iCol]);
        dp[1][iCol] = tmp;
    }

    int ans = DFS(N,N);

    cout << ans;

    return 0;
}