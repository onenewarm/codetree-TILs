#include <iostream>
#include <cmath>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.

    int N;
    cin >> N;

    int nums[3];

    for(int iCnt = 0; iCnt < 3 ;++iCnt)
    {
        cin >> nums[iCnt];
    }

    int ans = 0;

    for(int iFirst = 1 ; iFirst <= N ; ++iFirst)
    {
        for(int iSecond = 1 ; iSecond <= N ; ++iSecond)
        {
            for(int iThird = 1 ; iThird <= N ; ++iThird)
            {
                if(abs(nums[0] - iFirst) <= 2) ++ans;
                else if(abs(nums[1] - iSecond) <= 2) ++ans;
                else if(abs(nums[2] -iThird) <= 2) ++ans;
            }
        }
    }

    cout << ans;

    return 0;
}