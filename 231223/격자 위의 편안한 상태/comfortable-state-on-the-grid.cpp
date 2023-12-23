#include <iostream>
#include <vector>

using namespace std;

int dy[4] = {1, -1, 0, 0};
int dx[4] = {0, 0, -1, 1};

int main() {
    // 여기에 코드를 작성해주세요.

    int N,M;
    cin >> N >> M;

    vector<vector<int>> matrix(N+1, vector<int>(N+1, -1));

    while(M--)
    {
        int r,c;
        cin >> r >> c;

        matrix[r][c] = 1;
        
        int checkCnt = 0;
        for(int iCnt = 0; iCnt < 4; ++iCnt)
        {
            int nextY = r + dy[iCnt];
            int nextX = c + dx[iCnt];

            if(nextY < 1 || nextX < 1 || nextY > N || nextX > N || 
                    matrix[nextY][nextX] == -1) continue;

            ++checkCnt;
        }

        if(checkCnt == 3) cout << 1 << '\n';
        else cout << 0 << '\n';
    }

    return 0;
}

/*

N*N의 matrix위에 총 M번에 걸쳐 색칠을 한다.
한 번에 한 칸만 색칠을 한다.
색칠을 한 직후 해당 칸이 편안한 상태인지를 확인한다.
편안한 상태 : 방금 막 칠해진 칸의 위 아래 양 옆으로 인접한 4개의 칸 중 격자를 벗어나지 않느
칸에 색칠되어 있는 칸이 정확히 3개인 경우이다.
-> 색깔을 칠하면 상하좌우를 확인하여 색칠이 몇개가 됐는지를 카운트한다.



*/