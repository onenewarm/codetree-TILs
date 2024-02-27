#include <iostream>
#include <cstring>

using namespace std;

int T;
int n,m;
int matrix[51][51];

int dy[5] = { -1, 0, 1, 0};
int dx[5] = { 0, 1, 0, -1};

void Solve()
{
    memset(matrix, -1, sizeof(int) * 51 * 51);

    cin >> n >> m;

    while(m--)
    {
        int r,c;
        char d;
        cin >> r >> c >> d;

        if(d == 'U') matrix[r][c] = 0;
        else if(d == 'R') matrix[r][c] = 1;
        else if(d == 'D') matrix[r][c] = 2;
        else matrix[r][c] = 3;
    }

    int loopCnt = 0; // 처음 위치로 돌아오기 까지의 시간은 n*2번 걸린다. 이 범위동안 만약에 변화가 없었다면 항상 그상태 일 것이다.

    pair<int,int> nextStates[51][51]; //cnt, dir

    while(loopCnt <= 2 * (n + 1))
    {
        memset(nextStates, 0, sizeof(pair<int,int>) * 51 * 51);

        for(int iRow = 1 ; iRow <= n ; ++iRow)
        {
            for(int iCol = 1; iCol <= n ; ++iCol)
            {
                if(matrix[iRow][iCol] != -1)
                {
                    int curDir = matrix[iRow][iCol];

                    int ny = iRow + dy[curDir];
                    int nx = iCol + dx[curDir];

                    if(ny < 1 || nx < 1 || ny > n || nx > n)
                    {
                        curDir = (curDir + 2) % 4;
                        nextStates[ny][nx].second = curDir;
                    }
                    else
                    {
                        nextStates[ny][nx].first++;
                        nextStates[ny][nx].second = curDir;
                    }
                }
            }
        }

        for(int iRow = 1 ; iRow <= n ; ++iRow)
        {
            for(int iCol = 1; iRow <= n ; ++iCol)
            {
                if(nextStates[iRow][iCol].first == 1) matrix[iRow][iCol] = nextStates[iRow][iCol].second;
                else matrix[iRow][iCol] = -1;
            }
        }

        ++loopCnt;
    }

    int res = 0;

    for(int iRow = 1 ; iRow <= n ; ++iRow)
    {
        for(int iCol = 1; iCol <= n ; ++iCol)
        {
            if(matrix[iRow][iCol] != -1) ++res;
        }
    }

    cout << res <<'\n';
}

int main() {
    // 여기에 코드를 작성해주세요.

    cin >> T;

    while(T--)
    {
        Solve();
    }

    return 0;
}


/*

정사각형 격자판

구슬은 벽에 부딪히면 움직이지 않고 움직이는 방향만 반대로 바뀐다.
방향을 바꾸는 데에는 1초에 시간이 걸린다.

두 개 이상의 구슬이 충돌하게 되면 부딪힌 구슬 모두 사라진다.


*/