#include <iostream>

using namespace std;

int n,m,k;
int matrix[101][101];
int highest[101];

const int maxSize = 2147483647;

void Solve()
{
    int collisionRow = maxSize;
    for(int iCol = k ; iCol < k + m ; ++iCol)
    {
        if(highest[iCol] != 0) collisionRow = min(collisionRow, highest[iCol]);
    }

    int resCol;

    if(collisionRow == maxSize) resCol = 1;
    else resCol = collisionRow - 1;

    for(int iCol = k ; iCol < k + m ;++iCol)
    {
        matrix[resCol][iCol] = 1;
    }

    for(int iRow = 1 ; iRow <=n ; ++iRow)
    {
        for(int iCol = 1 ; iCol <=n ;++iCol)
        {
            cout << matrix[iRow][iCol] << ' ';
        }
        cout << '\n';
    }
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n >> m >> k;

    for(int iRow = 1 ; iRow <= n ; ++iRow)
    {
        for(int iCol = 1 ; iCol <= n ; ++iCol)
        {
            cin >> matrix[iRow][iCol];
        }
    }

    for(int iCol = 1 ; iCol <= n ; ++iCol)
    {
        for(int iRow = 1 ; iRow <= n ; ++iRow)
        {
            if(matrix[iRow][iCol])
            {
                highest[iCol] = iRow;
                break;
            }
        }
    }

    Solve();


    return 0;
}