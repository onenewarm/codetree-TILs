#include <iostream>

using namespace std;

struct Pos
{
    int x;
    int y;
    int dir;
};

int dy[4] = {-1,1,0,0};
int dx[4] = {0,0,-1,1};

int main() {
    // 여기에 코드를 작성해주세요.
    int n,t;
    cin >> n >> t;

    Pos cur;
    int r,c;
    char d;
    cin >> r >> c >> d;

    int iD;
    if(d == 'U') iD = 0;
    else if(d == 'D') iD = 1;
    else if(d == 'L') iD = 2;
    else if(d == 'R') iD = 3;

    cur = {c,r,iD};

    while(t--)
    {
        int nextY = cur.y + dy[cur.dir];
        int nextX = cur.x + dx[cur.dir];

        if(nextY < 1 || nextX < 1 || nextY > n || nextX > n)
        {
            if(cur.dir == 0) cur.dir = 1;
            else if(cur.dir == 1) cur.dir = 0;
            else if(cur.dir == 2) cur.dir = 3;
            else if(cur.dir == 3) cur.dir = 2;
        }
        else
        {
            cur.y += dy[cur.dir];
            cur.x += dx[cur.dir];
        }

    }
    
    cout << cur.y << ' ' << cur.x;
    return 0;
}