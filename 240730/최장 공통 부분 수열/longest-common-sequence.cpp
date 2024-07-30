#include <iostream>
#include <string>

using namespace std;

string A,B;

int DFS(int i, int j)
{
    if(i < 0 || j < 0)
    {
        return 0;
    }

    if(A[i] == B[j])
    {
        
        int res = DFS(i-1, j-1) + 1;
        
        return res;
    }
    else
    {
        int res = max(DFS(i-1, j), DFS(i,j-1));
        
        return res;
    }
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> A >> B;
    
    cout << DFS(A.size() -1 , B.size() - 1);

    return 0;
}