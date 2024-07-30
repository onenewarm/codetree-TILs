#include <iostream>
#include <string>

using namespace std;

string A,B;
int d[1001][1001];

int DFS(int i, int j)
{
    if(i < 0 || j < 0)
    {
        return 0;
    }

    if(d[i][j] != -1) return d[i][j];

    if(A[i] == B[j])
    {
        
        return d[i][j] = DFS(i-1, j-1) + 1;
    }
    else
    {
        return d[i][j] = max(DFS(i-1, j), DFS(i,j-1));
    }
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> A >> B;

    for(int ASize = 0 ; ASize < A.size() ; ++ASize)
    {
        for(int BSize = 0 ; BSize < B.size() ; ++BSize)
        {
            d[ASize][BSize] = -1;    
        }
    }
    
    cout << DFS(A.size() -1 , B.size() - 1);

    return 0;
}