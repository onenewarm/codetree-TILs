#include <iostream>

using namespace std;

int n;

int matrix[201][201];

void Boom(int r, int c, int damageSize)
{
    int startRow = r - damageSize;
    int endRow = r + damageSize - 1;

    if(startRow < 0) startRow = 0;
    if(endRow > n) endRow = n;

    for(int iRow = startRow ; iRow < endRow ; ++iRow)
    {
        matrix[iRow][c-1] = 0;
    }

    int startCol = c - damageSize;
    int endCol = c + damageSize - 1;

    if(startCol < 0) startCol = 0;
    if(endCol > n) endCol = n;

    for(int iCol = startCol ; iCol < endCol ; ++iCol)
    {
        matrix[r-1][iCol] = 0;
    }
}

void Gravity()
{
    int tmp[201][201] = {};

    for(int iCol = 0 ; iCol < n ; ++iCol)
    {
        int curPos = n-1;
        for(int iRow = n -1 ; iRow >= 0 ; --iRow)
        {
            if(matrix[iRow][iCol])
            {
                tmp[curPos][iCol] = matrix[iRow][iCol];
                --curPos;
            }
        }
    }

    for(int iRow = 0 ; iRow < n ; ++iRow)
    {
        for(int iCol = 0 ; iCol < n ;++iCol)
        {
            matrix[iRow][iCol] = tmp[iRow][iCol];
        }
    }
}

void Solve(int r, int c, int damageSize)
{
    Boom(r, c, damageSize);
    Gravity();

    for(int iRow = 0 ; iRow < n ; ++iRow)
    {
        for(int iCol = 0 ; iCol < n ;++iCol)
        {
            cout << matrix[iRow][iCol] <<' ';
        }
        cout << '\n';
    }
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

    int r, c;
    cin >> r >> c;

    int damageSize = matrix[r-1][c-1];

    Solve(r,c,damageSize);


    return 0;
}