#include <iostream>
#include <algorithm>
#include <string>
#include <utility>

using namespace std;

const int NMAX = int(1e9) + 10;
const int LMAX = int(1e5) + 10;

int N;
int A[LMAX];
long long ncnt = 0;

void init(){
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> A[i];
    }
    A[N] = 0;
}

void calc(){
    for(int i = 0; i < N; i++){
        if(A[N] < A[i])
            A[N] = A[i];
        if(A[i] < A[i+1])
            ncnt += A[i+1]-A[i];
    }
}

int main()
{
    init();
    calc();
    cout << ncnt;
}
