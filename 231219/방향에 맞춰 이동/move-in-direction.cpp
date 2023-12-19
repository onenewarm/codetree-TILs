#include <iostream>

using namespace std;

struct Pos
{
    int x;
    int y;
};

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int main() {
    // 여기에 코드를 작성해주세요.

    int N;
    cin >> N;

    Pos cur = {0, 0};

    for(int iCnt = 0; iCnt <N;++iCnt)
    {
        char dir;
        int cnt;
        cin >> dir >> cnt;

        int idx;
        if(dir == 'E') idx = 0;
        else if(dir == 'W') idx = 1;
        else if(dir == 'S') idx = 2;
        else if(dir == 'N') idx = 3;

        cur.x += dx[idx] * cnt;
        cur.y += dy[idx] * cnt;
    }

    cout << cur.x <<' ' <<cur.y;
    return 0;
}