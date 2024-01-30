#include <iostream>

using namespace std;

struct SickRecord
{
    int p;
    int t;
};

int main() {
    // 여기에 코드를 작성해주세요.

    int N,M,D,S;

    cin >> N >> M >> D >> S;

    int eatingRecord[51][51] = {};
    SickRecord sickRecord[51]; 


    for(int iCnt = 0; iCnt < D ;++iCnt)
    {
        int p,m,t;
        cin >> p >> m >> t;
        eatingRecord[p][m] = t;
    }

    for(int iCnt = 0; iCnt < S ; ++iCnt)
    {
        int p,t;
        cin >> p >> t;
        sickRecord[iCnt] = {p,t};
    }

    int ans = 0;

    int candidatesCheeze[51] = {};

    int prevIdx = 0;

    for(int iCnt = 0 ; iCnt < S ; ++iCnt)
    {
        //p가 먹은 치즈 중에서 t시간 전에 먹은 것을 찾아서 선별한다.
        for(int iCheeze = 1 ; iCheeze <= M ; ++iCheeze)
        {
            if(candidatesCheeze[iCheeze] == prevIdx && eatingRecord[sickRecord[iCnt].p][iCheeze] != 0 &&
            eatingRecord[sickRecord[iCnt].p][iCheeze] < sickRecord[iCnt].t)
            {
                candidatesCheeze[iCheeze] = sickRecord[iCnt].p;
            }
        }

        prevIdx = sickRecord[iCnt].p;
    }

    int visitPerson[51] = {};

    for(int iCheeze = 1; iCheeze <= M ; ++iCheeze)
    {
        if(candidatesCheeze[iCheeze] == prevIdx)
        {
            for(int iPerson = 1; iPerson <= N ;++iPerson)
            {
                if(eatingRecord[iPerson][iCheeze] != 0 && visitPerson[iPerson] == 0)
                {
                    visitPerson[iPerson] = 1;
                    ++ans;
                }
            }   
        }
    }

    cout << ans; 


    return 0;
}

/*

고급 요구사항 :
N명의 사람이 있다. M개의 치즈를 먹어쓴ㄴ데 정확히 하나의 치즈가 상했다는 것을 알았다.
특정 사람이 어떤 치즈를 언제 먹었는지에 대한 기록이 총 D번 주어진다.
특성 사람이 언제 아팠는지에 대한 기록 S번이 주어진다.

완벽하게 기록이 된 것이 아니기 때문에, 아프다고 기록되어 있는 사람 외에 다른 사람도 아플 수 있다.

상한 치즈를 먹은 사람에게 약을 복용시켜야 할 때, 약이 최대 몇 개나 필요한지를 구하자.

상한 치즈를 먹으면 1초가 지나야 아프다.

입력 : 
사람의 수 N ( 1  ~ 50 )
치즈의 수 M ( 1~ 50 )
치즈를 먹은 기록의 수 D ( 1 ~ 1000 )
아픈 기록의 수 S ( 1 ~ N )

D줄의 걸친 기록 :
(p, m, t) : p번째 사람이 m번째 치즈를 t초에 먹었다.

S줄의 걸친 기록 :
(p,t) : p번째 사람이 t초에 아팠다.

*/