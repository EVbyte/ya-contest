#include <iostream>
#include <algorithm>

using namespace std;

const int LMAX = int(1e5) + 10;
const int NMAX = int(1e9)*2 + 10;
const int EDGE = int(1e9)+7;

long long A[LMAX];
int N;
int K;
int product = 0;
bool used = false;

void input()
{
    cin >> N >> K;
    for(int i=0; i<N; i++)
        cin >> A[i];
}

void init()
{
    input();
}

void calc()
{
    int lidx = 0;
    int ridx = N - 1;

    while(K > 0){
        if(ridx == lidx){
            if(!used)
                product = A[ridx];
            else
                product *= A[ridx];
            K -= 1;
        }else{
            long long lprod = A[lidx]*A[lidx+1];
            long long rprod = A[ridx]*A[ridx-1];
            if(lprod >= rprod){
                if(!used){
                    product = lprod;

                }

                else
                    product *= lprod;
                lidx += 2;
                K -= 2;
            }
            else{
                if(!used)
                    product = A[ridx];
                else
                    product *= A[ridx];
                ridx -= 1;
                K -= 1;
            }
        }

        used = true;
    }
}

int main()
{
    init();
    sort(A, A+N);
    calc();
    cout << product;
    return 0;
}

int mod(long long value){
}
