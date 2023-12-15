#include <iostream>
#define OFFSET 100

using namespace std;

int main() {
    
    int matrix[OFFSET*2 + 1][OFFSET*2 + 1] = {{0, }, };

    int n;
    cin >> n;
    for(int iCnt = 0; iCnt < n;++iCnt)
    {
        int x1,y1,x2,y2;
        cin >> x1 >> y1 >> x2 >> y2;

        x1 += OFFSET;
        y1 += OFFSET;
        x2 += OFFSET;
        y2 += OFFSET;

        for(int iRow = y1+1; iRow <= y2;++iRow)
        {
            for(int iCol = x1+1;iCol <=x2;++iCol)
            {
                matrix[iRow][iCol] = 1;
            }
        }
    }

    int ans = 0;

    for(int iRow = 0 ; iRow <= 200 ; ++iRow)
    {
        for(int iCol = 0; iCol <= 200 ; ++iCol)
        {
            if(matrix[iRow][iCol]) ++ans;
        }
    }

    cout << ans;
    return 0;
}