#include <iostream>
#include <algorithm>

using namespace std;

long long X;


int main()
{
    cin >> X;
    if(X % 10)
        cout << X % 10;
    else
        cout << "NO";
    return 0;

}
