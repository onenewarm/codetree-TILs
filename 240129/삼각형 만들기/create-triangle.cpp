#include <iostream>
#include <cmath>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.

    int N;

    cin >> N;

    int ans = 0;

    int x[101];
    int y[101];

    for(int iCnt = 0 ; iCnt < N ; ++iCnt)
    {
        cin >> x[iCnt] >> y[iCnt];
    }

    for(int iPoint1 = 0; iPoint1 < N ; ++iPoint1) // 기준이 되는 점
    {
        for(int iPoint2 = 0 ; iPoint2 < N ;++iPoint2)
        {
            if(iPoint1 == iPoint2) continue;
            if(x[iPoint1] != x[iPoint2]) continue;

            for(int iPoint3 = 0 ; iPoint3 < N ;++iPoint3)
            {
                if(iPoint1 == iPoint3 || iPoint2 == iPoint3) continue; 
                if(y[iPoint1] != y[iPoint3]) continue;

                int xlength = abs(y[iPoint1] - y[iPoint2]);
                int ylength = abs(x[iPoint1] - x[iPoint3]);

                ans = max(ans, xlength * ylength);
            }
        }
    }

    cout << ans;

    return 0;
}