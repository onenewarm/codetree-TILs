#include <iostream>

using namespace std;

int n;

int blocks[101];

int main() {
    // 여기에 코드를 작성해주세요.

    cin >> n;

    int floorIdx = n-1;

    for(int iCnt = 0 ; iCnt < n ; ++iCnt)
    {
        cin >> blocks[iCnt];
    }

    int cases = 2;

    while(cases--)
    {
        int s,e;
        cin >> s >> e;

        for(int iCnt = s-1 ; iCnt < e ; ++iCnt)
        {
            if(blocks[iCnt] != 0)
            {
                blocks[iCnt] = 0;
                --n;
            }
        }

        for(int iCnt = floorIdx ; iCnt >= 0 ; --iCnt)
        {
            for(int iNear = iCnt ; iNear >= 0 ; --iNear)
            {
                if(blocks[iNear] != 0)
                {
                    blocks[iCnt] = blocks[iNear];
                    break;
                }
            }
        }
    }

    cout << n << '\n';
    for(int iCnt = floorIdx - (n - 1) ; iCnt < floorIdx + 1 ; ++iCnt )
    {
        cout << blocks[iCnt] << '\n';
    }

    return 0;
}

/*


*/