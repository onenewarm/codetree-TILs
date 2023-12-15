#include <iostream>
#define OFFSET 100

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int matrix[OFFSET*2 + 1][OFFSET*2 + 1] = {{0,},};

    int n;
    cin >> n;
    
    for(int iCnt = 0; iCnt < n;++iCnt)
    {
        int x1,y1,x2,y2;
        cin >> x1 >> y1 >> x2 >> y2;
        
        x1+=OFFSET;
        y1+=OFFSET;
        x2+=OFFSET;
        y2+=OFFSET;

        if(iCnt % 2 == 0)
        {
            for(int iRow = y1;iRow < y2;++iRow)
            {
                for(int iCol= x1;iCol < x2;++iCol)
                {
                    matrix[iRow][iCol] = 1;
                }
            }
        }
        else
        {
            for(int iRow = y1;iRow < y2;++iRow)
            {
                for(int iCol= x1;iCol < x2;++iCol)
                {
                    matrix[iRow][iCol] = 2;
                }
            }
        }
    }

    int ans = 0;

    for(int iRow = 0; iRow<=OFFSET*2;++iRow)
    {
        for(int iCol = 0; iCol<=OFFSET*2;++iCol)
        {
            if(matrix[iRow][iCol] == 2) ++ans;
        }
    }

    cout << ans;

    return 0;
}