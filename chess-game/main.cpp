#include <iostream>
#include <algorithm>

using namespace std;

const int NMAX = int(1e9)*2 + 10;

int N = 0;
int M = 0;
int X1 = 0;
int X2 = 0;
int Y1 = 0;
int Y2 = 0;

int main()
{
    cin >> N >> M >> X1 >> Y1 >> X2 >> Y2;
    cout << (abs(X1-X2) == abs(Y1-Y2) ? "NO" : "YES");
    return 0;
}
