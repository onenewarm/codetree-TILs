#include <iostream>
#include <vector>

using namespace std;

int N,M;
vector<int> res;

void GetComb(int cnt, int prev)
{
    if(cnt == M)
    {
        for(int iCnt = 0 ; iCnt < M ; ++iCnt)
        {
            cout << res[iCnt] << ' ';
        }
        cout << endl;
        return;
    }

    for(int num = prev + 1 ; num <= N ; ++num)
    {
        if((N - num + 1 ) < M - cnt) return;
        res.push_back(num);
        GetComb(cnt + 1, num);
        res.pop_back();
    }
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> N >> M;
    
    GetComb(0, 0);

    return 0;
}