#include <iostream>
#define OFFSET 1000
#define INF 2147483647
#define MINF -2147483648

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int matrix[OFFSET*2+1][OFFSET*2+1] = {{0,}, };

    int x1[3];
    int y1[3];
    int x2[3];
    int y2[3];

    for(int iCnt = 1;iCnt<3;++iCnt)
    {
        int _x1,_y1,_x2,_y2;

        cin >> _x1 >> _y1 >> _x2 >> _y2;

        _x1 += OFFSET;
        _y1 += OFFSET;
        _x2 += OFFSET;
        _y2 += OFFSET;

        x1[iCnt] = _x1;
        y1[iCnt] = _y1;
        x2[iCnt] = _x2;
        y2[iCnt] = _y2;
    }

    for(int iCnt = 1; iCnt<3;++iCnt)
    {
        for(int iRow=y1[iCnt]; iRow<y2[iCnt];++iRow)
        {
            for(int iCol=x1[iCnt]; iCol <x2[iCnt];++iCol)
            {
                matrix[iRow][iCol] = iCnt;
            }
        }
    }

    int leftX = INF, rightX = MINF, downY = INF, upY = MINF;

    bool changeFlag = false;

    for(int iRow = 0;iRow<=OFFSET*2;++iRow)
    {
        for(int iCol = 0; iCol<=OFFSET*2;++iCol)
        {
            if(matrix[iRow][iCol] == 1)
            {
                changeFlag = true;
                leftX = min(leftX, iCol);
                rightX = max(rightX, iCol);
                downY = min(downY, iRow);
                upY = max(upY, iRow);
            }
        }
    }

    if(changeFlag == true) cout << (rightX - leftX + 1) * (upY - downY + 1);
    else cout << 0;
    return 0;
}