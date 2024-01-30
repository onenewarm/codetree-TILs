#include <iostream>
#include <list>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int K,N;

    cin >> K >> N;

    list<pair<int,int>> res;
    
    int rank[5];

    int a,b,c,d;

    cin >> a >> b >> c >> d;

    rank[a] = 1;
    rank[b] = 2;
    rank[c] = 3;
    rank[d] = 4;

    for(int iA = 1 ; iA <= N ; ++iA)
    {
        for(int iB = 1 ; iB <= N ; ++iB)
        {
            if(iA == iB || rank[iB] < rank[iA] ) continue;

            res.push_back({iA, iB});
        }
    }


    for(int iCnt = 0; iCnt < K-1 ; ++iCnt)  
    {
        int a,b,c,d;

        cin >> a >> b >> c >> d;

        rank[a] = 1;
        rank[b] = 2;
        rank[c] = 3;
        rank[d] = 4;

        for(auto iter = res.begin() ; iter != res.end() ; )
        {
            int A = (*iter).first;
            int B = (*iter).second;

            if(rank[A] > rank[B]) iter = res.erase(iter);
            else ++iter;
        }
    }

    int ans = 0;

    for(auto iter = res.begin() ; iter != res.end() ; ++iter)
    {
        ++ans;
    }

    cout << ans;

    return 0;
}

/*

고급 요구사항 :
K번의 경기가 있었고, N명의 개발자의 순위가 주어진다.
항상 a번 개발자가 b번 개발자보다 더 높은 순위 였던 서로 다른(a,b) 쌍의 수를 구하여라.
a가 b보다 항상 높은 값인 경우의 수를 구하는 문제이다.

아이디어 :
각 경기에 대해서 순회를 한다.

각 경기의 결과는 랭크로 알려준다.

이전 경기들에 의해서 만들어진 (a,b) 경우를 List에 담아서 보관을 하고,
해당 List에 있는 요소들에 대해서만 이번 경기에 대해서 이변이 없는지를 확인한다.

그러기 위해서 List 초기화가 필요하다.
첫번째 경기에 대해서는 a가 b를 이기는 경우를 List에 담는다.

*/