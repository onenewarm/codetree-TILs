#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    
    int N,B;
    cin >> N >> B;

    vector<int> P(N);

    for(int iCnt = 0; iCnt < N ;++iCnt)
    {
        cin >> P[iCnt];
    }

    sort(P.begin(), P.end());

    int ans = 0;

    for(int iCnt = 0 ; iCnt < N ; ++iCnt)
    {
        if(B - P[iCnt] < 0)
        {
            if(B - (P[iCnt] / 2) >= 0)
            {
                ++ans;
            }
            break;
        }
        else
        {
            ++ans;
            B -= P[iCnt];
        }
    }

    cout << ans;

    return 0;
}

/*
고급 요구사항 :
N명의 학생에게 B만큼의 예산으로 선물을 준다. 돈이 B가 있고, 분배해서 N명의 학생들에게 준다.

하나의 상점에서 사는데 이 상점 물건 하나의 50% 할인쿠폰이 있다.
학생들이 원하는 선물의 가격이 주어진다. 주루루룩

선생님이 선물 가능한 학생의 최대 명수를 구하는 프로그램을 구하여라.

가격이 낮은 순대로 주루루룩 하면 되는거 이닌가?

*/