#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

const int LMAX = int(1e5) + 10;
const int NMAX = int(1e9)*2 + 10;

string S;
int lidx = 0;
int ridx = 0;
int npl = -1;

void init(){
    cin >> S;
    lidx = 0;
    ridx = S.size() - 1;
}

bool ispalindrom(){
    int i;
    for(i = 0; (i < S.size()/2) && (S[i] == S[S.size() - i - 1]); i++);

    if(i == S.size()/2)
        return true;
    else
        return false;
}

bool isequalcharspalindrom(){
    if(ispalindrom()){
        char ch = S[0];
        for(int i = 0; i < S.size(); i++){
            if(S[i] != ch){
                return false;
            }
        }
        return true;
    }else
        return false;
}



int main()
{
    init();
    if(isequalcharspalindrom())
        cout << -1;
    else if(ispalindrom())
        cout << S.size() - 1;
    else
        cout << S.size();

    return 0;
}
