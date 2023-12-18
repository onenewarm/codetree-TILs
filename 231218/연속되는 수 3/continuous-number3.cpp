#include <iostream>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n;
    cin >> n;

    int ans = 0;
    int cnt = 0;
    int prevX = 0;

    for(int iCnt = 0; iCnt < n ;++iCnt)
    {
        int x;
        cin >> x;
        if((prevX & 0x8000) & (x & 0x8000)) ++cnt;
        else
        {
            ans = max(ans, cnt);
            cnt = 1;
        }

        prevX = x;
    }

    ans = max(ans, cnt);
    cout << ans;

    return 0;
}