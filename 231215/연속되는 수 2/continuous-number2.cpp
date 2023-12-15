#include <iostream>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.

    int ans = 0;
    int cnt = 0;

    int n ;
    int nums[1001];

    cin >> n;
    for(int iCnt = 0 ;iCnt < n;++iCnt)
    {
        cin >> nums[iCnt];
    }

    for(int iCnt = 0; iCnt < n ; ++iCnt)
    {
        if(iCnt == 0)
        {
            cnt = 1;
            ans = 1;
        }
        else
        {
            if(nums[iCnt-1] == nums[iCnt]) ++cnt;
            else
            {
                ans = max(ans, cnt);
                cnt = 1;
            }
        }
    }

    cout << ans;

    return 0;
}