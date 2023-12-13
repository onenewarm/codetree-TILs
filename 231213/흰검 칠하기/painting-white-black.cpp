#include <iostream>
#define CHECK_SIZE 20'0001
#define OFFSET 10'0000

using namespace std;

//1 = 흰색, 2 = 검정색, 3 = 회색
int tiles[CHECK_SIZE];

int white[CHECK_SIZE];
int black[CHECK_SIZE];

int main() {
    // 여기에 코드를 작성해주세요.
    int n;
    cin >> n;
    int curPos = 0 + OFFSET;
    for(int iCnt = 0; iCnt<n;++iCnt)
    {
        int Cnt;
        char Dir;
        cin >> Cnt >> Dir;

        if(Dir == 'L')
        {
            while(Cnt--)
            {
                tiles[curPos] = 1;
                white[curPos]++;
                --curPos;
            }
            ++curPos;
        }
        else
        {
            while(Cnt--)
            {
                tiles[curPos] = 2;
                black[curPos]++;
                ++curPos;
            }
            --curPos;
        }
    }

    int totalWhite = 0;
    int totalBlack = 0;
    int totalGray = 0;


    for(int iCnt = 0; iCnt < CHECK_SIZE;++iCnt)
    {
        if(white[iCnt] >= 2 && black[iCnt] >= 2) totalGray++;
        else{
            if(tiles[iCnt] == 1) totalWhite++;
            else if(tiles[iCnt] == 2) totalBlack++;
        }
    }

    cout << totalWhite << ' ' << totalBlack << ' ' << totalGray;

    return 0;
}