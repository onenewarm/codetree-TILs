#include <iostream>
#include <algorithm>


using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.

    int n,m;
    cin >> n >> m;

    int arrA[101];
    int arrB[101];

    for(int iCnt = 0; iCnt < n ; ++iCnt)
    {
        cin >>arrA[iCnt];
    }

    for(int iCnt = 0; iCnt < m ; ++iCnt)
    {
        cin >> arrB[iCnt];
    }

    sort(arrB, arrB + m);
    int ans = 0;

    for(int iA = 0; iA <= n - m ;++iA)
    {
        int tmpArr[m];
        for(int iCnt = 0; iCnt < m;++iCnt)
        {
            tmpArr[iCnt] = arrA[iA + iCnt];   
        }
        sort(tmpArr, tmpArr + m);

        bool flag = true;

        for(int iCnt = 0; iCnt < m;++iCnt)
        {
            if(tmpArr[iCnt] != arrA[iA + iCnt])
            {
                flag = false;
                break;
            }
        }

        if(flag) ++ans;
    }

    cout << ans;

    return 0;
}