#include <iostream>

using namespace std;

int n,m;
int y,x;
int matrix[101][101];
int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1 , 1};
int u = 1, f = 2, r = 3;


int main() {
    // 여기에 코드를 작성해주세요.
    
    cin >> n >> m >> y >> x;

    char dir;

    matrix[y][x] = 6;

    while(m--)
    {
        cin >> dir;

        int iDir;

        if(dir == 'U') iDir = 0;
        else if(dir == 'D') iDir = 1;
        else if(dir == 'L') iDir = 2;
        else iDir = 3;

        int nextY = y + dy[iDir];
        int nextX = x + dx[iDir];

        if(nextY < 1 || nextX < 1 || nextY > n || nextX > n) continue;

        y = nextY;
        x = nextX;

        int tmp;

        switch(iDir)
        {
            case 0 :
                tmp = 7 - u;
                u = f;
                f = tmp;
                break;
            case 1 :
                tmp = 7 - f; 
                f = u; 
                u = tmp;
                break;
            case 2 :
                tmp = 7 - u;
                u = r;
                r = tmp;
                break;
            case 3 :
                tmp = 7 - r;
                r = u;
                u = tmp;
                break;
        }
        matrix[y][x] = 7-u;
    }

    int res = 0;

    for(int iRow = 1 ; iRow <= n ; ++iRow)
    {
        for(int iCol = 1; iCol <= n ; ++iCol)
        {
            res += matrix[iRow][iCol];
        }
    }
    
    cout << res;

    return 0;
}

/*


*/