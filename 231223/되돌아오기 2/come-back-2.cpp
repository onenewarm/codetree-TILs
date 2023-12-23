#include <iostream>

using namespace std;

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

int main() {
    // 여기에 코드를 작성해주세요.
    
    int curX = 0;
    int curY = 0;

    char cmd[100000];
    cin >> cmd;

    int ans = 0;
    
    int iDir = 0;
    char* pCmd = cmd;
    while((*pCmd) != '\0')
    {
        ++ans;
        if(*pCmd == 'L')
        {
            iDir = (iDir + 1) % 4;
        }
        else if(*pCmd == 'R')
        {
            iDir = (iDir + 3) % 4;
        }
        else if(*pCmd == 'F')
        {
            curX += dx[iDir];
            curY += dy[iDir];

            if(curX == 0 && curY == 0)
            {
                cout << ans;
                return 0;
            } 
        }
        ++pCmd;
    }

    cout << -1;
    return 0;
}


/*
시작 지점 (0,0,N)

N개의 명령에 따라 총 N번 움직인다.
명령 L이 주어지면 왼쪽으로 90도 방향 전환을 한다.
명령 R이 주어지면 오른쪽으로 90도 방향 전환을 한다.
명령 F가 주어지면 바라보고 있는 방향으로 한칸 이동한다.
1초에 한칸씩 움직이며, 회전에도 1초의 시간이 걸린다 했을 때,
몇초 뒤에 처음으로 다시 돌아오는가?

*/