#include <iostream>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.

    double numArr[101];

    int n;
    cin >> n;

    for(int iCnt = 0; iCnt < n ; ++iCnt)
    {
        cin >> numArr[iCnt];
    }

    int ans = 0;

    for(int iStart = 0; iStart < n; ++iStart)
    {
        for(int iEnd = iStart ; iEnd < n ;++iEnd)
        {
            double sum = 0;
            for(int iNum = iStart ; iNum <= iEnd ; ++iNum)
            {
                sum += numArr[iNum];
            }

            double avg = sum / (iEnd - iStart + 1);

            for(int iNum = iStart ; iNum <= iEnd ; ++iNum)
            {
                if(avg == numArr[iNum])
                {
                    ++ans;
                    break;
                }
            }
        }
    }

    cout << ans;

    return 0;
}