#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;

int dp[1001][1001];

string A, B, res;

/*
short logIdx = 0;

struct Log
{
    int i;
    int j;
    int curCommonLen;
    int prevDP;
    char curA;
    char curB;
    char addCh;
};

Log logs[65536];

*/


int DFS(int i, int j)
{
    if (dp[i][j] != -1) return dp[i][j];

    if (i < 1 || j < 1) return dp[i][j] = 0;

    if (A[i - 1] == B[j - 1])
    {
        res.push_back(A[i-1]);
        return dp[i][j] = DFS(i - 1, j - 1) + 1;
    }
    else
    {
        int aCommonLen = DFS(i, j-1);
        int bCommonLen = DFS(i-1, j);

        if(A > B)
        {
            return dp[i][j] = aCommonLen;
        }
        else
        {
            return dp[i][j] = bCommonLen;
        }
    }
}

int main() {

    cin >> A >> B;

    for (int Row = 0; Row < 1001; ++Row)
    {
        for (int Col = 0; Col < 1001; ++Col)
        {
            dp[Row][Col] = -1;
        }
    }

    int i = A.size();
    int j = B.size();
    DFS(i, j);

    

        /*for(int Row = 0 ; Row <= A.size() ; ++Row)
        {
            for(int Col = 0 ; Col <= B.size() ; ++Col)
            {
                cout << dp[Row][Col] << ' ';
            }
            cout << endl;
        }*/

        

/*

    while (1)
    {
        //cout << prevDP << ' ';

        if (prevDP == 0) break;

        if (i == 0 && j == 0 && prevDP == 1)
        {
            if (A.size() > B.size())
            {
                //Log log = { i, j, DFS(1,1),prevDP, A[0], B[0], A[0]};
                //logs[logIdx++] = log;
                res += A[0];
            }
            else
            {
                //Log log = { i, j, DFS(1,1), prevDP,A[0], B[0], B[0] };
                //logs[logIdx++] = log;
                res += B[0];
            }

            break;
        }


        if (DFS(i,j) == prevDP - 1)
        {
            if (DFS(i, j+1) == prevDP)
            {
                //printf("Add : %d, %d, %c\n", i, j, B[j]);
                //Log log = { i, j, DFS(i,j+1), prevDP,A[i], B[j], B[j] };
                //logs[logIdx++] = log;
                res += B[j];
            }
            else
            {
                //printf("Add : %d, %d, %c\n", i, j, A[i]);
                //Log log = { i, j, DFS(i+1,j), prevDP,A[i], B[j], A[i] };
                //logs[logIdx++] = log;
                res += A[i];
            }
            prevDP--;
            //cout <<"***"<< i << j << prevDP;
        }

        if (i != 0) i--;
        if (j != 0) j--;
    }

    */


    for (int Cnt = res.size() - 1; Cnt >= 0; --Cnt)
    {
        printf("%c", res[Cnt]);
    }
    return 0;
}