#include <iostream>
#include <algorithm>
#include <string>
#include <utility>

using namespace std;

const int NMAX = int(1e9) + 10;
const int LMAX = int(1e5) + 10;

int N;
int A[LMAX];

void init(){
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> A[i];
    }
    A[N] =
}

void calc(){
    int last = A[0];

    for(int i = 0; i < N; i++){
        if()
        last = min(last, i > 0 ? A[i-1] : last);
        cout << last << '\n';
    }
}

int main()
{
    init();
    calc();
}
