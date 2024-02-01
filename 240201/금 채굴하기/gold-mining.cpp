#include <iostream>

using namespace std;

int n,m;
int matrix[21][21];
int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};

void DFS(int visit[][21], int K, int curK, int* goldCnt, int y, int x)
{   
    if(matrix[y][x] != 0) *goldCnt += 1;

    if(K == curK) return;

    for(int iCnt = 0 ; iCnt < 4 ; ++iCnt)
    {
        int nextY = y + dy[iCnt];
        int nextX = x + dx[iCnt];

        if(nextY < 0 || nextY > n - 1 || nextX < 0 || nextX > n - 1 || visit[nextY][nextX] != 0 ) continue;
        visit[nextY][nextX] = 1;
        DFS(visit, K, curK+1, goldCnt, nextY, nextX);
    }

    return;
}


int Solve()
{
    int ret = 0;

    for(int KCnt = 0 ; KCnt <= 2 * n ; ++KCnt)
    {
        for(int iY = 0 ; iY < n ; ++iY)
        {
            for(int iX = 0 ; iX < n ; ++iX)
            {
                int visit[21][21] = {};
                int goldCnt = 0;
                visit[iY][iX] = 1;
                DFS(visit, KCnt, 0, &goldCnt, iY, iX);

                int spendedMoney = (KCnt*KCnt) + (KCnt + 1) * (KCnt + 1);
                int earnedMoney = goldCnt * m;

                if(earnedMoney - spendedMoney >= 0) ret = max(ret, goldCnt);
            }
        }
    }

    return ret;
}


int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n >> m;

    for(int iRow = 0 ; iRow < n ; ++iRow)
    {
        for(int iCol = 0 ; iCol < n ; ++iCol)
        {
            cin >> matrix[iRow][iCol];
        }
    }

    cout << Solve();

    return 0;
}

/*

고급 요구사항 :
2차원 n x n 영역에 금이 묻혀 있는데, 손해를 보지 않고 금을 최대한 많이 캐겠다.
마름모 모양으로 금을 채취 할 수 있다.
외부로 나가는 것도 허용이 된다.
마름모 -> K번 이동으로 갈 수 있는 모든 곳
비용은 마름모 안의 격자 개수 만큼 들어가고 그 값은 K^2 + (K+1)^2 으로 나타난다.
금 하나의 가격이 m이다.

입력 :
n,m이 입력된다. n (1 ~ 20), m(1 ~ 10)
n x n 만큼 격자의 정보가 주어진다.

아이디어 :


*/