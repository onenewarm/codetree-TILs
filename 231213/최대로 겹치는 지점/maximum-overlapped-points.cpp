#include <iostream>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int arr[101] = {0, };
    
    int n;

    cin >> n;
    
    for(int iCnt = 0 ; iCnt <n;++iCnt)
    {
        int a, b;
        cin >> a >> b;
        for(int iArr = a;iArr <= b;++iArr)
        {
            arr[iArr]++;
        }
    }

    int ans = 0;
    for(int iCnt = 1 ; iCnt <=100;++iCnt)
    {
        ans = max(ans, arr[iCnt]);
    }

    cout << ans;
    return 0;
}