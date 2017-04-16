#include <iostream>
#include <algorithm>

using namespace std;

const int LMAX = int(1e5) + 10;

const int divs[][10] = {
    {1087388483},
    {1021, 1031, 1033},
    {1031, 1054693},
    {1021, 1065023},
    {1033, 1052651}
};

int N;
long long A[LMAX];


int main()
{
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> A[i];
    }

    for(int i = 0; i <= 0; i++){
        if(*find(A, A + N, divs[0][i]) != divs[0][i]){
            break;
        }else if(i == 0){
            cout << "YES";
            return 0;
        }
    }

    for(int i = 0; i <= 2; i++){
        if(*find(A, A + N, divs[1][i]) != divs[1][i]){
            break;
        }else if(i == 2){
            cout << "YES";
            return 0;
        }
    }

    for(int i = 0; i <= 1; i++){
        if(*find(A, A + N, divs[2][i]) != divs[2][i]){
            break;
        }else if(i == 1){
            cout << "YES";
            return 0;
        }
    }

    for(int i = 0; i <= 1; i++){
        if(*find(A, A + N, divs[3][i]) != divs[3][i]){
            break;
        }else if(i == 1){
            cout << "YES";
            return 0;
        }
    }

    for(int i = 0; i <= 1; i++){
        if(*find(A, A + N, divs[4][i]) != divs[4][i]){
            break;
        }else if(i == 1){
            cout << "YES";
            return 0;
        }
    }

    cout << "NO";
    return 0;
}
