#include <iostream>
#include <string>

using namespace std;

string s,p;

bool dp[21][21];

bool DFS(int i, int j, bool starFlag)
{
    if(i < 0 || j < 0)
    {
        if(i - j) return false;
        else return true;
    }

    if(dp[i][j] != -1) return dp[i][j];

    if(s[i] == p[j])
    {
        if(starFlag == true)
        {
            bool ret = DFS(i-1, j-1, false);
            if(ret == false) ret = DFS(i-1, j, true);
            return dp[i][j] = ret;
        }

        return dp[i][j] = DFS(i-1, j-1, false);
    }
    else
    {
        if(p[j] == '.')
        {
            if(starFlag == true)
            {
                bool ret = DFS(i-1, j-1, false);
                if(ret == false) ret = DFS(i-1, j, true);
                return dp[i][j] = ret;
            }

            return dp[i][j] = DFS(i-1, j-1, false);
        }
        
        if(p[j] == '*') return dp[i][j] = DFS(i, j-1, true);

        if(starFlag == false) return dp[i][j] = false;
        else return dp[i][j] = DFS(i, j-1, false);
    }
}

int main() {
    // 여기에 코드를 작성해주세요

    cin >> s >> p;

    for(int i = 0 ; i < s.size() ; ++i)
    {
        for(int j = 0 ; j < p.size() ; ++j)
        {
            dp[i][j] = -1;
        }
    }
    
    bool res = DFS(s.size() - 1, p.size() - 1, false);

    if(res == true) cout << "true";
    else cout << "false";

    return 0;
}