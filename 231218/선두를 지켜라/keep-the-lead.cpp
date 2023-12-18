#include <iostream>
#include <vector>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.

    int N, M;
    cin >> N >> M;

    vector<int> A(1000001, -1);
    vector<int> B(1000001, -1);

    int curX = 0;
    int curH = 0;

    for(int iCnt = 0; iCnt < N ;++iCnt)
    {
        int v, t;
        cin >> v >> t;

        for(int iTime = 0; iTime < t;++iTime)
        {
            curX += v;
            A[curH++] = curX;
        }
    }

    curX = 0;
    curH = 0;

    for(int iCnt = 0; iCnt < M ;++iCnt)
    {
        int v, t;
        cin >> v >> t;

        for(int iTime = 0; iTime < t;++iTime)
        {
            curX += v;
            B[curH++] = curX;
        }

    }

    int ans = -1;

    int first = 0;

    for(int iCnt = 0;iCnt < 1000001;++iCnt)
    {
        if(A[iCnt] == -1) break;

        if(first == 0)
        {
            if(A[iCnt] > B[iCnt])
            {
                ++ans;
                first = 1;
            }
            else if(A[iCnt] < B[iCnt])
            {
                ++ans;
                first = 2;
            }
        }
        else if(first == 1)
        {
            if(B[iCnt] > A[iCnt])
            {
                ++ans;
                first =2;
            }
        }
        else if(first == 2)
        {
            if(A[iCnt] > B[iCnt])
            {
                ++ans;
                first= 1;
            }
        }
    }

    if(ans == -1) cout << 0;
    else cout << ans;

    return 0;
}