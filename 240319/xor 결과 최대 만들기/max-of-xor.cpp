#include <iostream>
#include <vector>

using namespace std;

int n,m;
vector<int> nums;
vector<int> curNums;

int res = -1;

void GetVal(int cnt, int nextIdx)
{
    if(cnt == m)
    {
        int curRes = curNums[0];

        for(int iCnt = 1 ; iCnt < m ; ++iCnt)
        {
            curRes ^= curNums[iCnt];
        }

        res = max(res, curRes);
        return;
    }
    else if(nextIdx == n) return;

    curNums.push_back(nums[nextIdx]);
    GetVal(cnt + 1, nextIdx + 1);
    curNums.pop_back();
    GetVal(cnt, nextIdx + 1);
}

int main() {
    // 여기에 코드를 작성해주세요.

    cin >> n >> m;
    nums.resize(n);

    for(int iCnt = 0 ; iCnt < n ; ++iCnt)
    {
        cin >> nums[iCnt];
    }

    GetVal(0, 0);
    cout << res;

    return 0;
}