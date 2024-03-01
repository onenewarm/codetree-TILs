#include <iostream>

using namespace std;

int n;

int cnt = 0;

void DFS(int prefix, int num)
{
    if((prefix + num) > n) return;
    else if((prefix + num) == n)
    {
        ++cnt;
        return;
    }

    prefix += num;

    for(int nextNum = 1 ; nextNum <= 9 ; ++nextNum)
    {
        DFS(prefix, nextNum);
    }
}

void Solve()
{
    for(int Num = 1 ; Num <= 9 ; ++Num)
    {
        DFS(0, Num);
    }
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n;

    Solve();

    cout << cnt;

    return 0;
}


/*

1~4의 숫자로 이루어져있다.
해당 숫자만큼 연달아 나오는 수?

모든 경우의 수를 다 한다고 했을 때,
주어진 자리수의 모든 숫자 각각에 대하여 아름다운 수의 판별을 통해서 할 수 있다.

하지만,
n = 10
10자리라고 했을 때, 10000000000 
무조건 시간복잡도에서 문제가 있을 것이다.

시간복잡도를 줄이기 위해서는?

내가 직접 만든다.

1 -> n의 자리로 자리수를 늘려가면서

맨 앞이 1 ~ 9일 때까지, 그리고 다음 자리수로 넘어간다.
여태까지 추가 된 위치를 파라미터로 전달해준다.

*/