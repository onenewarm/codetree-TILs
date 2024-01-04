#include <iostream>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n;
    cin >> n;

    int ans = 0;

    int nums[101];

    for(int iCnt = 0 ; iCnt < n ; ++iCnt)
    {
        cin >> nums[iCnt];
    }

    for(int itemA = 0; itemA < n;++itemA)
    {
        for(int itemB = itemA+2;itemB<n;++itemB)
        {
            ans = max(ans, nums[itemA] + nums[itemB]);
        }
    }

    cout << ans;

    return 0;
}