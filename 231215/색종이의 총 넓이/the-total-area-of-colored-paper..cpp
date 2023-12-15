#include <iostream>
#define OFFSET 100

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int matrix[OFFSET*2 +1][OFFSET*2 +1]= {{0,}, };

    int n;
    cin >> n;
    for(int iCnt = 0 ;iCnt<n;++iCnt)
    {
        int x,y;
        cin >> x >> y;
        x+=OFFSET;
        y+=OFFSET;

        for(int iRow = y+1;iRow<=y+8;++iRow)
        {
            for(int iCol = x+1;iCol <= x+8;++iCol)
            {
                matrix[iRow][iCol] = 1;
            }
        }
    }

    int ans =0;


    for(int iRow=0;iRow<=OFFSET*2;++iRow)
    {
        for(int iCol=0;iCol<=OFFSET*2;++iCol)
        {
            if(matrix[iRow][iCol]) ++ans;
        }
    }

    cout << ans;

    return 0;
}