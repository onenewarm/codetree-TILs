#include <iostream>
#define OFFSET 10'0000

using namespace std;

// 1=흰색, 2=검정색
int tiles[OFFSET*2 +1];
int curX = 0 + OFFSET;

int main() {
    // 여기에 코드를 작성해주세요.
    int n;
    cin >> n;
    for(int iCnt = 0; iCnt < n;++iCnt)
    {
        int Cnt;
        char Dir;
        cin >> Cnt >> Dir;

        if(Dir == 'L')
        {
            while(Cnt--)
            {
                tiles[curX] = 1;
                if(Cnt) --curX;
            }
        }
        else
        {
            while(Cnt--)
            {
                tiles[curX] = 2;
                if(Cnt) ++curX;
            }
        }
    }

    int white = 0;
    int black = 0;

    for(int iCnt = 0 ; iCnt < OFFSET * 2 + 1; ++iCnt)
    {
        if(tiles[iCnt] == 1) ++white;
        else if(tiles[iCnt] == 2) ++black;
    }

    cout << white << ' ' << black;

    return 0;
}