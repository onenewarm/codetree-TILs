#include <iostream>

using namespace std;

int n;
int matrix[100][100];
int maxTime = 0;

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

void PartSolve(int curY, int curX, int curDir)
{
    int curTime = 1;

    while(1)
    {
        ++curTime;
        int nextY = curY + dy[curDir];
        int nextX = curX + dx[curDir];

        if(nextY < 0 || nextX < 0 || nextY > n - 1 || nextX > n - 1) break;

        if(matrix[nextY][nextX] != 0)
        {
            if(matrix[nextY][nextX] == 1)
            {
                if(curDir == 0 || curDir == 2) curDir = (curDir + 5) % 4;
                else curDir = (curDir + 3) % 4;
            }
            else
            {
                if(curDir == 0 || curDir == 2) curDir = (curDir + 3) % 4;
                else curDir = (curDir + 5) % 4;
            }
        }

        curY = nextY;
        curX = nextX;
    }

    maxTime = max(maxTime, curTime);
}

void Solve()
{

    //위
    for(int iCol = 0 ; iCol < n ; ++iCol) PartSolve(0, iCol, 2);

    //하
    for(int iCol = 0 ; iCol < n ; ++iCol) PartSolve(n-1, iCol, 0);

    //좌
    for(int iRow = 0 ; iRow < n ; ++iRow) PartSolve(iRow, 0, 1);

    //우
    for(int iRow = 0 ; iRow < n ; ++iRow) PartSolve(iRow, n-1, 3);

    cout << maxTime;

}

int main() {
    // 여기에 코드를 작성해주세요.

    cin >> n;

    for(int iRow = 0 ; iRow < n ; ++iRow)
    {
        for(int iCol = 0 ; iCol < n ; ++iCol)
        {
            cin >> matrix[iRow][iCol];
        }
    }

    Solve();

    return 0;
}
/*

정사각형 격자가 주어진다.
0,1,2 숫자들로 이루어져 있다.
0은 빈공간
1은 /
2는 역슬래시

바에 부딪혀서 진행방향이 바뀐다.
구슬이 격자밖으로 나가면 종료
구슬이 한칸 이동하는 데에는 1초가 걸린다.
격자 안으로 들어가고 나가는 시간을 포함한다.

1은 상하로 부딪히면 오른쪽 좌우로 부딪히면 왼쪽
2는 상하로 부딪히면 왼쪽 좌우로 부딪히면 오른쪽

나오는데 걸리는 시간이 최대가 되도록 하여라.

*/