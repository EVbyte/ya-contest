#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <set>
#include <utility>

using namespace std;

const int LEN_MAX = int(1e5) + 10;
const long long NUM_MAX = ((long long)1e19)*9;

long long nodescount;
long long connectionscount;
set< pair<int, int> > connections[LEN_MAX];
int startnode;
int endnode;
long long waycost;
long long costtonodes[LEN_MAX];

queue<int> queue1;

void init()
{
    waycost = 0;
    cin >> nodescount >> connectionscount;
    for(int i = 0; i < connectionscount; i++){
        int fromnodeid, tonodeid, cost;
        cin >> fromnodeid >> tonodeid >> cost;
        pair<int, int> connection = {connection.first=cost, connection.second=tonodeid};
        connections[fromnodeid].insert(connection);
        pair<int, int> second_connection = {connection.first=cost, connection.second=fromnodeid};
        connections[tonodeid].insert(second_connection);
    }
    cin >> startnode >> endnode;
    for(int i = 0; i < LEN_MAX; i++){
        costtonodes[i] = NUM_MAX;
    }
}

void mover(int nodestart){
    int nodeid;
    int i = 0;
    set< pair<int, int> >::iterator it;

    queue1.push(nodestart);

    while(!queue1.empty()){
        nodeid = queue1.front();

        queue1.pop();
        i=0;
        // cout << nodeid << "-->";
        for(it = connections[nodeid].begin(); it != connections[nodeid].end(); ++it)
        {
            long long toneighborfromhere = costtonodes[nodeid] + (*it).first;
            long long neighborcost = costtonodes[(*it).second];
            int neighborid = (*it).second;
            // cout << neighborid;
            if(toneighborfromhere < neighborcost){
                // cout << "(queue add <" << neighborid << ">)";
                costtonodes[neighborid] = toneighborfromhere;
                queue1.push(neighborid);
            }
            i++;
            // cout << ", ";

        }
        // cout << endl;

    }
}

void findwaycost()
{
    costtonodes[startnode] = 0;
    mover(startnode);
    waycost = costtonodes[endnode];
}

int main()
{
    init();
    findwaycost();
    cout << waycost;

    return 0;
}
