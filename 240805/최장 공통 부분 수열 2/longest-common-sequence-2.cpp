#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;

int dp[1001][1001];

string A, B, res;

int DFS(int i, int j)
{
    if(i < 1 || j < 1) return 0;
    
    if(dp[i][j] != 0) return dp[i][j];

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

    DFS(A.size(), B.size());

    int i = A.size();
    int j = B.size();
    int prevDP = dp[i][j];

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
        if(i < 1 || j < 1)
        {
            if(i < 1)
            {
                for(int curj = j ; curj > 0 ; --curj)
                {
                    if(dp[i+1][curj] == prevDP - 1)
                    {
                        prevDP = dp[i+1][curj];
                        //printf("Add : %d, %d, %c\n", i, curj, B[curj]);
                        res = B[curj] + res;
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
                        //printf("Add : %d, %d, %c\n", curi, j, A[curi]);
                        res = A[curi] + res;
                    } 
                }
            }

            break;
        }
        else if(dp[i][j] == prevDP - 1)
        {
            if(dp[i-1][j] == prevDP - 1)
            {
                //printf("Add : %d, %d, %c\n", i, j, B[j]);
                res = B[j] + res;
            }
            else
            {
                //printf("Add : %d, %d, %c\n", i, j, A[i]);
                res = A[i] + res;
            }
            prevDP = dp[i][j];
        }
        i--;
        j--;
    }

    cout << res;
    return 0;
}