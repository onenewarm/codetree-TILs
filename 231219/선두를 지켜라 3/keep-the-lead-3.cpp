#include <iostream>
#include <vector>

using namespace std;

const int OOB = 2100000000;

int main() {
    // 여기에 코드를 작성해주세요.

    int N,M;
    cin >> N >> M;

    vector<int> A(1000001, OOB);
    vector<int> B(1000001, OOB);
    A[0] = 0;
    B[0] = 0;

    int aCurT = 0;
    for(int iCnt = 0; iCnt < N;++iCnt)
    {
        int v, t;
        cin >> v >> t;

        while(t--)
        {
            ++aCurT;
            A[aCurT] = A[aCurT-1] + v;
        }
    }

    int bCurT = 0;
    for(int iCnt = 0; iCnt < N;++iCnt)
    {
        int v, t;
        cin >> v >> t;

        while(t--)
        {
            ++bCurT;
            B[bCurT] = B[bCurT-1] + v;
        }
    }

    int first = 0;
    int ans = 0;

    for(int iCnt = 1; iCnt < 1000001;++iCnt)
    {
        if(A[iCnt] == OOB) break;
        
        int curFirst;
        if(A[iCnt] == B[iCnt]) curFirst = 0;
        else if(A[iCnt] > B[iCnt]) curFirst = 1;
        else if(A[iCnt] < B[iCnt]) curFirst = 2;

        if(first != curFirst)
        {
            ++ans;
            first = curFirst;
        }
    }

    cout << ans;

    return 0;
}

/*

A와 B가 동일한 시작점에서 출발한다.
도중에 방향을 바꾸는 일을 없고 N,M번에 대하여 주어지는 특정 속도로 특정 시간만큼 이동한다.
매 시간마다 선두인 사람들을 모아서 명예의 전당에 이름을 올린다.
A,B 움직임에 대한 정보가 주어졌을 때 명예의 전당에 올라간 사람의 조합이 총 몇 번 바뀌었는지를 출력하라.

*/