#include <iostream>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.

    int N;
    cin >> N;

    int cowsHeight[101];

    for(int iCnt = 1; iCnt < N+1;++iCnt)
    {
        cin >> cowsHeight[iCnt];
    }

    int ans = 0;

    for(int iA = 1 ; iA < N - 1 ; ++iA)
    {
        for(int iB = iA + 1 ; iB < N ; ++iB)
        {
            for(int iC = iB + 1 ; iC < N + 1 ; ++iC)
            {
                if(cowsHeight[iA] <= cowsHeight[iB] && cowsHeight[iB] <= cowsHeight[iC]) ++ans;
            }
        }
    }

    cout << ans;

    return 0;
}