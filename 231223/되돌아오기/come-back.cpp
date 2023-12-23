#include <iostream>

using namespace std;

int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};

int main() {
    // 여기에 코드를 작성해주세요.

    int curX = 0;
    int curY = 0;

    int n;
    cin >> n;

    int ans = 0;

    while(n--)
    {
        char dir;
        int cnt;
        int iDir;
        cin >> dir >> cnt;

        if(dir == 'N')
        {
            iDir = 0;
        }
        else if(dir == 'S')
        {
            iDir = 1;
        }
        else if(dir == 'W')
        {
            iDir = 2;
        } 
        else if(dir == 'E')
        {
            iDir = 3;
        }
        
        for(int iCnt = 0 ; iCnt < cnt ; ++iCnt)
        {
            ++ans;
            curY = curY + dy[iDir];
            curX = curX + dx[iDir];

            if(curY == 0 && curX == 0)
            {
                cout << ans;
                return 0;
            }
        }
    }

    return 0;
}