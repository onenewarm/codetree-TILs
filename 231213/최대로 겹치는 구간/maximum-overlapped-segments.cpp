#include <iostream>
#define OFFSET 100

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n;
    cin >> n;

    int arr[202] = {0,};

    for(int iCnt = 0; iCnt < n; ++iCnt)
    {
        int a,b;
        cin >> a >> b;
        for(int iArr = a+OFFSET; iArr < b+OFFSET;++iArr)
        {
            arr[iArr]++;
        }
    }

    int ans = 0;

    for(int iCnt = 0;iCnt < 202;++iCnt)
    {
        ans = max(ans, arr[iCnt]);
    }

    cout << ans;

    return 0;
}