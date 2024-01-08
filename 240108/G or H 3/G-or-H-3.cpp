#include <iostream>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.

    char people[10001] = {0, };

    int n, k;
    cin >> n >> k;

    k++;

    char scoreSums[10001] = {0, };
    for(int iCnt = 0; iCnt < n ; ++iCnt)
    {
        int x;
        char sign;
        cin >> x >> sign;
        people[x] = sign;
    }

    for(int iCnt = 1; iCnt < 10001 ;++iCnt)
    {
        scoreSums[iCnt] = scoreSums[iCnt - 1];
        if(people[iCnt] != 0 ) scoreSums[iCnt] += (people[iCnt] - 'G' + 1);
    }

    int ans = 0;

    for(int iCnt = 1; iCnt <= 10001 - k ; ++iCnt)
    {
        ans = max(ans, scoreSums[iCnt + k - 1] - scoreSums[iCnt - 1]);
    }

    cout << ans;

    return 0;
}