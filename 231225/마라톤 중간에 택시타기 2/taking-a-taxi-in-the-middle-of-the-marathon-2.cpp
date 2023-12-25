#include <iostream>
#include <cmath>

using namespace std;

struct Pos
{
    int x;
    int y;
};

int main() {
    // 여기에 코드를 작성해주세요.
    int n;
    cin >> n;

    Pos checkPoint[100];

    for(int iCnt = 0; iCnt < n ;++iCnt)
    {
        cin >> checkPoint[iCnt].x >> checkPoint[iCnt].y;
    }

    int ans = 1 << 30;

    for(int iDel = 1 ; iDel < n-1 ; ++iDel)
    {
        int curDistance = 0;
        for(int iCnt = 0; iCnt < n-1; ++iCnt)
        {
            int iOperand = iCnt+1;

            if(iCnt == iDel) continue;
            if(iOperand == iDel) ++iOperand;

            curDistance = curDistance + (abs(checkPoint[iCnt].x - checkPoint[iOperand].x) +
                                                abs(checkPoint[iCnt].y - checkPoint[iOperand].y));
        }
        ans = min(ans, curDistance);
    }

    cout << ans;

    return 0;
}