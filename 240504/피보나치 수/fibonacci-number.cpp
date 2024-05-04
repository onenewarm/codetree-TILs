#include <iostream>

using namespace std;

int dp[46];

int n;

int main() {
    // 여기에 코드를 작성해주세요.

    cin >> n;

    dp[1] = 1;
    dp[2] = 1;

    for(int iCnt = 3; iCnt <= n ; ++iCnt)
    {
        dp[iCnt] = dp[iCnt - 2] + dp[iCnt - 1]; 
    }

    cout << dp[n];

    return 0;
}