#include <iostream>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.

    int n;
    int x[101];
    int y[101];

    cin >> n;

    for(int iCnt = 0 ; iCnt < n ;++iCnt)
    {
        cin >> x[iCnt] >> y[iCnt];
    }

    int ans = 2147483647;

    for(int iCnt1 = 0; iCnt1 < n ;++iCnt1)
    {
        for(int iCnt2 = iCnt1 + 1; iCnt2 < n ; ++iCnt2)
        {
            int distanceX = (x[iCnt1] - x[iCnt2]) * (x[iCnt1] - x[iCnt2]);
            int distanceY = (y[iCnt1] - x[iCnt2]) * (y[iCnt1] - y[iCnt2]);

            ans = min(ans, distanceX + distanceY);
        }
    }

    cout << ans;

    return 0;
}