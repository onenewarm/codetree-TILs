#include <iostream>
#include <deque>

using namespace std;

int N,M,K;

deque<pair<int,int>> snake;

int matrix[101][101]; //뱀1 사과2 빈공간0

int dy[4] = {-1 , 1 , 0 , 0};
int dx[4] = {0, 0, -1 , 1};


int Move(int iDir, int cnt)
{
    int timeCnt = 0;

    while(cnt--)
    {
        ++timeCnt;

        int y = snake.front().first;
        int x = snake.front().second;

        int nextY = y + dy[iDir];
        int nextX = x + dx[iDir];

        if(nextY < 1 || nextX < 1 || nextY > N || nextX > N) return timeCnt;

        if(matrix[nextY][nextX] != 2)
        {
            matrix[snake.back().first][snake.back().second] = 0;
            snake.pop_back();
        }
        
        if(matrix[nextY][nextX] == 1) return timeCnt;

        matrix[nextY][nextX] = 1;

        snake.push_front({nextY,nextX});
    }

    return timeCnt;     
}


int main() {
    // 여기에 코드를 작성해주세요.
    
    cin >> N >> M >> K;

    for(int iCnt = 0 ; iCnt < M ; ++iCnt)
    {
        int x,y;
        cin >> x >> y;
        matrix[y][x] = 2;
    }

    int res  = 0;

    matrix[1][1] = 1;

    snake.push_back({1,1});

    while(K--)
    {
        char dir;
        int cnt;

        cin >> dir >> cnt;

        int iDir;

        if(dir == 'U') iDir = 0;
        else if(dir == 'D') iDir = 1;
        else if(dir == 'L') iDir = 2;
        else iDir = 3;

        res += Move(iDir, cnt);
        
    }

    cout << res;

    return 0;
}

/*

정사각형 격자가 주어진다.

격자안에는 사과와 뱀이 있다.
뱀이 움직인다.

게임이 끝나는데 얼마나 걸리는지 구하여라.

여러 격자가 하나가 돼 움직이는 문제이다.
문제가 되는 점은, 각 격자마다 다른 움직임을 가지고 있다는 점이다.
앞 선 노드의 움직임을 모방해서 움직여야 한다.

마지막 노드를 기억하고 그 노드만을 삭제하는 식으로 만드는 것이 더 간단 할 것으로 보인다.
그리고 첫번째 노드 위치에서 움직이고하자 하는 방향으로 새로운 노드를 생성한다.

종료 조건 = 격자 밖, 움직이다가 몸이 겹치는 경우

몸이 겹치는 경우를 처리를 하기 위해서 먼저 뒤가 사라지고 앞이 생기는 방식으로 만들어야 겠다.
*/