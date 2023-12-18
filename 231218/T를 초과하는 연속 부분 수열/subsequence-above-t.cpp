#include <iostream>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n,t;
    cin >> n >> t;
    
    int ans = 0;
    int cnt = 0;
    for(int iCnt = 0; iCnt < n;++iCnt)
    {
        int num;
        cin >> num;
        if(num > t)
        {
            ++cnt;
        }
        else
        {
            ans = max(ans, cnt);
            cnt = 0;
        }
    }

    ans = max(ans, cnt);

    cout << ans;

    return 0;
}