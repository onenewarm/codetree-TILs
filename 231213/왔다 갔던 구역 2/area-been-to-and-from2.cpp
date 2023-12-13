#include <iostream>
#define OFFSET 1000
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int arr[2001] = {0, };
    int curX = 1000;
    int n;
    cin >> n;
    for(int iCnt = 0; iCnt < n ;++iCnt)
    {
        int Count;
        char Direct;
        cin >> Count >> Direct;
        if(Direct == 'R')
        {
            while(Count--)
            {
                curX++;
                arr[curX]++;
            }
        }
        else
        {
            while(Count--)
            {
                curX--;
                arr[curX]++;
            }
            
        }
    }

    int ans = 0;

    for(int iCnt = 0 ;iCnt<2001;++iCnt)
    {
        if(arr[iCnt] > 1) ++ans;
    }

    cout << ans;
    return 0;
}