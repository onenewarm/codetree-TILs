#include <iostream>

using namespace std;

int rooms[1004];
int people = 0;
int N;
int GetDistance(int start)
{
    int ans = 0;
    int _people = people;

    _people -= rooms[start];

    while(_people != 0)
    {
        ++start;
        start %= N;
        ans += _people;
        _people -= rooms[start];
    }

    return ans;
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> N;

    int ans = 2147483647;

    for(int iCnt = 0; iCnt < N;++iCnt)
    {
        cin >> rooms[iCnt];
        people += rooms[iCnt];
    }

    for(int iCnt = 0; iCnt<N;++iCnt)
    {
        ans = min(ans, GetDistance(iCnt));
    }

    cout << ans;

    return 0;
}