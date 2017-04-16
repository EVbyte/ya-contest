#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

const int MAX = int(1e6)*2 + 10;

string S;
long long Q;
int strs[MAX];
int endss[MAX];
int roof;


void init(){
    int str = 0;
    int end = 0;
    roof = 0;

    cin >> S >> Q;

    for(int i = 0; i < S.size(); i++)
        strs[i] = endss[i] = 0;

    for(int i = 0; i < Q; i++){
        cin >> str >> end;
        if(end < str)
            swap(end, str);
        strs[--str]++;
        endss[--end]++;
    }
}

int main()
{
    init();
    for(int i = 0; i < S.size(); i++){
        roof += strs[i];
        if(roof % 2)
            S[i] = islower(S[i]) ? toupper(S[i]) : tolower(S[i]);
        roof -= endss[i];
    }
    cout << S;
    return 0;
}
