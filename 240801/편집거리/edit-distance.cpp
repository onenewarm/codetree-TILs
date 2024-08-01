#include <iostream>
#include <string>


using namespace std;

string A,B;

int DFS(int i, int j)
{
    if(i < 0 && j < 0) return 0;
    else if(i < 0 || j < 0) return 1;
    
    if(A[i] == B[j])
    {
        return DFS(i-1, j-1);
    }
    else
    {
        int minVal = min(DFS(i-1, j), DFS(i,j-1));
        minVal = min(minVal, DFS(i-1, j-1));
        return minVal + 1;
    }
}


int main() {
    // 여기에 코드를 작성해주세요
    cin >> A >> B;
    
    cout << DFS(A.size() - 1, B.size() - 1);
    
    return 0;
}