#include <iostream>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.

    int n;

    cin >> n;

    int nums[21];

    for(int iCnt = 0; iCnt < n;++iCnt)
    {
        cin >> nums[iCnt];
    }

    int ans = -1;

    for(int iFirst = 0; iFirst < n - 2;++iFirst)
    {
        for(int iSecond = iFirst+1;iSecond < n - 1; ++iSecond)
        {
            for(int iThird = iSecond+1;iThird < n ; ++iThird)
            {
                int modVal = 10;
                
                int First = nums[iFirst];
                int Second = nums[iSecond];
                int Third = nums[iThird];

                bool isPossible = true;

                while(First | Second | Third)
                {
                    int tmpSum = (First % modVal) + (Second % modVal) + (Third % modVal);

                    if(tmpSum >= 10){
                        isPossible = false;
                        break;
                    }

                    First /= 10;
                    Second /= 10;
                    Third /= 10;
                }

                if(isPossible) ans = max(ans, nums[iFirst] + nums[iSecond] + nums[iThird]);
            }
        }
    }

    cout << ans;

    return 0;
}