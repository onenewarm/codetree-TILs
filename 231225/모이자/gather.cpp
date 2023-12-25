#include <iostream>
#include <cmath>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n;
    int peopleNums[101];

    cin >> n;

    for(int iCnt = 1;iCnt < n+1; ++iCnt)
    {
        cin >> peopleNums[iCnt];
    }

    int ans = 1 << 30;

    for(int iStd = 1;iStd < n+1;++iStd)
    {
        int curAns = 0;
        for(int iCnt = 1;iCnt <n+1;++iCnt)
        {
            curAns += abs(iStd - iCnt) * peopleNums[iCnt];
        }
        ans = min(ans, curAns);
    }

    cout << ans;

    return 0;
}

/*

모든 사람들의 이동 거리의 합이 최소가 되는 것을 원한다.


*/