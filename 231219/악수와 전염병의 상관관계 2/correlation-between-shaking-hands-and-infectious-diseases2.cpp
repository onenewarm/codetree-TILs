#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct handShake
{
    int t;
    int x;
    int y;
};

bool compare(const handShake& A, const handShake& B)
{
    return A.t < B.t;
}

int main() {
    // 여기에 코드를 작성해주세요.
    int N,K,P,T;
    cin >> N >> K >> P >> T;

    vector<handShake> handShakes(T);

    vector<int> infectedFlags(N+1, 0);
    vector<int> infectedCnt(N+1, K);
    infectedFlags[P] = 1;

    for(int iCnt = 0; iCnt< T;++iCnt)
    {
        int t,x,y;
        cin >> t >> x >> y;
        handShakes[iCnt] = {t,x,y};
    }

    sort(handShakes.begin(), handShakes.end(), compare);

    for(int iCnt = 0; iCnt <T;++iCnt)
    {
        int x = handShakes[iCnt].x;
        int y = handShakes[iCnt].y;

        if(infectedFlags[x])
        {
            if(infectedCnt[x] > 0)
            {
                infectedCnt[x]--;
                infectedFlags[y] = 1;
            }
        }

        if(infectedFlags[y])
        {
            if(infectedCnt[y] > 0)
            {
                infectedCnt[y]--;
                infectedFlags[x] = 1;
            }
        }
    }

    for(int iCnt = 1; iCnt < N+1;++iCnt)
    {
        cout << infectedFlags[iCnt];
    }

    return 0;
}

/*

n명의 개발자가 있다. t초에 걸쳐서 x개발자가 y개발자와 악수를 나눈다.
1명의 개발자가 전염병을 옮기기 시작했다.
K번의 악수 동안만 전염병을 옮기게 된다.
그 이후 부터는 전염병에 걸려있지만 새로 옮기지는 않게 된다.
개발자들의 악수에 대한 정보와 처음 전염병에 걸려 있는 개발자의 번호 P가 주어진다.
모든 악수를 진행 한 이후 최종적으로 누가 전염병에 걸리게 됏는지를 알아내는 프로그램을 작성하여라.
전염된 사람끼리 만나도 전염시킨 것으로 간주해야 한다.

*/