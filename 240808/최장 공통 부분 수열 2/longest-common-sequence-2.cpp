#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;

int dp[1001][1001];

string A, B, res;

int DFS(int i, int j)
{
    if (dp[i][j] != -2) return dp[i][j];

    if (i < 1 || j < 1) return dp[i][j] = 0;

    if (A[i - 1] == B[j - 1])
    {
        return dp[i][j] = DFS(i - 1, j - 1) + 1;
    }
    else
    {
        return dp[i][j] = max(DFS(i - 1, j), DFS(i, j - 1));
    }
}

int main() {

    cin >> A >> B;

    for (int Row = 0; Row < 1001; ++Row)
    {
        for (int Col = 0; Col < 1001; ++Col)
        {
            dp[Row][Col] = -2;
        }
    }

    int i = A.size();
    int j = B.size();
    int prevDP = DFS(i, j);

    

        /*for(int Row = 0 ; Row <= A.size() ; ++Row)
        {
            for(int Col = 0 ; Col <= B.size() ; ++Col)
            {
                cout << dp[Row][Col] << ' ';
            }
            cout << endl;
        }*/

        


    while (1)
    {
        //cout << prevDP << ' ';

        if (prevDP == 0) break;

        if (i == 0 && j == 0 && prevDP == 1)
        {
            if (A.size() > B.size()) res += A[0];
            else res += B[0];
            break;
        }

        if (DFS(i,j) == prevDP - 1)
        {
            if (DFS(i, j+1) == prevDP)
            {
                //printf("Add : %d, %d, %c\n", i, j, B[j]);
                res += B[j];
            }
            else if(DFS(i+1, j) == prevDP)
            {
                //printf("Add : %d, %d, %c\n", i, j, A[i]);
                res += A[i];
            }
            else
            {
                res += A[i];
            }

            prevDP--;
            //cout <<"***"<< i << j << prevDP;
        }

        if (i != 0) i--;
        if (j != 0) j--;
    }


    for (int Cnt = res.size() - 1; Cnt >= 0; --Cnt)
    {
        printf("%c", res[Cnt]);
    }
    return 0;
}