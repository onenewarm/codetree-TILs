#include <iostream>
#include <cmath>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.

    int N;

    cin >> N;

    int comb[2][3];

    for(int iCnt = 0; iCnt < 2; ++iCnt)
    {
        for(int iPos = 0; iPos < 3 ; ++iPos)
        {
            cin >> comb[iCnt][iPos];
        }
    }

    int ans = 0;

    for(int First = 1 ; First <= N ; ++First)
    {
        for(int Second = 1 ; Second <= N; ++Second)
        {
            for(int Third = 1 ; Third <= N ; ++Third)
            {
                for(int iCnt = 0; iCnt < 2 ;++iCnt)
                {
                    if((abs(comb[iCnt][0] - First) <= 2 || abs(comb[iCnt][0] - First) >= N-2) &&
                    (abs(comb[iCnt][1] - Second) <= 2 || abs(comb[iCnt][1] - Second) >= N-2) &&
                    (abs(comb[iCnt][2] - Third) <= 2 || abs(comb[iCnt][2] - Third) >= N-2))
                    {
                        ++ans;
                        break;
                    }
                }
            }
        }
    }

    cout << ans;

    return 0;
}