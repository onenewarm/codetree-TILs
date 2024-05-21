#include <iostream>

using namespace std;

int N;

int matrix[101][101];

int dp[101][101];

int DFS(int Row, int Col)
{
    if(dp[Row][Col] != -1) return dp[Row][Col];

    dp[Row][Col] = max(DFS(Row-1,Col), DFS(Row,Col-1)) + matrix[Row][Col];

    return dp[Row][Col];
}


int main() {
    // 여기에 코드를 작성해주세요.

    cin >> N;

    for(int Row = 1 ; Row <= N ; ++Row)
    {
        for(int Col = 1; Col <= N ; ++Col)
        {
            cin >> matrix[Row][Col];
            dp[Row][Col] = -1;
        }
    }

    int tmpVal = 0;

    for(int Row = 1 ; Row <= N ; ++Row)
    {
        tmpVal += matrix[Row][1];
        dp[Row][1] = tmpVal;
    }

    tmpVal = 0;

    for(int Col = 1 ; Col <= N ; ++Col)
    {
        tmpVal += matrix[1][Col];
        dp[1][Col] = tmpVal;
    }

    int ans = DFS(N,N);

    cout << ans;

    return 0;
}

// d(x,y) = max(d(x, y-1), d(x-1, y)) + matrix[y][x]