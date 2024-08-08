#include <iostream>
#include <vector>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n;
    int k;

    cin >> n >> k;

    vector<int> coins(n);

    int res = 0;

    for(int cnt = 0 ; cnt < n ; ++cnt)
    {
        cin >> coins[cnt];
    }

    for(int cnt = n-1 ; cnt >= 0 ; --cnt)
    {
        int curCoin = coins[cnt];
        while(1)
        {
            if(k - curCoin < 0) break;
            res++;
            k -= curCoin;
        }
    }

    cout << res;

    return 0;
}