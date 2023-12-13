#include <iostream>
#define OFFSET 1000
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int arr[2001] = {0, };
    int curX = 0 + OFFSET;
    int n;
    cin >> n;
    for(int iCnt = 0; iCnt < n ;++iCnt)
    {
        int Count;
        char Direct;
        cin >> Count >> Direct;
        if(Direct == 'R')
        {
            for(int iArr = curX;iArr<curX+Count;++iArr)
            {
                arr[iArr]++;
            }
           
            curX += Count;

        }
        else
        {
            for(int iArr = curX - Count ;iArr < curX;++iArr)
            {
                arr[iArr]++;
            }
                       
            curX -= Count;
            
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