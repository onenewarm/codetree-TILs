#include <iostream>
#include <cmath>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.

    int n, h, t;

    cin >> n >> h >> t;

    int field[101];

    for(int iCnt = 0 ; iCnt < n ; ++iCnt)
    {
        cin >> field[iCnt];
    }

    int ans = (1 << 31) - 1;

    for(int iStart = 0 ; iStart <= n - t ; ++iStart)
    {
        int sum = 0;

        for(int iCnt = 0; iCnt < t; ++iCnt)
        {
            sum += abs(field[iStart + iCnt] - h);
        }

        ans = min(ans, sum);
    }

    cout << ans;

    return 0;
}