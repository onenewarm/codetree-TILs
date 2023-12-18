#include <iostream>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n;
    cin >> n;

    int cnt = 1;
    int ans = 0;

    int arrNums[1001];

    for(int iCnt = 0; iCnt < n;++iCnt)
    {
        cin >> arrNums[iCnt];
    }

    for(int iCnt = 1; iCnt < n;++iCnt)
    {
        if(arrNums[iCnt] > arrNums[iCnt-1]) ++cnt;
        else
        {
            ans = max(ans, cnt);
            cnt = 1;
        }
    }
    ans = max(ans, cnt);

    cout << ans;

    return 0;
}