#include <iostream>
#include <algorithm>

using namespace std;


int size;
long long arr[int(1e5) + 10];


void init(){
    cin >> size;
    for(int i = 0; i < size; i++)
        cin >> arr[i];
}

int main()
{
    // get product max product of: two max, two min values
    init();
    sort(arr, arr + size);
    cout << max(arr[0] * arr[1], arr[size-1] * arr[size-2]);
    return 0;
}
