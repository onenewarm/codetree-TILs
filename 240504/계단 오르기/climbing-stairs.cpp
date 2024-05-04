#include <iostream>
#include <cstring>

using namespace std;

int n;
//위치에 따른 가능한 경우의 수를 memo한다.
int memo[1001];

int DFS(int cur)
{
    if(memo[cur] != -1)
    {
        return memo[cur];
    }

    if(cur > n) return 0;
    else if(cur == n) return memo[cur] = 1;
    else if(cur == n - 1) return memo[cur] = 0;

    memo[cur] = 0;

    return memo[cur] += ((DFS(cur + 2) + DFS(cur + 3))) % 10,007;
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n;

    ::memset(memo, -1, 1001);
    
    DFS(0);

    cout << memo[0];

    return 0;
}

//2와 3의 더하기 조합으로 n만들기