#include <iostream>
#include <vector>

using namespace std;

int dy[4] = {-1, 0, 1 ,0};
int dx[4] = {0, 1, 0, -1}; 

int main() {
    // 여기에 코드를 작성해주세요.
    int N;
    cin >> N;

    vector<vector<char>> matrix(N, vector<char>(N));

    for(int iRow = 0; iRow < N;++iRow)
    {
        char str[1001];
        cin >> str;

        char* pStr = str;
        int iCol = 0;
        while(*pStr != '\0')
        {
            matrix[iRow][iCol] = *pStr;
            ++pStr;
            ++iCol;
        }
    }

    int K;

    cin >> K;

    K--;

    int curY = 0;
    int curX = 0;
    int curDir = 1;

    while(K--)
    {
        int nextY = curY + dy[curDir];
        int nextX = curX + dx[curDir];

        if(nextY < 0 || nextX < 0 || nextY > N - 1 || nextX > N - 1)
        {
            curDir = (curDir + 1) % 4;
        }
        else
        {
            curX += dx[curDir];
            curY += dy[curDir];
        }

    }

    curDir = (curDir + 1) % 4;

    int ans = 0;

    {
        if(matrix[curY][curX] == '\\')
        {
            ++ans;
            if(curDir == 0) curDir = 3;
            else if(curDir == 1) curDir = 2;
            else if(curDir == 2) curDir = 1;
            else if(curDir == 3) curDir = 0;
        }
        else if(matrix[curY][curX] == '/')
        {
            ++ans;
            if(curDir == 0) curDir = 1;
            else if(curDir == 1) curDir = 0;
            else if(curDir == 2) curDir = 3;
            else if(curDir == 3) curDir = 2;
        }
    }

    while(1)
    {
        int nextY = curY + dy[curDir];
        int nextX = curX + dx[curDir];

        if(nextY < 0 || nextX < 0 || nextY > N - 1 || nextX > N - 1)
        {
            cout << ans;
            return 0;
        }

        if(matrix[nextY][nextX] == '\\')
        {
            ++ans;
            if(curDir == 0) curDir = 3;
            else if(curDir == 1) curDir = 2;
            else if(curDir == 2) curDir = 1;
            else if(curDir == 3) curDir = 0;
        }
        else if(matrix[nextY][nextX] == '/')
        {
            ++ans;
            if(curDir == 0) curDir = 1;
            else if(curDir == 1) curDir = 0;
            else if(curDir == 2) curDir = 3;
            else if(curDir == 3) curDir = 2;
        }

        curY = nextY;
        curX = nextX;
    }
    

    return 0;
}

/*

N*N 격자가 있다. 각 칸마다 거울이 하나씩 들어있다.
각 거울은 /이거나 \이거이다.
격자 밖 4N개의 위치 중 특정 위치에서 레이저를 쐇을 때, 거울에 튕기는 횟수를 구하는
프로그램을 작성하여라.
거울의 튕기는 횟수를 구하는 것이다.

상태를 유지해야하는 데이터는
matrix와 현재 위치

\
아래 -> 오른쪽
오른쪽 -> 아래
위 -> 왼쪽
왼쪽 -> 위

/
아래 -> 왼쪽
오른쪽-> 위
위 ->오른쪽
왼쪽-> 아래

*/