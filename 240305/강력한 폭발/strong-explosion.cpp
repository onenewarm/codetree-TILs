#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int dy[4][4] = {{}, {1,2,-1,-2}, {-1, 1, 0, 0}, {-1, -1, 1, 1} };
int dx[4][4] = {{}, {0,0,0,0}, {0, 0, -1, 1}, {-1, 1, -1, 1} };

int n;

vector<pair<int,int>> bombs;
int matrix[20][20];
int visit[20][20];
int endCnt = 0;
int res = 0;

void DFS(int iBombs, int BombNum, int curRes, int change[][20])
{
    if(iBombs == endCnt)
    {
        res = max(res, curRes);
        return;
    }

    int y = bombs[iBombs].first;
    int x = bombs[iBombs].second;

    if(visit[y][x] == 0)
    {
        ++curRes;
        change[y][x] = 1;
        visit[y][x] = 1;
    }
    

    for(int iCnt = 0 ; iCnt < 4 ; ++iCnt)
    {
        int ny = y + dy[BombNum][iCnt];
        int nx = x + dx[BombNum][iCnt];

        if(ny < 0 || nx < 0 || ny > n-1 || nx > n-1 || visit[ny][nx] == 1) continue;

        ++curRes; 
        change[ny][nx] = 1;
        visit[ny][nx] = 1;    
    }

    ++iBombs;

    for(int iCnt = 1 ; iCnt < 4 ; ++iCnt)
    {
        int paramChange[20][20] = {};
        DFS(iBombs, iCnt, curRes, paramChange);

        if(iBombs == endCnt) continue;

        y = bombs[iBombs].first;
        x = bombs[iBombs].second;

        if(paramChange[y][x]) visit[y][x] = 0;

        for(int jCnt = 0 ; jCnt < 4 ; ++jCnt)
        {
            int ny = y + dy[iCnt][jCnt];
            int nx = x + dx[iCnt][jCnt];

            if(ny < 0 || nx < 0 || ny > n-1 || nx > n-1 || paramChange[ny][nx] == 0) continue;
        
            visit[ny][nx] = 0;
        }
    }
}

void Solve()
{
    for(int iCnt = 1 ; iCnt < 4 ; ++iCnt)
    {
        int paramChange[20][20] = {};
        DFS(0, iCnt, 0, paramChange);
        int y = bombs[0].first;
        int x = bombs[0].second;

        visit[y][x] = 0;
        for(int jCnt = 0 ; jCnt < 4 ; ++jCnt)
        {
            int ny = y + dy[iCnt][jCnt];
            int nx = x + dx[iCnt][jCnt];

            if(ny < 0 || nx < 0 || ny > n-1 || nx > n-1 ) continue;
        
            visit[ny][nx] = 0;
        }
        

    }

    cout << res;
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n;

    for(int iRow = 0 ; iRow < n ; ++iRow)
    {
        for(int iCol = 0 ; iCol < n ; ++iCol)
        {
            cin >> matrix[iRow][iCol];
            if(matrix[iRow][iCol])
            {
                ++endCnt;
                bombs.push_back({iRow, iCol});
            }
        }
    }


    Solve();

    return 0;
}

/*

정사각형 격자가 주어진다.
1은 폭탄임

폭탄은 세가지 종류이고, 선택이 가능하다.

최대로 많은 곳을 초토화 시키려고 한다.

*/