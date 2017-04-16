#include <iostream>
#include <algorithm>

using namespace std;

int y;

int main()
{
    cin >> y;
    if(y % 4 == 0 && y % 100 != 0 || y % 400 == 0)
        cout << "YES";
    else
        cout << "NO";

    return 0;
}
