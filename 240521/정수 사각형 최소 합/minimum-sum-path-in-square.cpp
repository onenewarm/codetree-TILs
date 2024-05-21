#include <iostream>

using namespace std;

int N;

int matrix[101][101];
int dp[101][101];


int DFS(int Row, int Col)
{
    if(dp[Row][Col] != -1) return dp[Row][Col];

    return dp[Row][Col] = min(DFS(Row, Col + 1), DFS(Row - 1, Col)) + matrix[Row][Col];
}


int main() {
    // 여기에 코드를 작성해주세요.
    cin >> N;

    for(int Row = 1; Row <= N ; ++Row)
    {
        for(int Col = 1; Col <= N ; ++Col)
        {
            cin >> matrix[Row][Col];
            dp[Row][Col] = -1;
        }
    }

    int tmp = 0;

    for(int Row = 1; Row <= N ; ++Row)
    {
        tmp += matrix[Row][N];
        dp[Row][N] = tmp; 
    }

    tmp = 0;

    for(int Col = N ; Col >= 1; --Col)
    {
        tmp += matrix[1][Col];
        dp[1][Col] = tmp;
    }

    int ans = DFS(N, 1);

    cout << ans;

    return 0;
}