#include <iostream>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int N,T;

    cin >> N >> T;

    cin.ignore();

    char cmd[100001];
    cin >> cmd;

    int matrix[99][99];

    for(int iRow = 0;iRow < N ; ++iRow)
    {
        for(int iCol = 0; iCol < N ; ++iCol)
        {
            cin >> matrix[iRow][iCol];
        }
    }

    int curX = N/2;
    int curY = N/2;

    int dy[4] = {-1 ,0, 1, 0};
    int dx[4] = {0, 1, 0, -1};
    int iDir = 0;

    char* pCmd = cmd;

    int ans = matrix[curY][curX];

    while(*pCmd != '\0')
    {
        if(*pCmd == 'L') iDir = (iDir + 3) % 4;
        else if(*pCmd == 'R') iDir = (iDir + 1) % 4;
        else if(*pCmd == 'F')
        {
            int nextY = curY + dy[iDir];
            int nextX = curX + dx[iDir];

            bool flag = true;

            if(nextY < 0 || nextX < 0 || nextY > N-1 || nextX > N-1) flag = false;

            if(flag == true)
            {
                ans += matrix[nextY][nextX];
                curY = nextY;
                curX = nextX;
            }
            
        }

        ++pCmd;
    }

    cout << ans;

    return 0;
}