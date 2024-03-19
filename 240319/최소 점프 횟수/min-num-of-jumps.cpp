#include <iostream>
#include <vector>

#define INVALID_VALUE 2100000000

using namespace std;

int n;

vector<int> jumps;

int res = INVALID_VALUE;

void Jump(int curPos, int cnt)
{
    if(curPos == n - 1)
    {
        res = min(res, cnt);
        return;
    }

    int maxMoveNum = jumps[curPos];

    if(maxMoveNum == 0) return;

    for(int moveNum = 1 ; moveNum <= maxMoveNum; ++moveNum)
    {
        if(curPos + moveNum > n - 1) continue;
        Jump(curPos + moveNum, cnt + 1);
    }
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n;
    jumps.resize(n);

    for(int iCnt = 0 ; iCnt < n ; ++iCnt) cin >> jumps[iCnt];

    Jump(0, 0);

    cout << res;

    return 0;
}
/*


*/