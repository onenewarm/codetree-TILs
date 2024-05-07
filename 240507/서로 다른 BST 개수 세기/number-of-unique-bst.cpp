#include <iostream>

using namespace std;

int n;
int memo[20];


int DFS(int nodeCnt)
{
    if(memo[nodeCnt] != -1) return memo[nodeCnt];

    if(nodeCnt == 0) return memo[0] = 1;
    else if(nodeCnt == 1) return memo[1] = 1;
    else
    {
        int ret = 0;
        for(int LeftCnt = 0 ; LeftCnt < nodeCnt ; ++LeftCnt)
        {
            ret += DFS(LeftCnt) * DFS((nodeCnt - 1) - LeftCnt);
        }
        return memo[nodeCnt] = ret;
    } 
}


int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n;

    for(int iCnt = 0 ; iCnt < 20 ; ++iCnt)
    {
        memo[iCnt] = -1;
    }

    DFS(n);

    cout << memo[n];

    return 0;
}


/*

브루트포스 방법을 생각해보자.

트리의 특징으로 볼 때,
BST의 최악의 깊이는 N이고,
BST의 가장 밸런스가 잡힌 깊이는 log2(N)이다.

깊이를 기준으로 각각의 방법을 센다.

루트를 기준으로 경우의 수를 센다.
이 경우에는 어떤가? 루트가 1일 때, visit을 만들어서 이미 추가한 것에 대해서는 visit을 1로 설정한다.
그렇지 않다면 0이고, 왼쪽이 가능하면서 visit이 아닌 경우에 대해서 또 DFS를 타고 타고 타고..


어차피 구해야 하는 것은 BST의 개수를 세는 것이다.
그렇다면 노드가 들어 갈 수 있는 자리를 기준으로 해서 경우의 수를 찾아본다면?

n=1일 때, 노드가 있을 수 있는 자리는 1이다. 그러므로 1
n=2일 때, 노드가 있을 수 있는 자리는 2이다. 여기서 n=2일 때, 1은 2의 무조건 왼쪽이다. 1일때는 무조건 오른쪽
n=3일 때, 1,2,3에 대해서 1이 루트라면 2일 때 3은 무조건 오른쪽 3이 위일때, 이때가 새로운 경우이다. 3이 루트인 경우에는 1과 2의 위치는 정해져 버린다. 하지만 이 경우도 경우의 수가 늘어난다.
= 1 + 1 + 1 + 
n=4일 때, 새로운 경우의 수는 리프노드로 삽입되지 않는 경우라고 보면 된다.
3일때의 모든 경우의 수 + 4를 리프노드로 삽입하지 않는 경우
삽입 순서가 어떻게 되는가?
4가 첫번째 - 1,2,3

2,1,3 / 2,3,1

2,1,4,3 / 2,4,1,3 이런건 중복이 되니까 하나로만 쳐야 됨.

*/