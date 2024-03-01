#include <iostream>

using namespace std;

int K,N;

int res[10];

void DFS(int pos, int val)
{
    res[pos] = val;
    if(pos == N)
    {
       
        for(int iCnt = 1 ; iCnt <= N ; ++iCnt)
        {
            cout << res[iCnt] <<' ';
        }
        cout << '\n';
        return;
    }

    for(int Num = 1 ; Num <= K ; ++Num)
    {
        DFS(pos + 1, Num);
    }
}

void Solve()
{
    for(int Num = 1 ; Num <= K ; ++Num)
    {
        DFS(1, Num);
    }
}

int main() {
    // 여기에 코드를 작성해주세요.

    cin >> K >> N;

    Solve();

    return 0;
}