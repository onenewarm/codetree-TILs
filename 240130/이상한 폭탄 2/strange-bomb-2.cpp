#include <iostream>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int N, K;
    cin >> N >> K;

    int ans = -1;

    int ordered_boom[101];

    for(int iCnt = 0 ; iCnt < N ; ++iCnt)
    {
        cin >> ordered_boom[iCnt];
    }

    for(int iCnt = 0; iCnt < N ; ++iCnt)
    {
        for(int iLeft = 1 ; iLeft <= K ; ++iLeft)
        {
            if(iCnt - iLeft < 0) break;

            if(ordered_boom[iCnt - iLeft] == ordered_boom[iCnt]){
                ans = max(ans, ordered_boom[iCnt]);
                break;
            }

        }

        for(int iRight = 1 ; iRight <= K ; ++iRight)
        {
            if(iCnt + iRight > N - 1) break;

            if(ordered_boom[iCnt + iRight] == ordered_boom[iCnt])
            {
                ans = max(ans, ordered_boom[iCnt]);
                break;
            }
        }
    }

    cout << ans;

    return 0;
}

/*
고급 요구사항 :
폭탄 N개가 있다.
폭탄은 부여된 번호가 있다.
같은 번호가 부여된 폭탄끼리 거리가 K안에 있다면 폭발한다.
폭탄의 개수 N, 특정 거리 K, 폭탄을 나열한 순서가 주어진다.
폭발 할 폭탄 중에 부여된 번호가 가장 큰 번호를 출력해라.

*/