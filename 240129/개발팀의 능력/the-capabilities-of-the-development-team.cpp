#include <iostream>

using namespace std;

const int INVALID_ANS = 2147483647;

bool DuplicateChk(int* teamScore)
{

    for(int iTeam = 0 ; iTeam < 3 ; ++iTeam)
    {
        for(int iCmp = iTeam + 1; iCmp < 3 ; ++iCmp)
        {
            if(teamScore[iTeam] == teamScore[iCmp]) return false;
            for(int iCmp2 = iCmp + 1; iCmp2 < 3 ; ++iCmp2)
            {
                if(teamScore[iCmp] == teamScore[iCmp2]) return false;
                
            }
        }
    }
    return true;
}

int main() {
    // 여기에 코드를 작성해주세요.

    int teamScore[3];

    int developer[5];

    int totalScore = 0;


    for(int iCnt = 0; iCnt < 5 ; ++iCnt)
    {
        cin >> developer[iCnt];
        totalScore += developer[iCnt];
    }

    int developerVisit[5] = {0, };

    int ans = INVALID_ANS;

    for(int A = 0; A < 5 ; ++A)
    {
        developerVisit[A] = 1;
        for(int B = 0 ; B < 5 ;++B)
        {
            if(developerVisit[B] == 1) continue;
            developerVisit[B] = 1;
            for(int C = 0 ; C < 5 ;++C)
            {
                if(developerVisit[C] == 1) continue;
                
                teamScore[0] = developer[A] + developer[B];
                teamScore[1] = developer[C];
                teamScore[2] = totalScore - teamScore[0] - teamScore[1];

                bool PossibleFlag = DuplicateChk(teamScore);

                if(PossibleFlag == true)
                {
                    int maxScore = max(teamScore[0],teamScore[1]);
                    maxScore = max(maxScore, teamScore[2]);

                    int minScore = min(teamScore[0], teamScore[1]);
                    minScore = min(minScore, teamScore[2]);

                    ans = min(ans,maxScore - minScore);
                }
            }
            developerVisit[B] = 0;
        }
        developerVisit[A] = 0;
    }

    if(ans == INVALID_ANS) cout << -1;
    else cout << ans;

    return 0;
}

/*

큰 틀 :
5명의 점수가 있다. 점수는 정수이다.
2, 2, 1 으로 팀을 이룬다. 팀의 점수 수치는 사람 각각의 점수를 합한 값이다.
최대 능력의 팀과 최소 능력의 팀 간의 능력 차이가 최소가 되도록 만들어라.
모든 팀의 능력치는 서로 달라야 한다.


입력 :
5명의 능력치가 주어진다. 1 ~ 1000

출력 :
모든 팀의 능력치가 서로 다르게 만들 수 없다면 -1을 리턴한다.
최대 능력치 팀과 최소 능력치 팀의 차이를 출력한다.

로직 :
4중 for문으로 2개의 팀을 만든다.


*/