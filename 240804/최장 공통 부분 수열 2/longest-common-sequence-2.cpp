#include <iostream>
#include <string>

using namespace std;

string dp[1001][1001];

string A, B;

string DFS(int i, int j)
{
    if(i < 1 || j < 1) return dp[0][0];
    
    if(dp[i][j].size() != 0)
    {
        return dp[i][j];
    }

    if(A[i-1] == B[j-1])
    {
        return dp[i][j] = DFS(i-1,j-1) + A[i-1];
    }
    else
    {
        string tmp1 = dp[i-1][j] = DFS(i-1,j);
        string tmp2 = dp[i][j-1] = DFS(i, j-1);

        if(tmp1.size() > tmp2.size()) return dp[i][j] = tmp1;
        else return dp[i][j] = tmp2;
    }
}

int main() {
    
    cin >> A >> B;

    cout << DFS(A.size(), B.size());

    return 0;
}