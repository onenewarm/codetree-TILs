#include <iostream>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.

    int n, k;
    cin >> n >> k;

    int arr[101];

    for(int iCnt = 0; iCnt < n ; ++iCnt)
    {
        cin >> arr[iCnt];
    }

    int ans = 0;

    for(int iCnt = 0; iCnt < n - k ; ++iCnt)
    {
        int sum = 0;
        for(int iNum = iCnt; iNum < iCnt+k;++iNum)
        {
            sum += arr[iNum];
        }
        ans = max(ans, sum);
    }

    cout << ans;

    return 0;
}