#include <iostream>
#include <cmath>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.

    int totalSum = 0;

    int algorithmStats[6];

    for(int iCnt = 0; iCnt < 6 ;++iCnt)
    {
        cin >> algorithmStats[iCnt];
        totalSum += algorithmStats[iCnt];
    }

    int ans = 1 << 30;

    for(int iFirst = 0 ; iFirst < 6 ; ++iFirst)
    {
        for(int iSecond = iFirst ; iSecond < 6 ; ++iSecond)
        {
            for(int iThird = iSecond ; iThird < 6 ;++iThird)
            {
                int sum = 0;
                sum = algorithmStats[iFirst] + algorithmStats[iSecond] + algorithmStats[iThird];

                ans = min(ans, abs((totalSum - sum) - sum));
            }
        }
    }

    cout << ans;


    return 0;
}