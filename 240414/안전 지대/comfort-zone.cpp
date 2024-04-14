#include <iostream>
#include <vector>
#include <list>

using namespace std;

int n,m;

vector<vector<int>> matrix;

vector<vector<int>> floodedMatrix;

list<pair<int,int>> notFloodedHouse;

int maxSafeBoundary = 0;
int safeBoundaryMinK = 1;

int dx[4] = {0,0,-1,1};
int dy[4] = {-1,1,0,0};

void DFS(int curX, int curY, vector<vector<int>>* visit)
{
    for(int iD = 0; iD < 4 ; ++iD)
    {
        int nextX = curX + dx[iD];
        int nextY = curY + dy[iD];

        if(nextX < 0 || nextY < 0 || nextX > m -1 || nextY > n -1
        || (*visit)[nextY][nextX] == 1 || floodedMatrix[nextY][nextX] == 1) continue;

        (*visit)[nextY][nextX] = 1;
        DFS(nextX, nextY, visit);
    }
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n >> m;

    matrix.resize(n, vector<int>(m));

    floodedMatrix.resize(n, vector<int>(m, 0));

    int maxK = 0;

    for(int iRow = 0 ; iRow < n ; ++iRow)
    {
        for(int iCol = 0 ; iCol < m ; ++iCol)
        {
            cin >> matrix[iRow][iCol];
            maxK = max(maxK, matrix[iRow][iCol]);
            notFloodedHouse.push_back({iRow, iCol});
        }
    }

    for(int K = 1 ; K <= maxK ; ++K)
    {
        for(auto iter = notFloodedHouse.begin() ; iter != notFloodedHouse.end() ; )
        {
            int row = (*iter).first;
            int col = (*iter).second;

            if(matrix[row][col] > K) ++iter;
            else
            {
                floodedMatrix[row][col] = 1;
                iter = notFloodedHouse.erase(iter);
            }
        }

        int safeBoundary = 0;

        vector<vector<int>> visit(n, vector<int>(m,0));

        for(int iRow = 0 ; iRow < n ; ++iRow)
        {
            for(int iCol = 0 ; iCol < m ; ++iCol)
            {
                if(visit[iRow][iCol] == 1 || floodedMatrix[iRow][iCol] == 1) continue;

                visit[iRow][iCol];
                DFS(iCol, iRow, &visit);
                ++safeBoundary;
            }
        }

        if(maxSafeBoundary < safeBoundary)
        {
            maxSafeBoundary = safeBoundary;
            safeBoundaryMinK = K;
        }
    }

    cout << safeBoundaryMinK << ' ' << maxSafeBoundary;

    return 0;
}

/*

1~100 K를 늘려가면서 1,0으로 잠긴 곳, 잠기지 않은 곳 으로 나눔
DFS를 돌면서 1인 영역의 개수를 센다.

K라는 값을 늘렸는데 영역이 적어졌다 -> 더이상 하지 말아야 할 때이다.


*/