#include <iostream>
#include <vector>

using namespace std;

int dy[9] = {0, -1, -1, 0, 1, 1, 1, 0, -1};
int dx[9] = {0, 0, 1, 1, 1, 0, -1, -1, -1};

int n;

int nums[5][5];
int dirs[5][5];

int startR,startC;

int res = 0;

bool OOB(int r, int c)
{
    return (r < 1 || c < 1 || r > n || c > n);
}

void ChoosePath(int curR, int curC, int moveCnt)
{
    res = max(res, moveCnt);

    int dir = dirs[curR][curC];

    int nextR = curR;
    int nextC = curC;

    while(!OOB(nextR, nextC))
    {
        nextR += dy[dir];
        nextC += dx[dir];
        if(nums[nextR][nextC] < nums[curR][curC]) continue;
        ChoosePath(nextR, nextC, moveCnt + 1);
    }
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n;

    for(int iRow = 1 ; iRow <= n ; ++iRow)
    {
        for(int iCol = 1 ; iCol <= n ; ++iCol)
        {
            cin >> nums[iRow][iCol];
        }
    }

    for(int iRow = 1 ; iRow <= n ; ++iRow)
    {
        for(int iCol = 1 ; iCol <= n ; ++iCol)
        {
            cin >> dirs[iRow][iCol];
        }
    }

    cin >> startR >> startC;

    ChoosePath(startR, startC, 0);

    cout << res;

    return 0;
}