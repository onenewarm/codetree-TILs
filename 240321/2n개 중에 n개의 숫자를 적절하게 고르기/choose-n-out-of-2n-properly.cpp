#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int n;
vector<int> nums;

int sum = 0;

int resDistance = 2147483647;

void FindMinDistance(int selectCnt, int curSum, int curIdx)
{
    if(selectCnt == n)
    {
        int oppositeSum = sum - curSum;
        resDistance = min(resDistance, abs(curSum - oppositeSum));
        return;
    }

    if(selectCnt + 1 + (2*n - (curIdx + 1)) >= n)
        FindMinDistance(selectCnt + 1, curSum + nums[curIdx], curIdx + 1);

    if(selectCnt + (2*n - (curIdx + 1)) >= n)
        FindMinDistance(selectCnt, curSum, curIdx + 1);
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n;

    for(int iCnt = 0 ; iCnt < 2 * n ; ++iCnt)
    {
        int num;
        cin >> num;
        nums.push_back(num);
        sum += num;
    }

    FindMinDistance(0, 0, 0);

    cout << resDistance;


    return 0;
}