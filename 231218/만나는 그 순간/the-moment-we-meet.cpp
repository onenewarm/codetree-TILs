#include <iostream>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int N,M;

    cin >> N >> M;

    int A[1000001];
    int B[1000001];

    for(int iCnt = 0 ; iCnt < 1000001;++iCnt)
    {
        A[iCnt] = -2000;
        B[iCnt] = -2000;
    }

    int curX = 0;
    int curSec = 0;

    for(int iCnt = 0; iCnt < N ;++iCnt)
    {
        char dir;
        int sec;
        cin >> dir >> sec;

        if(dir == 'R')
        {
            for(int iSec = 0; iSec < sec; ++iSec)
            {
                A[++curSec] = --curX;
            }
        }
        else
        {
            for(int iSec = 0; iSec < sec; ++iSec)
            {
                A[++curSec] = ++curX;
            }
        }
    }

    curX = 0;
    curSec = 0;

    for(int iCnt = 0; iCnt < M ;++iCnt)
    {
        char dir;
        int sec;
        cin >> dir >> sec;

        if(dir == 'R')
        {
            for(int iSec = 0; iSec < sec; ++iSec)
            {
                B[++curSec] = --curX;
            }
        }
        else
        {
            for(int iSec = 0; iSec < sec; ++iSec)
            {
                B[++curSec] = ++curX;
            }
        }
    }

    for(int iCnt = 1; iCnt < 1001;++iCnt)
    {
        if(A[iCnt] == B[iCnt] && A[iCnt] != -2000)
        {
            cout << iCnt;
            return 0;
        }
    }

    cout << -1;
    return 0;
}