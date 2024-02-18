#include <iostream>
#include <cstring>

using namespace std;

int matrix[201][201];
int tmp[201][201];

int n,m;
int col;
int topRows[201];

int dx[4] = {0, 0, -1 , 1};
int dy[4] = {-1, 1, 0, 0};

void Boom()
{
    int row = topRows[col];

    int size = matrix[row][col];

    matrix[row][col] = 0;

    for(int sizeCnt = 1 ; sizeCnt < size ; ++sizeCnt)
    {
        for(int iCnt = 0 ; iCnt < 4 ; ++iCnt)
        {
            int nextRow = row + (dy[iCnt] * sizeCnt);
            int nextCol = col + (dx[iCnt] * sizeCnt);

            if(nextRow < 1 || nextCol < 1 || nextRow > n || nextCol > n || matrix[nextRow][nextCol] == 0) continue;

            matrix[nextRow][nextCol] = 0;
        }
    }
    
}

void Gravity()
{
    memset(tmp, 0, 4 * 201 * 201);

    for(int iCol = 1 ; iCol < n + 1 ; ++iCol)
    {
        int curRow = n;
        for(int iRow = n ; iRow >= topRows[iCol] ; --iRow)
        {
            if(matrix[iRow][iCol] != 0)
            {
                tmp[curRow--][iCol] = matrix[iRow][iCol];
            }
        }
        topRows[iCol] = curRow + 1;
    }

    for(int iRow = 1 ; iRow < n + 1 ; ++iRow)
    {
        for(int iCol = 1 ; iCol < n + 1 ; ++iCol)
        {
            matrix[iRow][iCol] = tmp[iRow][iCol];
        }
    }
}

void Solve()
{
    while(m--)
    {
        cin >> col;
        Boom();
        Gravity();
    }

    for(int iRow = 1 ; iRow < n + 1 ; ++iRow)
    {
        for(int iCol = 1 ; iCol < n + 1 ; ++iCol)
        {
            cout << matrix[iRow][iCol] << ' ';
        }
        cout << '\n';
    }

}

int main() {
    // 여기에 코드를 작성해주세요.

    cin >> n >> m;

    for(int iRow = 1; iRow < n + 1 ;++iRow)
    {
        for(int iCol = 1 ; iCol < n +1 ; ++iCol)
        {
            cin >> matrix[iRow][iCol];
        }
    }

    for(int iCnt = 1 ; iCnt < n + 1; ++iCnt)
    {
        topRows[iCnt] = 1;
    }

    Solve();

    return 0;
}
/*

정사각형의 격자판이 주어진다.

[폭탄이 위치한 최상단의 Row][Col]이 선택이 되고, 안에 적혀있는 숫자만큼으로 십자 모양으로 폭탄이 터진다.
그 이후에 row가 커지는 방향으로 중력이 작용한다.

최상단 Row를 기억하는 1차원 배열
tmp 2차원 배열

while(1)
if(최상단 Row의 값이 -1인 경우? 음.. n인경우..)
Boom
Gravity

*/