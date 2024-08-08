#include <iostream>
#include <vector>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.

    int n;

    cin >> n;

    vector<int> v(n);
    for(int cnt = 0 ; cnt < n ; ++cnt)
    {
        cin >> v[cnt];
    }

    int res = -2100000000;
    int curSum = 0;

    for(int cnt = 0 ; cnt < n ; ++cnt)
    {
        curSum += v[cnt];

        res = max(curSum, res);

        if(curSum < 0) curSum = 0;
    }

    cout << res;


    return 0;
}