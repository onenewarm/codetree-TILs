#include <iostream>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int R,C;
    cin >> R >> C;

    char startColor;

    char Rect[5][15];

    for(int iRow = 0; iRow < R ; ++iRow)
    {
        for(int iCol = 0; iCol < C; ++iCol)
        {
            cin >> Rect[iRow][iCol];
        }
    }

    startColor = Rect[0][0];

    int ans = 0;

    for(int iARow = 1; iARow < R-2 ;++iARow)
    {
        for(int iACol = 1;iACol < C-2 ;++iACol)
        {
            if(Rect[iARow][iACol] == startColor) continue;
            for(int iBRow = iARow+1;iBRow < R-1;++iBRow)
            {
                for(int iBCol = iACol + 1; iBCol < C-1;++iBCol)
                {
                    if(Rect[iBRow][iBCol] != startColor) continue;

                    ++ans;
                }
            }
        }
    }

    cout << ans;

    return 0;
}