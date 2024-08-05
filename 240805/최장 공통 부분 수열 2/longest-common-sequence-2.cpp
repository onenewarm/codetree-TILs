#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;

int dp[1001][1001];

string A, B, res;

int DFS(int i, int j)
{
    if(i < 1 || j < 1) return 0;
    
    if(dp[i][j] != -1) return dp[i][j];

    if(A[i-1] == B[j-1])
    {
        return dp[i][j] = DFS(i-1, j-1) + 1;
    }
    else
    {
       return dp[i][j] = max(DFS(i-1,j) ,DFS(i, j-1));
    }
}

int main() {
    
    cin >> A >> B;

    for(int Row = 0 ; Row < 1001 ; ++Row)
    {
        for(int Col = 0 ; Col < 1001 ; ++Col)
        {
            dp[Row][Col] = -1;
        }
    }

    DFS(A.size(), B.size());

    int i = A.size();
    int j = B.size();
    int prevDP = dp[i][j];

    if(A[i-1] == B[j-1]) res = A[i-1];

/*
    for(int Row = 1 ; Row <= A.size() ; ++Row)
    {
        for(int Col = 1 ; Col <= B.size() ; ++Col)
        {
            cout << dp[Row][Col] << ' ';
        }
        cout << endl;
    }
    */

    while(1)
    {
        if(dp[i][j] == 0) break;

        if(i < 1 || j < 1)
        {
            //cout << "!";
            if(i < 1)
            {
                //cout << "@";
                for(int curj = j ; curj > 0 ; --curj)
                {
                    //cout << "#";
                    //cout << prevDP;
                    if(dp[i+1][curj] == prevDP - 1)
                    {
                        //cout << "%";
                        prevDP = dp[i+1][curj];
                        //printf("Add : %d, %d, %c\n", i, curj, B[curj-1]);
                        res += B[curj-1];
                    }
                }
            }
            else
            {
                for(int curi = i ; curi > 0 ; --curi)
                {
                   if(dp[curi][j+1] == prevDP - 1)
                    {
                        prevDP = dp[curi][j+1];
                        //printf("Add : %d, %d, %c\n", curi, j, A[curi-1]);
                        res += A[curi-1];
                    } 
                }
            }

            break;
        }
        else if(dp[i][j] == prevDP - 1)
        {
            if(dp[i-1][j] == prevDP - 1)
            {
                //printf("Add : %d, %d, %c\n", i, j, B[j-1]);
                res += B[j-1];
            }
            else
            {
                //printf("Add : %d, %d, %c\n", i, j, A[i-1]);
                res += A[i-1];
            }
            prevDP = dp[i][j];
            //cout <<"***"<< i << j << prevDP;
        }
        i--;
        j--;
    }

    for(int Cnt = res.size() - 1 ; Cnt >= 0 ; --Cnt)
    {
        printf("%c", res[Cnt]);
    }
    return 0;
}