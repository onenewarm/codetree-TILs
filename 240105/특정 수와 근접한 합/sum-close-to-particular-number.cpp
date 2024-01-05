#include <iostream>
#include <cmath>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.

    int s,n;

    cin >> n >> s;

    int totalSum = 0;

    int nums[101];

    int distance = 1 << 30;

    for(int iCnt = 0; iCnt < n ;++iCnt)
    {
        cin >> nums[iCnt];
        totalSum += nums[iCnt];
    }

    for(int iFirst = 0; iFirst < n - 1 ;++iFirst)
    {
        for(int iSecond = iFirst + 1 ; iSecond < n ;++iSecond)
        {
            int cmpVal = totalSum - nums[iFirst] - nums[iSecond];

            distance = min(distance, abs(s-cmpVal));
        }
    }

    cout << distance;

    return 0;
}