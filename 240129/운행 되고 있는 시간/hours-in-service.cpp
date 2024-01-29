#include <iostream>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.

    int N;
    cin >> N;

    int start[101];
    int end[101];

    for(int iCnt = 0 ; iCnt < N ; ++iCnt)
    {
        cin >> start[iCnt] >> end[iCnt];
    }

    int ans = 0;

    for(int iCnt = 0; iCnt < N ;++iCnt)
    {
        int accum[1001] = {0,};
        for(int iCnt2 = 0 ; iCnt2 < N ;++iCnt2)
        {
            if(iCnt == iCnt2) continue;
            for(int iRange = start[iCnt2] ; iRange < end[iCnt2] ; ++iRange)
            {
                accum[iRange]++;
            }
        }

        int cnt = 0;
        for(int iAccum = 0 ; iAccum < 1001 ; ++iAccum)
        {
            if(accum[iAccum] > 0) ++cnt;
        }

        ans = max(ans, cnt);
    }

    cout << ans;

    return 0;
}