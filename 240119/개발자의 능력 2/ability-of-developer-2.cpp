#include <iostream>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int developers[6];

    for(int iCnt = 0 ; iCnt < 6 ; ++iCnt)
    {
        cin >> developers[iCnt];
    }

    for(int iCnt = 0 ; iCnt < 5 ; ++iCnt)
    {
        for(int iCmp = 0; iCmp < 5 - iCnt ; ++iCmp)
        {
            if(developers[iCmp] > developers[iCmp+1])
            {
                int tmp = developers[iCmp];
                developers[iCmp] = developers[iCmp+1];
                developers[iCmp+1] = tmp;
            }
        }
    }

    int minTeam = 1 << 30;
    int maxTeam = 0;

    // 0 , 5 / 1, 4 / 2, 3

    for(int iCnt = 0 ; iCnt < 3 ; ++iCnt)
    {
        int curTeam = developers[iCnt] + developers[5 - iCnt];
        minTeam = min(minTeam, curTeam);
        maxTeam = max(maxTeam, curTeam);
    }

    cout << maxTeam - minTeam;
    
    return 0;
}

/*

6명을 2명씩 3팀으로 배정한다.
팀원들의 능력 총합이 가장 큰 팀과 가장 작은 팀의 차이를 최소화 할 수 있게 균형있게 구성 할 때의 차를 출력하자.



*/