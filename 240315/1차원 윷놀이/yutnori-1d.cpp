#include <iostream>
#include <vector>

using namespace std;

int n,m,k;
vector<int> turns;
vector<int> curPos;

int res = 0;

void GetScore()
{
    int score = 0;
    for(int iCnt = 1; iCnt <= k ; ++iCnt)
    {
        if(curPos[iCnt] == m) ++score;
    }

    res = max(res, score);
}

void Move(int moveCnt)
{
    if(moveCnt == n)
    {
        GetScore();
        return;
    }

    for(int iCnt = 1 ; iCnt <= k ; ++iCnt)
    {
        if(curPos[iCnt] == m) continue;

        int prevPos = curPos[iCnt];
        curPos[iCnt] += turns[moveCnt];
        if(curPos[iCnt] > m) curPos[iCnt] = m;
        Move(moveCnt + 1);
        curPos[iCnt] = prevPos;
    }
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n >> m >> k;

    for(int iCnt = 0 ; iCnt < n ; ++iCnt)
    {
        int turn;
        cin >> turn;
        turns.push_back(turn);
    }

    curPos.resize(k+1, 1);

    Move(0);

    cout << res;

    return 0;
}