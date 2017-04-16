#include <iostream>
#include <algorithm>
#include <string>
#include <utility>

using namespace std;

const int MAX = int(1e6) + 10;

int N;
int A[MAX];
long long icnt = 0;

void merge(int arr[], int l, int m, int r){
    int it = l;
    int lit = 0;
    int rit = 0;
    int llarr = m - l + 1;
    int lrarr = r - m;
    int larr[MAX];
    int rarr[MAX];
    for(int i = 0; i < llarr; i++){
        larr[i] = arr[l + i];
    }
    for(int i = 0; i < lrarr; i++){
        rarr[i] = arr[m + i + 1];
    }

    while(lit < llarr && rit < lrarr){
        if(larr[lit] <= rarr[rit]){
            arr[it] = larr[lit];
            lit++;
        }else{
            arr[it] = rarr[rit];
            rit++;
            icnt += llarr - lit;
        }
        it++;

    }
    while(lit < llarr){
        arr[it] = larr[lit];
        it++;
        lit++;
    }
    while(rit < lrarr){
        arr[it] = rarr[rit];
        it++;
        rit++;
    }
}

void mergesort(int arr[], int l, int r){
    if(l < r){
        int m = l + (r-l)/2;
        mergesort(arr, l, m);
        mergesort(arr, m+1, r);
        merge(arr, l, m, r);
    }
}

void init(){
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> A[i];
    }
}

int main()
{
    init();
    mergesort(A, 0, N-1);
    cout << icnt;
}
