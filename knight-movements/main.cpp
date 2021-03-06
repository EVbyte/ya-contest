#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int LMAX = int(1e2) + 10;
const int NMAX = int(1e5);

int t = 1;
int n = 0;
int m = 0;
int i = 0;
int j = 0;
long long turns = 0;
long long A[LMAX][LMAX];

void dfs (int i, int j, int scnt) {
    if(scnt < A[i][j]){
        A[i][j] = scnt;
        if(i-1 >= 0 && j-2 >= 0) dfs(i-1, j-2, scnt+1);
        if(i-1 >= 0 && j+2 <= m) dfs(i-1, j+2, scnt+1);
        if(i-2 >= 0 && j-1 >= 0) dfs(i-2, j-1, scnt+1);
        if(i-2 >= 0 && j+1 <= m) dfs(i-2, j+1, scnt+1);

        if(i+1 <= n && j-2 >= 0) dfs(i+1, j-2, scnt+1);
        if(i+1 <= n && j+2 <= m) dfs(i+1, j+2, scnt+1);
        if(i+2 <= n && j-1 >= 0) dfs(i+2, j-1, scnt+1);
        if(i+2 <= n && j+1 <= m) dfs(i+2, j+1, scnt+1);
    }
}

void init(){
    cin >> n >> m >> i >> j;
    i -= 1;
    j -= 1;
    n -= 1;
    m -= 1;
    for(int k = 0; k <= n; k++){
        for(int v = 0; v <= m; v++){
            A[k][v] = NMAX;
        }
    }
}

int main()
{
    init();
    dfs(0, 0, 0);
    if(A[i][j] == NMAX)
        cout << "NEVAR";
    else
        cout << A[i][j];
    // count << (A[i][j] == NMAX ? "NEVER" : A[i][j]);
    return 0;
}
