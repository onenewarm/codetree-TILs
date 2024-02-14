#include <iostream>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.

    int n = 0;
    char A[11];

    cin >> A;
    char* p = A;
    while(*p != '\0')
    {
        ++n;
        ++p;
    }

    int res = 2147483647;

    for(int startIdx = 0; startIdx < n ; ++startIdx)
    {
        char B[11];
        for(int iCnt = 0; iCnt < n ; ++iCnt)
        {
            B[iCnt] = A[(startIdx + iCnt) % n];
        }

        int strLen = 2;
        char prevCh = B[0];

        for(int iCnt = 1 ;iCnt < n ;++iCnt)
        {
            if(prevCh != B[iCnt])
            {
                strLen += 2;
                prevCh = B[iCnt];
            }
        }

        if(n == 10 && strLen == 2) strLen += 1;

        res = min(res, strLen);
    }

    cout << res;

    return 0;
}

/*
고급요구사항 :
길이가 n인 문자열 A가 있다.
특정 횟수만큼 오른쪽으로 shift한다.

*/