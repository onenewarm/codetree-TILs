#include <iostream>
#include <list>
#include <vector>

using namespace std;

int n,m;

vector<vector<list<int>>> matrix;

int moveNumbers[100];

int dy[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dx[8] = {0, 1, 1, 1, 0, -1, -1, -1};

void SearchPos(pair<int,int>* dest, int* offset,int searchVal)
{
    for(int iRow = 0 ; iRow < n ; ++iRow)
    {
        for(int iCol = 0 ; iCol < n ; ++iCol)
        {
            int cntOffSet = 0;
            for(auto iter = matrix[iRow][iCol].begin() ; iter != matrix[iRow][iCol].end() ; ++iter)
            {
                if(*iter == searchVal)
                {
                    (*dest) = { iRow, iCol};
                    (*offset) = cntOffSet;
                    return;
                }
                ++cntOffSet;
            }
        }
    }
}


void Solve()
{
    int iMoveNumbers = 0;

    while(iMoveNumbers < m)
    {
        pair<int,int> pos;
        int offset;
        SearchPos(&pos, &offset,moveNumbers[iMoveNumbers++]);
        
        int maxNum = 0;
        pair<int,int> maxPos;

        for(int iD = 0 ; iD < 8 ; ++iD)
        {
            int ny = pos.first + dy[iD];
            int nx = pos.second + dx[iD];

            if(ny < 0 || nx < 0 || ny > n - 1 || nx > n - 1 ) continue;

            for(auto iter = matrix[ny][nx].begin() ; iter != matrix[ny][nx].end() ; ++iter)
            {
                if(*iter > maxNum)
                {
                    maxNum = *iter;
                    maxPos = {ny, nx};
                } 
            }
   
        }

        //맨뒤에서 꺼내서 맨 앞에 붙히기

        if(maxNum != 0)
        {
            int curY = pos.first;
            int curX = pos.second;

            int nextY = maxPos.first;
            int nextX = maxPos.second;

            auto iter = matrix[curY][curX].begin();

            for(int iCnt = 0 ; iCnt < offset ; ++iCnt) ++iter;


            while(offset >= 0)
            {
                matrix[nextY][nextX].push_front(*iter);
                iter = matrix[curY][curX].erase(iter);
                --iter;
                --offset;
            }
            
        }

/*
        for(int iRow = 0 ; iRow < n ; ++iRow)
        {
            for(int iCol = 0 ; iCol < n ; ++iCol)
            {
                if(!matrix[iRow][iCol].empty())
                {
                    for(auto iter = matrix[iRow][iCol].begin() ; iter != matrix[iRow][iCol].end() ; ++iter)
                    {
                        cout << *iter << ' ';
                    }
                    cout <<'\n';
                }
                else cout << "None" << '\n';
            }
        }

        cout << '\n';

        */
    }

}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n >> m;
    
    matrix.resize(n, vector<list<int>>(n));

    for(int iRow = 0 ; iRow < n ; ++iRow)
    {
        for(int iCol = 0 ; iCol < n ; ++iCol)
        {
            int num;
            cin >> num;
            matrix[iRow][iCol].push_back(num);
        }
    }

    int iMoveNumbers = 0;
    while(iMoveNumbers < m)
    {
        cin >> moveNumbers[iMoveNumbers++];
    }

    Solve();


    for(int iRow = 0 ; iRow < n ; ++iRow)
    {
        for(int iCol = 0 ; iCol < n ; ++iCol)
        {
            if(!matrix[iRow][iCol].empty())
            {
                for(auto iter = matrix[iRow][iCol].begin() ; iter != matrix[iRow][iCol].end() ; ++iter)
                {
                    cout << *iter << ' ';
                }
                cout <<'\n';
            }
            else cout << "None" << '\n';
        }
    }

    

    return 0;
}

/*

정사각형 격자가 주어진다. 격자의 각 요소 값은 1 ~ n
m번에 걸쳐서 숫자를 움직인다.

이동 할 숫자들의 번호가 주어짐
8방향 중 가장 큰 곳으로 이동
움직인 위치에 이미 다른 숫자가 있다면, 해당 숫자들 중 가장 위에 위치한다.

움직이는 위치는 뒤에서 빼고
쌓는 것은 위에 쌓는다.
-> Deque, List 중 선택해서 하면 될 듯하다..

8방향에 아무런 숫자도 없다면 움직이지 않는다.

*/