#include <iostream>

using namespace std;

int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };

struct Pos
{
    int x;
    int y;
};

int main() {
    // 여기에 코드를 작성해주세요.

    Pos cur = { 0, 0 };
    int curDir = 0;

    char cmd[100001];

    cin >> cmd;

    char* pCmd = &cmd[0];
    while (*pCmd != '\0')
    {
        if (*pCmd == 'L')
        {
            curDir = (curDir + 3) % 4;
        }
        else if (*pCmd == 'R')
        {
            curDir = (curDir + 1) % 4;
        }
        else if (*pCmd == 'F')
        {
            cur.x += dx[curDir];
            cur.y += dy[curDir];
        }
        ++pCmd;
    }

    cout << cur.x << ' ' << cur.y;

    return 0;
}