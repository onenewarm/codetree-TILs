#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Marble
{
    int speed;
    int num;
    int dir;
};

struct compare
{
    bool operator()(Marble& a, Marble& b)
    {
        if(a.speed > b.speed) return true;
        else if(a.speed == b.speed)
        {
            if(a.num > b.num) return true;
            else return false;
        }
        else return false;
    }
};

int dy[4] = {-1 ,0, 1, 0};
int dx[4] = {0, 1, 0, -1};

vector<vector<vector<Marble>>> matrix;


int n,m,t,k;


void Solve()
{
    while(t--)
    {
        vector<vector<priority_queue<Marble, vector<Marble>, compare>>> pqMatrix
        (n+1, vector<priority_queue<Marble, vector<Marble>, compare>>(n+1));
        
        vector<vector<vector<Marble>>> tmpMatrix(n+1, vector<vector<Marble>>(n+1));

        pqMatrix.resize(n+1, vector<priority_queue<Marble, vector<Marble>, compare>>(n+1));


        for(int iRow = 1 ; iRow <= n ; ++iRow)
        {
            for(int iCol = 1 ; iCol <= n ; ++iCol)
            {
                for(int iCnt = 0 ; iCnt < matrix[iRow][iCol].size(); ++iCnt)
                {
                    Marble curMarble = matrix[iRow][iCol][iCnt];

                    int moveCnt = curMarble.speed;
                    
                    int y = iRow;
                    int x = iCol;

                    while(moveCnt)
                    {
                        int ny = y + dy[curMarble.dir];
                        int nx = x + dx[curMarble.dir];

                        if(ny < 1 || nx < 1 || ny > n || nx > n)
                        {
                            curMarble.dir = (curMarble.dir + 2) % 4;
                        }
                        else
                        {
                            y = ny; x = nx;
                            --moveCnt;
                        }
                    }

                    pqMatrix[y][x].push(curMarble);
                }
            }
        }

        for(int iRow = 1 ; iRow <= n ; ++iRow)
        {
            for(int iCol = 1 ; iCol <= n ; ++iCol)
            {
                if(pqMatrix[iRow][iCol].empty()) continue;

                int limitCnt = k;

                while(limitCnt--)
                {
                    if(pqMatrix[iRow][iCol].empty()) break;
                    
                    tmpMatrix[iRow][iCol].push_back(pqMatrix[iRow][iCol].top());
                    pqMatrix[iRow][iCol].pop();
                }
            }
        }

        matrix = tmpMatrix;
    }
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n >> m >> t >> k;

    matrix.resize(n + 1, vector<vector<Marble>>(n + 1));

    int num = 1;

    while(m--)
    {
        int r,c,v;
        char d;

        cin >> r >> c >> d >> v;

        int iDir;
        if(d == 'U') iDir = 0;
        else if(d == 'R') iDir = 1;
        else if(d == 'D') iDir = 2;
        else iDir = 3;

        matrix[r][c].push_back({v, num++, iDir});
    }

    Solve();

    int res = 0;

    for(int iRow = 1 ; iRow <= n ; ++iRow)
    {
        for(int iCol = 1 ; iCol <= n ; ++iCol)
        {
            res += matrix[iRow][iCol].size();
        }
    }

    cout << res;

    return 0;
}

/*

정사각형 2차원 격자 안에 m개의 구슬이 있다.

격자는 벽으로 둘러싸여 있습니다.

각 구슬은 일정 속도를 갖고 정해진 방향으로 움직입니다.

그림에서 나타는 숫자는 각 구슬마다 1초에 몇 칸을 움직이는지를 표신 한 것입니다.

벽에 부딪히면 반대 방향으로 방향 전환에는 시간 소요 X

같은 위치에 여러 구슬이 위치 할 수 있다.
동일한 위치에 구슬이 K개 이하라면 ㄱㅊ

K개 넘으면 우선순위가 높은 구슬 K만 살아남고 나머지는 아웃

구슬이 빠른 놈이 우선순위가 높음 속도가 같으면 숫자 큰놈


2차원 배열에 pq를 넣으면 될 듯 하다.
struct를 하나 정의해서 속도, 번호, 방향을 넣고, 속도&번호를 짬뽕해서 pq의 compare를 넣어준다.
위에서 말한 pq 2차원 배열을 매 번 초기화를 한다.

결과를 저장하는 struct 타입의 2차원 배열을 만들어준다.

*/