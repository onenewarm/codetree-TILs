#include <iostream>
#include <vector>
#define OOR 2147483647

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.

    vector<int> A(1000001, OOR);
    vector<int> B(1000001, OOR);
    A[0] = 0;
    B[0] = 0;

    int n,m;
    cin >> n >> m;

    int iA = 0;
    for(int iCnt = 0 ; iCnt < n; ++iCnt)
    {
        int t;
        char d;
        cin >> t >> d;

        int v;

        if(d == 'L') v = -1;
        else v = 1;

        while(t--)
        {
            iA++;
            A[iA] = A[iA-1] + v;
        }
    }

    int iB = 0;
    for(int iCnt = 0 ; iCnt < m; ++iCnt)
    {
        int t;
        char d;
        cin >> t >> d;

        int v;

        if(d == 'L') v = -1;
        else v = 1;

        while(t--)
        {
            iB++;
            B[iB] = B[iB-1] + v;
        }
    }

    if(iA > iB)
    {
        int t = iA - iB;
        while(t--)
        {
            iB++;
            B[iB] = B[iB-1];
        }
    }
    else if(iA < iB)
    {
        int t = iB - iA;
        while(t--)
        {
            iA++;
            A[iA] = A[iA-1];
        }
    }

    int ans = 0;
    for(int iCnt = 1; iCnt < 1000001;++iCnt)
    {
        if(A[iCnt] == OOR) break;

        if(A[iCnt-1] != B[iCnt-1])
        {
            if(A[iCnt] == B[iCnt]) ++ans;
        }
    }

    cout << ans;

    return 0;
}