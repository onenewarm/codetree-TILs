#include <iostream>

using namespace std;

int N, M;
int boombs[102];

bool Pang()
{
    int prevNum;
    int topPos = 1;

    while (boombs[topPos] == 0) ++topPos;

    int duplicateCnt = 0;

    bool flag = false;

    int curPos = topPos;

    prevNum = boombs[curPos];

    while (curPos <= N + 1)
    {
        if (prevNum == boombs[curPos])
            ++duplicateCnt;
        else
        {
            if (duplicateCnt >= M)
            {
                flag = true;
                for (int iCnt = 1; iCnt <= duplicateCnt; ++iCnt)
                    boombs[curPos - iCnt] = 0;
            }
            prevNum = boombs[curPos];
            duplicateCnt = 1;
        }
        ++curPos;
    }

    return flag;
}

void Gravity()
{
    int tmp[102] = {};

    int addPos = N;

    for (int iCnt = N; iCnt > 0; --iCnt)
    {
        if (boombs[iCnt] != 0) tmp[addPos--] = boombs[iCnt];
    }

    for (int iCnt = 1 ; iCnt <= N; ++iCnt)
    {
        boombs[iCnt] = tmp[iCnt];
    }
}

void Solve()
{
    while (Pang())
    {
        Gravity();
    }

    int Cnt = 0;

    for (int iCnt = 1; iCnt <= N; ++iCnt)
    {
        if (boombs[iCnt] != 0)
        {
            ++Cnt;
        }
    }

    cout << Cnt << '\n';
    for (int iCnt = 1; iCnt <= N; ++iCnt)
    {
        if (boombs[iCnt] != 0) cout << boombs[iCnt] << '\n';
    }

}

int main() {
    // 여기에 코드를 작성해주세요.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;

    for (int iCnt = 1; iCnt < N + 1; ++iCnt)
    {
        cin >> boombs[iCnt];
    }


    Solve();

    return 0;
}