#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;

int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};

vector<vector<int>> matrix;
vector<vector<int>> visit;

int VillageCnt = 0;
vector<int> popularity;

void DFS(int curX, int curY, int* personCnt)
{
    for(int iD = 0 ; iD < 4 ; ++iD)
    {
        int nextY = curY + dy[iD];
        int nextX = curX + dx[iD];

        if(nextY < 0 || nextX < 0 || nextY > n-1 || nextX > n-1
        || matrix[nextY][nextX] == 0 || visit[nextY][nextX] == 1) continue;

        ++(*personCnt);
        visit[nextY][nextX] = 1;
        DFS(nextX, nextY, personCnt);
    }
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n;
    matrix.resize(n, vector<int>(n));
    visit.resize(n, vector<int>(n, 0));

    for(int iRow = 0; iRow < n ; ++iRow)
    {
        for(int iCol = 0 ; iCol < n ; ++iCol)
        {
            cin >> matrix[iRow][iCol];
        }
    }

    for(int iRow = 0 ; iRow < n ; ++iRow)
    {
        for(int iCol = 0 ; iCol < n ; ++iCol)
        {
            if(matrix[iRow][iCol] == 1 && visit[iRow][iCol] == 0)
            {
                int personCnt = 1;

                ++VillageCnt;
                visit[iRow][iCol] = 1;
                DFS(iCol, iRow, &personCnt);

                popularity.push_back(personCnt);
            }
        }
    }

    sort(popularity.begin(), popularity.end());

    cout << VillageCnt << '\n';

    for(int iCnt = 0 ; iCnt < popularity.size() ; ++iCnt)
    {
        cout << popularity[iCnt] <<'\n';
    }

    return 0;
}