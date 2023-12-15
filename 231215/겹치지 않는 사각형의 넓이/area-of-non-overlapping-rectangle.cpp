#include <iostream>
#define OFFSET 1000

using namespace std;

int main() {
    
    int matrix[OFFSET*2 + 1][OFFSET*2 + 1] = {{0, }, };

    for(int iCnt = 0 ; iCnt < 2; ++iCnt)
    {
        int x1,y1,x2,y2;

        cin >> x1 >> y1 >> x2 >> y2 ;
        x1 += OFFSET;
        y1 += OFFSET;
        x2 += OFFSET;
        y2 += OFFSET;

        for(int iRow = y1+1; iRow <= y2 ; ++iRow)
        {
            for(int iCol = x1+1; iCol <= x2 ; ++iCol)
            {
                matrix[iRow][iCol] = 1;
            }
        }
    }

    int x1,y1,x2,y2;
    cin >> x1 >> y1 >> x2 >> y2;
    x1 += OFFSET;
    y1 += OFFSET;
    x2 += OFFSET;
    y2 += OFFSET;
    for(int iRow = y1+1; iRow <= y2 ; ++iRow)
    {
        for(int iCol = x1+1; iCol <= x2 ; ++iCol)
        {
            matrix[iRow][iCol] = 0;
        }
    }

    int ans = 0;

    for(int iRow = 0 ; iRow <= OFFSET*2;++iRow)
    {
        for(int iCol = 0 ; iCol <= OFFSET*2;++iCol)
        {
            if(matrix[iRow][iCol]) ++ans;
        }
    }

    cout << ans;

    return 0;
}