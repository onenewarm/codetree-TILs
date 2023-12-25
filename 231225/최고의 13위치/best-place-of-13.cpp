#include <iostream>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.

    int N;
    cin >> N;
    int coinsFlag[20][20];

    for(int iRow = 0 ; iRow < N ; ++iRow)
    {
        for(int iCol = 0 ; iCol < N ; ++iCol)
        {
            cin >> coinsFlag[iRow][iCol];
        }
    }

    int ans = 0;

    for(int iRow = 0 ; iRow < N ; ++iRow)
    {
        for(int iCol = 0; iCol < N - 2 ; ++iCol)
        {
            int curCoins = coinsFlag[iRow][iCol] + coinsFlag[iRow][iCol+1] + coinsFlag[iRow][iCol+2];
            ans = max(ans, curCoins);
        }
    }

    cout << ans;

    return 0;
}