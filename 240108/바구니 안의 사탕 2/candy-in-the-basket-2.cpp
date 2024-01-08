#include <iostream>

using namespace std;

int road[101];

int main() {
    // 여기에 코드를 작성해주세요.

    int n, k;
    cin >> n >> k;

    for(int iCnt = 0; iCnt < n;++iCnt)
    {
        int candiesCnt, pos;
        cin >> candiesCnt >> pos;

        road[pos] += candiesCnt;
    }

    int ans = 0;

// 0 1 2 3 4
    for(int iStart = 0; iStart <= 100 - (2*k) ;++iStart)
    {
        int sum = 0;
        for(int iCnt = 0; iCnt < (2*k+1);++iCnt)
        {
            sum += road[iStart + iCnt];
        }

        ans = max(ans, sum);
    }

    cout << ans;


    return 0;
}