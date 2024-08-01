#include <iostream>
#include <string>

using namespace std;

string s,p;

bool DFS(int i, int j, bool starFlag)
{
    if(i < 0 || j < 0)
    {
        if(i - j) return false;
        else return true;
    }

    if(s[i] == p[j])
    {
        if(starFlag == true)
        {
            bool ret = DFS(i-1, j-1, false);
            if(ret == false) ret = DFS(i-1, j, true);
            return ret;
        }

        return DFS(i-1, j-1, false);
    }
    else
    {
        if(p[j] == '.')
        {
            if(starFlag == true)
            {
                bool ret = DFS(i-1, j-1, false);
                if(ret == false) ret = DFS(i-1, j, true);
                return ret;
            }

            return DFS(i-1, j-1, false);
        }
        
        if(p[j] == '*') return DFS(i, j-1, true);

        if(starFlag == false) return false;
        else return DFS(i, j-1, false);
    }
}

int main() {
    // 여기에 코드를 작성해주세요

    cin >> s >> p;
    
    bool res = DFS(s.size() - 1, p.size() - 1, false);

    if(res == true) cout << "true";
    else cout << "false";

    return 0;
}